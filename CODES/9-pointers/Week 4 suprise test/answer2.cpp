// Week 4 Quiz
// Sara Krehbiel, 10/15/25

#include <iostream>
using namespace std;

// class definition
class Fraction {
public:
    Fraction() : n(0), d(1) {}
    Fraction(int n, int d) : n(n), d(d) {}//first step, make a 2-arg constructer that initialize two variables

    string toStr() const;
	Fraction operator+(const Fraction& rhs) const;//����ֻ��rhs����Ϊ����һ��member function,����ֻ��һ������
	friend Fraction operator -(const Fraction& lhs, const Fraction& rhs);//second step, make a non-member subtraction function(declared as friend)//����֮������lhs��rhs����Ϊ����һ��non-member function,��������������

private:
    int n;
    int d;
};

string Fraction::toStr() const {
    return to_string(n) + "/" + to_string(d);
}

Fraction Fraction::operator+(const Fraction& rhs) const {
    return Fraction(n * rhs.d + d * rhs.n, d * rhs.d);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {//third step, implement the non-member subtraction function//�����������������Ѿ���������friend�ˣ��������ﲻ��Ҫ�ټ�friend
	return Fraction(lhs.n * rhs.d - lhs.d * rhs.n, lhs.d * rhs.d);
}

ostream& operator<<(ostream& o, Fraction f) {
    return o << f.toStr();
}

// driver program
int main() {
    Fraction f1(2, 3);
    Fraction f2(1, 4);

    cout << f1.toStr() << " + " << f2.toStr() << " = " << f3.toStr() << endl;
    cout << f1.toStr() << " - " << f2.toStr() << " = " << f4.toStr() << endl;

    return 0;
}
