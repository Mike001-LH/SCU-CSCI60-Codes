// Header file containing the interface for the Duration class. 
// A duration object hold an amount of time, displayed in hours and minutes.
// Duration objects can be added together, which we'll do in several ways.
// New concepts include operator overloading, friend functions, and a brief
// discussion of const, which we'll discuss further on Monday.
// Note that sumDuration can be unambiguously overloaded simultaneously as 
// a member AND non-member, but + cannot because of how they are called.
// Sara Krehbiel, 10/1/25-10/3/25

#ifndef DURATION_H // boilerplate for header files (no need to memorize)
#define DURATION_H

#include <iostream>
using namespace std;

// class definition: declares all member fields, may have inline functions defs
class Duration {
public:
	// CONSTRUCTORS (defined inline with initialization sections)

	Duration() : mins(0) { } 
	Duration(int mins) : mins(mins) { }
	Duration(int hrs, int mins) : mins(hrs*60+mins) { }

	// MEMBER FUNCTION DECLARATIONS

	// formats Duration data as a nice string
	string toString() const; // 0 const prohibits changing calling object

	// 1 sumDuration declared as a member function
	Duration sumDuration(Duration rhs); // don't declare calling object/lhs!

	// 4 + declared as a member function
	Duration operator +(Duration rhs); 

	// 7 inline += overload, which uses built-in += to modify calling object
	void operator +=(Duration rhs) { mins += rhs.mins; }

	// an inline accessor that's only needed for non-member non-friends
	int getMins() { return mins; } 

	// FRIEND FUNCTION DECLARATIONS

	friend Duration sumDuration(Duration lhs, Duration rhs); // 3
	//friend Duration operator +(Duration lhs, Duration rhs); // 6
private:
	int mins;
};

// DECLARATIONS OF NON-MEMBER NON-FRIEND FUNCTIONS RELATED TO THIS CLASS

//Duration sumDuration(Duration lhs, Duration rhs); // 2
//Duration operator +(Duration lhs, Duration rhs); // 5

#endif
