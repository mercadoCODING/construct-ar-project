#ifndef AR_PLANE_H
#define AR_PLANE_H

using namespace cv;
using namespace std;

//hpp file for initializing the plane detection

class Plane {
	bool avail = false;
	float mA = 0, mB = 0, mC = 0, mD = 0; // Plane Formula Ax + By + Cz + D = 0
	const float lineThreshold = 1e - 3;

public:
	Plane();
	void reset();
	bool avail();
	bool computePlane(Point3f, Point3f, Point3f);
	bool fit(vector<Point3f>&, int i = 500, float threshold = 0.01);

	Mat normal();

	float distance(Point3f);
	float countZ(float x, float y);
	float countZ(Point3f);
	float count(Mat);
	float count(Point3f);

	//getter
	float getA() { return mA; }
	float getB() { return mB; }
	float getC() { return mC; }
	float getD() { return mD; }

	void copy(Plane&);


};
#endif // !AR_PLANE_H
