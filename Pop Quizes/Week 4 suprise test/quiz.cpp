/*
Week 4 Quiz
Wednesday, October 15, 2025
CSCI 60 – Krehbiel

Instructions.
On the other side is a partial definition of a class whose objects represent fractions, each of which has an integer numerator and an integer denominator. Add three pieces of code as follows:

Write a 2-argument constructor that initializes the member variables with the provided arguments.

Overload the – operator consistent with fraction subtraction, e.g.,
  a/b – c/d = (ad – cb) / bd
 You must overload subtraction as a non-member function; it may or may not be a friend.

Add two lines to the main driver program so the existing cout statements output the following:
2/3+1/4=11/12
2/3-1/4=5/12
*/
// Week 4 Quiz
// Sara Krehbiel, 10/15/25

#include <iostream>
using namespace std;

class Fraction {
public:
    Fraction() : n(0), d(1) {}

    string toStr() const;
    Fraction operator+(const Fraction& rhs) const;

private:
    int n;
    int d;
};

string Fraction::toStr() const {
    return to_string(n) + "/" + to_string(d);
}

Fraction Fraction::operator+(const Fraction& rhs) const {
    Fraction sum(n * rhs.d + d * rhs.n, d * rhs.d);
    return sum;
}

int main() {
    Fraction f1(2, 3);
    Fraction f2(1, 4);

    // (需要添加两行定义 f3, f4)
    cout << f1.toStr() << "+" << f2.toStr() << "=" << f3.toStr() << endl;
    cout << f1.toStr() << "-" << f2.toStr() << "=" << f4.toStr() << endl;
    return 0;
}
