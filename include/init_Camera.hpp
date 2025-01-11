#ifndef  AR_INITCAMERA_H
#define  AR_INITCAMERA_H

#include "init.hpp"
#include "ORB-SLAM/include/System.h"
#include "plane.hpp"
#include <chrono>
	
//hpp file for initializing camera and slam

using namespace cv;
using namespace std;

class Camera {

	//For debugging
	bool matDeb = false;
	chrono::steady_clock::time_point mTimeStamps;

	//Matriix Variables
	Size2d matImageSize;
	Mat matImageMask;
	Mat matIndicatorImage;


	//Pointer Instance of the ORB-SLAM SYSTEM
	//To be used dynamically in the main.cpp
	ORB_SLAM2::System* mpSlam;

	// Orb Points Storage
	vector<ORB_SLAM2::MapPoint*> mvMapPoints;
	vector<KeyPoint> mKeypoints;
	vector<Point3f> pPoints;

	//Transformation Matrix Camera to world and World to Camera
	Mat mCtoW, mWtoC;

	// 2 Point corner of the indicator X , Y
	vector<Point2f> matIndicatorCorner;

	//Intrinsic Camera Matrix
	Mat matKMat;

	//Plane Detection
	float planeThreshold = 80;
	Plane mPlane;
	
	//Helper func
	Point2f worldToImage(Point3f);
	Point3f cameraToWorld(Point3f);
	Point3f worldToCamera(Point3f);

public:
	Camera();
	void setDebug(bool);
	void releaseSlam(); //release slam resources
	void init(string path);
	int process(Mat& image, Mat& output);	
	bool detectPlane(int iterations = 500, float threshold = 0.01); // plane detection
	void showIndicator(Mat $dest);
	Plane getPlane();

	Mat getCtoW(); //Getter Camera to World
	Mat getWtoC(); // Getter World to Camera
	Point3f getCameraCenter(Plane);
};


#endif // ! AR_INITGLM_H
