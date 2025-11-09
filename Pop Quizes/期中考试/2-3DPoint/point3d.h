/*
2  3D Point (15 points)

The following skeletal class represents a point in 3-dimensional space.
Declare two operators below (in point3d.h) and define them on the following page (in point3d.cpp) as follows:

1) Overload * as a member function to compute the dot product of two 3D points.
   The dot product of (a1, a2, a3) and (b1, b2, b3) is a1*b1 + a2*b2 + a3*b3.

2) Overload + as a non-member function to compute the vector sum.
   The sum of (a1, a2, a3) and (b1, b2, b3) is (a1 + b1, a2 + b2, a3 + b3).

Then write a simple program (in main.cpp):

3) Declare Point3D p1 as (1, 2, 3) and Point3D p2 as (-1, 2, 4).
4) Declare a variable initialized to the dot product of p1 and p2 using your overloaded *,
   and another variable initialized to the sum using your overloaded +.

*/
#ifndef POINT3D_H
#define POINT3D_H

class Point3D {
public:
    Point3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}
    Point3D() : x_(0), y_(0), z_(0) {}
	//1, Overload * as a member function to compute the dot product of two 3D points.
    double operator* (const Point3D& other) const {}
	double getX() const { return x_; }
	double getY() const { return y_; }
	double getZ() const { return z_; }
private:
    double x_;
    double y_;
    double z_;
};

//2, Overload + as a non-member function to compute the vector sum.
Point3D operator+ (const Point3D& p1, const Point3D& p2) {}

#endif // POINT3D_H
