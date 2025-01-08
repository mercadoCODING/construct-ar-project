#ifndef  AR_INITGLM_H
#define  AR_INITGLM_H

#include "init.hpp"
#include "ORB-SLAM/include/System.h"
#include "plane.hpp"
#include <chrono>
	
using namespace cv;

class Camera {

	//For debugging
	bool matDeb = false;

	Size2d matImageSize;
	Mat matImageMask;
	Mat matIndicatorImage;

	// 2 Point corner of the indicator X , Y
	std::vector<Point2f> matIndicatorCorner;

	//Camera Matrix
	Mat matKMat;

	chrono::steady_clock::time_point mTimeStamps;
	



};


#endif // ! AR_INITGLM_H
