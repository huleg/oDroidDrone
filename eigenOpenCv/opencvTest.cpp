#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "feature.hpp"

/** @function main */
int main( int argc, char** argv )
{
	cv::VideoCapture cap(0);
	cv::Mat image;

	cameraFeatures CameraFeatures( );


	cv::namedWindow( "Matches" );

	while( cv::waitKey(0) != 27 ) {
		cap.grab();
		cap.grab();
		cap.grab();
		cap.grab();
		cap.grab();
		cap.retrieve( image );

		cv::imshow("Matches", image );
	}


	return 0;
}