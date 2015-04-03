#ifndef _ODOMETRY_H_
#define _ODOMETRY_H_


#define ODO_MAX_FRAMES (5) // used for static allocation of state and sigma
#define ODO_STATE_SIZE (16)
#define ODO_STATE_FRAME_SIZE (10)
#define ODO_STATE_MAX_SIZE ( ODO_STATE_SIZE + ODO_STATE_FRAME_SIZE * ( ODO_MAX_FRAMES + 1 ) )
#define ODO_SIGMA_SIZE (15)
#define ODO_SIGMA_FRAME_SIZE (9)
#define ODO_SIGMA_MAX_SIZE ( ODO_SIGMA_SIZE + ODO_SIGMA_FRAME_SIZE * ( ODO_MAX_FRAMES + 1 ) )


#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <sys/time.h>
#include <list>
#include "common.hpp"

using namespace Eigen;

class Calib {
public:
	// 
	// Camera calibration
	//
	/* Projection */
	double o_x, o_y,  // principal point [px,px]
			f_x, f_y, // focal length [px,px]
			k1, k2,   // radial distortion parameters [n/u,n/u]
			t1, t2;   // tangential distortion parameters [n/u,n/u]
	/* Position */
	Quaternion<double> CI_q; // Rotation from intertial to camera coordinates. [unit quaternion]
	Vector3d C_p_I;              // Position of inertial frame in camera coordinates [m,m,m]
	//
	// Physical properties
	//
	double g;           // Gravitational acceleration [m/s^2]
	double delta_t;     // Time between IMU data [s]
	struct timeval imageOffset; // Time delay for images [s]
	//
	// Noise levels
	//
	/* IMU TODO: add correct units */
	double sigma_gc, sigma_ac,    // Standard deviation of IMU noise [rad/s, m/s^2]
			sigma_wgc, sigma_wac; // Standard deviation of IMU random walk noise [rad/s, m/s^2]
	/* Camera */
	double sigma_Im; // Image noise
	/* height sensor */
	double sigma_hc; // Standard deviation of height sensor noise [m]
	//
	// Options
	//
	unsigned int maxFrame; // Maximum frames in FIFO
	unsigned int minFrame; // Minimun frames in FIFO (is smaller before the first minFrames). Is used if features are only added when there is a match

	Calib( );
	friend std::ostream& operator<<( std::ostream& out, const Calib& calib );
};

class MSCKF {
public:
	cv::Mat debugImg;
	//
	// Calibration object
	//
	Calib* calib;
	//
	// State
	//
	// Matrix<double,Dynamic,1,0,ODO_STATE_MAX_SIZE,1> x; // allocate statically
	Matrix<double,Dynamic,1> x;
	//
	// Covariance
	//
	// Matrix<double,Dynamic,Dynamic,0,ODO_SIGMA_MAX_SIZE,ODO_SIGMA_MAX_SIZE> sigma; // allocate statically
	Matrix<double,Dynamic,Dynamic> sigma;
	//
	// Local variables for integration
	//
	Vector3d I_a_dly, I_g_dly;

//public:
	// print
	friend std::ostream& operator<<( std::ostream& out, const MSCKF& msckf );
	// init
	MSCKF( Calib* cal );
	// propagate
	void propagate( double a_m[3], double g_m[3] );
	// TODO: -Propagate state <- used for pure prediction
	// TODO: -Propagate sigma <- no use for this
	// augment state
	void augmentState( void );
	// remove n old states
	void removeOldStates( int n );
	// updateCamera
	void updateCamera( CameraMeasurements &cameraMeasurements );
	// 	triangluate
	Vector3d triangluate( MatrixX2d z );
	// -marginalize
	template <typename Derived_r0, typename Derived_H0>
void MSCKF::marginalize( const MatrixX2d &z , const Vector3d &G_p_f, const MatrixBase<Derived_r0>& r0, const MatrixBase<Derived_H0>& H0 );
	// TODO: -isInlinerCamera
	bool isInlinerCamera( const VectorXd &r0, const MatrixXd &H0 );
	// updateHeight
	void updateHeight( double height );
	// TODO: -isInlierHeight
};


#endif //_ODOMETRY_H_