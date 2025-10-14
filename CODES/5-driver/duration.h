// Header file containing the interface for the Duration class. 
// A duration object hold an amount of time, displayed in hours and minutes.
// Duration objects can be added together, which we'll do in several ways.
// New concepts include const refs, friend functions, and operator overloading.
// Sara Krehbiel, 10/1/25-10/3/25

#ifndef DURATION_H // boilerplate for header files (no need to memorize)
#define DURATION_H

#include <iostream>
using namespace std;

// class definition: declares all member fields, may have inline functions defs
class Duration {
public:
	// constructors (defined inline with initialization sections)
	Duration() : mins(0) { } 
	Duration(int mins) : mins(mins) { }//从左到右3个mins分别是driver.cpp里面的100，duration.h这里的private mins，以及driver.cpp里面的100
	Duration(int hrs, int mins) : mins(hrs*60+mins) { }

	// member function declarations
	string toString();

	// friend function declarations

private:
	int mins;
};

// declarations of non-member non-friend functions related to class

#endif
