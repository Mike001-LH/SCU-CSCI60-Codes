
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>


class biguint
{
public: 

	static const int CAPACITY = 20;// max number of digits

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint();

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(string s);

    // CONSTANT MEMBER FUNCTIONS

    // pre: none
    // post: returns the digit at position pos
    //          0 is the least significant (units) position

    unsigned short operator [](int pos);

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(biguint b) ;



    // MODIFICATION MEMBER FUNCTIONS


    // pre: none
    // post: b is added to this biguint; ignore last carry if any
    void operator += (biguint b);
    // pre: this is > b, since unsigned
    // post: b is subtracted to this biguint; ignore last borrow if any
    void operator -= (biguint b);

private:

	unsigned short data_[CAPACITY];//unsigned short is a type that can hold small non-negative integers //unsigned的意思是非负的

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

// nonmember functions

biguint operator + ( biguint b1,  biguint b2);
biguint operator - ( biguint b1,  biguint b2);

bool operator < ( biguint b1,  biguint b2);
bool operator <= ( biguint b1,  biguint b2);
bool operator != ( biguint b1,  biguint b2);
bool operator == ( biguint b1,  biguint b2);
bool operator >= ( biguint b1,  biguint b2);
bool operator > ( biguint b1,  biguint b2);
std::ostream& operator <<(std::ostream& out,  biguint b);

