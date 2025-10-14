// Implementation file for the Duration class. 
// (Definitions for functions only declared in duration.h)
// New concepts include to_string and syntax for operator overloading.
// Sara Krehbiel, 10/1/25-10/3/25

#include "duration.h" // include the interface file

// stub implementation returns value of member variable as string
string Duration::toString() {
	// TODO: use string concatenation to format string like "x hrs, y mins"
	return to_string(mins);//to_string它是 C++ 标准库函数，作用是把数值类型（int, long, double, float 等）转换成 字符串
}