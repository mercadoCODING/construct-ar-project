#include "init_Camera.hpp"

using namespace std;
using namespace cv;

Camera::Camera() {
	mpSlam = nullptr;
	mTimeStamps = std::chrono::steady_clock::now();
}

void Camera::releaseSlam() {
	mpSlam->Shutdown();
}

void Camera::setDebug(bool debug) {
	matDeb = debug;
}

void Camera::init(string path) {
	//TOOD implement initialization of camera and slam system and orb vocabulary
	string settings_path = path + "/Calibrations.yaml";
}

int Camera::process(Mat& img, Mat& output) {

}

Mat Camera::getCtoW() {
	return mCtoW.clone();
}


Mat Camera::getWtoC() {
	return mWtoC.clone();
}

Plane Camera::getPlane() {
	return mPlane;
}

Point3f Camera::cameraToWorld(Point3f p) {
	Mat mat = (Mat_<float>(4, 1) << p.x, p.y, p.z, 1.0); // Coordinate Matrix [x;y;z;1]
	Mat c2w = mCtoW * P; // c2w = [x;y;z;1] translation
	return Point3f(c2w.at<float>(0), c2w.at<float>(1), c2w.at<float>(2)); //access index in the matrix [x;y;z]
}


Point3f Camera::worldToImage(Point3f p) {
	Mat mat = (Mat_<float>(4, 1) << p.x, p.y, p.z, 1.0);
	Mat w2c = mWtoC * P;
	return Point3f(w2c.at<float>(0), w2c.at<float>(1), w2c.at<float>(2));
}