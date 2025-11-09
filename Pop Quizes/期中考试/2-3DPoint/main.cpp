#include "point3d.h"

int main() {
	//3, Declare Point3D p1 as (1, 2, 3) and Point3D p2 as (-1, 2, 4).
	Point3D p1(1, 2, 3);
	Point3D p2(-1, 2, 4);
	//4, Declare a variable initialized to the dot product of p1 and p2 using your overloaded *,
	double dotProduct = p1 * p2;
	//    and another variable initialized to the sum using your overloaded +.
	Point3D sum = p1 + p2;
	//for testing
	cout << "Dot Product: " << dotProduct << endl; // Expected output: 16
	cout << "Vector Sum: (" << sum.getX() << ", " << sum.getY() << ", " << sum.getZ() << ")" << endl; // Expected output: (0, 4, 7)
	return 0;
}