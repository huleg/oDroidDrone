#include "videoIO.hpp"

int main( int argc, char** argv )
{
	VideoIn videoIn( 0 );
	cv::Mat frame;

	cv::namedWindow( "Features", 1 );

	while(1)
	{
		cv::imshow("Features", frame);

		char c = (char)cv::waitKey(1);
		if( c == 27 )
			break;
	}
}