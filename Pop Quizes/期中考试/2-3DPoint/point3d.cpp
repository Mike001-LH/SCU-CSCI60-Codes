#include "point3d.h"

// Overload * as a member function to compute the dot product of two 3D points.
double Point3D::operator* (const Point3D& other) const {
	return x_ * other.x_ + y_ * other.y_ + z_ * other.z_;
}

// Overload + as a non-member function to compute the vector sum.
Point3D operator+ (const Point3D& p1, const Point3D& p2) {
	double newX = p1.getX() + p2.getX();
	double newY = p1.getY() + p2.getY();
	double newZ = p1.getZ() + p2.getZ();
	Point3D result(newX, newY, newZ);
	return result;
}
