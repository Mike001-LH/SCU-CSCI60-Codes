// Implementation file for the Duration class. 
// (Definitions for functions only declared in duration.h)
// New concepts include to_string and syntax for operator overloading.
// Sara Krehbiel, 10/1/25-10/3/25

#include "duration.h" // include the interface file

// use to_string and concatenation to format like "x hrs, y mins"
string Duration::toString() const {
	//mins=1000; // 0 illegal if toString is a const member function
	return to_string(mins/60) + " hrs, " + to_string(mins%60) + " mins"; 
}

// 1 definition for sumDuration as a member function
Duration Duration::sumDuration(Duration rhs) { // NOTE: need scope resolution
	//int total = mins + rhs.mins; // NOTE: mins is of the calling object/lhs
	//Duration thirdObj(total);
	//return thirdObj;
	return Duration(mins + rhs.mins); 
}

// 2 definition for sumDuration as non-member non-friend function
/*Duration sumDuration(Duration lhs, Duration rhs) { // NOTE: no scope resolution
	return Duration(lhs.getMins()+rhs.getMins()); // need getMins for this!
}*/

// 3 definition for sumDuration as (non-member) friend function
Duration sumDuration(Duration lhs, Duration rhs) {
	return Duration(lhs.mins + rhs.mins); // friends get private access
}

// 4 definition for + as a member function
Duration Duration::operator +(Duration rhs) { 
	return Duration(mins + rhs.mins);
}

// 5 definition for + as non-member non-friend
/*Duration operator +(Duration lhs, Duration rhs) {
	return Duration(lhs.getMins() + rhs.getMins());
}*/

// 6 definition for + as friend
/*Duration operator +(Duration lhs, Duration rhs) {
	return Duration(lhs.mins + rhs.mins);
}*/