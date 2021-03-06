/*
 * mfc codec encoding example application
 * Andrzej Hajda <a.hajda@samsung.com>
 *
 * Sample input device.
 *
 * Copyright 2012 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <arm_neon.h>

#include "common.h"
#include "in_demo.h"
#include "func_dev.h"

#define SQUARE_SIZE 5
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

struct in_demo_priv {
	int width;
	int height;
	char **NV12_ARRAY;
};

static int in_demo_read(struct io_dev *dev, int nbufs, char **bufs, int *lens)
{
	dbg( "Processing input image\n" );
	dbg( "consuming trigger\n" );
	char c[8];
	char a = read( dev->fd, c, 8);
	dbg( "consumed trigger\n" );


	struct in_demo_priv *p;
	int size;

	p = dev->priv;

	if (nbufs != 2)
		return -1;

	size = p->width * p->height;
	if (size > lens[0] || size > 2 * lens[1]) {
		err("Size=%d len=%d,%d", size, lens[0], lens[1]);
		return -1;
	}

	// Copy is done while going from BGR to NV12
	//memset( bufs[0], 0, size );
	//memset( bufs[1], 128, size / 2 );
	//memcpy(bufs[0], p->NV12_ARRAY[0], size);
	//memcpy(bufs[1], p->NV12_ARRAY[1], size / 2);

	// copy blue
	uint8_t* bgrArray = p->NV12_ARRAY[2];
	uint8_t* lumaArray = bufs[0];
	uint8_t* chromaArray = bufs[1];

	int i;
	for( i = 0; i < size/16; i++ ) {
		uint8x8x3_t bgr[2] = { vld3_u8( bgrArray ), //load 16 pixels at 8-bits into 3 channels
			vld3_u8( bgrArray + 3*8 ) }; //load 16 pixels at 8-bits into 3 channels
		uint8x8_t c128 = vdup_n_u8( 128 );
		uint8x8_t c0 = vdup_n_u8( 0 );

		int16x8_t r16[2];
		int16x8_t g16[2];
		int16x8_t b16[2];
		uint8x8_t y8[2];

		int j;
		for ( j = 0; j < 2; j++ ) {
			// Covert to 16 bit
			r16[j] = (int16x8_t) vaddl_u8( bgr[j].val[2], c0 );
			g16[j] = (int16x8_t) vaddl_u8( bgr[j].val[1], c0 );
			b16[j] = (int16x8_t) vaddl_u8( bgr[j].val[0], c0 );
			// Calculate Y
			// Matrix product
			int16x8_t y16 = vmulq_n_s16( r16[j], 76 );
			y16 = vmlaq_n_s16( y16, g16[j], 150 );
			y16 = vmlaq_n_s16( y16, b16[j], 29 );
			// rounding shift and narrow
			y8[j] = (uint8x8_t) vrshrn_n_s16( y16, 8 );
		}
		// store luma
		vst1_u8( lumaArray, y8[0] );
		vst1_u8( lumaArray + 8, y8[1] );

		// Check if we should encode chroma
		if( (i/(p->width/16))%2 ) {
			// get each Other
			int16x8x2_t r = vuzpq_s16( r16[0], r16[1] ); // get each other R
			int16x8x2_t g = vuzpq_s16( g16[0], g16[1] ); // get each other R
			int16x8x2_t b = vuzpq_s16( b16[0], b16[1] ); // get each other R

			// U
			int16x8_t u16 = vmulq_n_s16( r.val[0], -43 );
			u16 = vmlaq_n_s16( u16, g.val[0], -84 );
			u16 = vmlaq_n_s16( u16, b.val[0], 127 );
			// rounding shift and narrow
			uint8x8_t u8 = (uint8x8_t) vrshrn_n_s16( u16, 8 );
			// shift arround 0
			u8 = vadd_u8( u8, c128 );

			// V
			int16x8_t v16 = vmulq_n_s16( r.val[0], 127 );
			v16 = vmlaq_n_s16( v16, g.val[0], -106 );
			v16 = vmlaq_n_s16( v16, b.val[0], -21 );
			// rounding shift and narrow
			uint8x8_t v8 = (uint8x8_t) vrshrn_n_s16( v16, 8 );
			// shift arround 0
			v8 = vadd_u8( v8, c128 );

			//interleave and store
			uint8x8x2_t c = { .val[0] = u8,
												.val[1] = v8 };
			vst2_u8( chromaArray, c );

			// move array pointer
			chromaArray += 16;
		}
		// Advance array pointers
		bgrArray += 16*3;
		lumaArray += 16;
	}


	return size;
}

static int in_demo_destroy(struct io_dev *dev)
{
	free(dev->priv);

	return func_destroy(dev);
}

static struct io_dev_ops in_demo_ops = { .read = in_demo_read,
					 .req_bufs = func_req_bufs,
					 .enq_buf = func_enq_buf,
					 .deq_buf = func_deq_buf,
					 .destroy = in_demo_destroy
					};

struct io_dev *in_demo_create(int width, int height, int encoderFd, char **NV12_ARRAY)
{
	struct io_dev *dev;
	struct in_demo_priv *priv;

	dev = malloc(sizeof(*dev));
	memzero(*dev);

	priv = malloc(sizeof(struct in_demo_priv));
	priv->width = width;
	priv->height = height;
	priv->NV12_ARRAY = NV12_ARRAY;

	dev->fd = encoderFd;
	dev->io[DIR_IN].type = IO_NONE;
	dev->io[DIR_OUT].type = IO_FUNC;
	dev->ops = &in_demo_ops;

	dev->priv = priv;

	return dev;
}
