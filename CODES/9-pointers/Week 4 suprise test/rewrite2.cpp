#include <iostream>
using namespace std;

class Fraction {
public:
    Fraction() : n(0), d(1) {}
    //write a 2-argument constructor that initializes the member variables with the provided arguments
    Fraction(int n, int d) : n(n), d(d) {} //here, we initialize n with n and d with d

    string toStr() const;
    Fraction operator+(const Fraction& rhs) const;
	friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);//哪怕是friend，也要先在类里声明，再在类外实现

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

//Overload the - operator consistent with fraction subtraction, e.g., a/b - c/d = (ad - cb) / bd 
//You must overload subtraction as a non-member function; it may or may not be a friend.
//由于是non-member function，所以左值和右值都要作为参数传入//左值是第一个分数（有名字、能找到内存地址的对象），右值是第二个分数（没有名字的临时值（表达式结果））
//我们这次写用friend的版本
Fraction operator-(const Fraction& lhs, const Fraction& rhs) {//这里之所以不用const Fraction& lhs = f1, const Fraction& rhs = f2，是因为这是non-member function，不能直接访问私有成员，所以只能用getters方法
    Fraction sum(lhs.n * rhs.d - lhs.d * rhs.n, lhs.d * rhs.d);
    return sum;
}
int main() {
    Fraction f1(2, 3);
    Fraction f2(1, 4);
    // (需要添加两行定义 f3, f4)
    Fraction f3 = f1 + f2;//之所以等于f1+f2，是因为我们在类里定义了operator+，会把f1(2, 3)作为左值，f2(1, 4)作为右值传入，最后返回f3(11, 12), 计算过程是(2*4+3*1)/(3*4) = 11/12
    Fraction f4 = f1 - f2;//之所以等于f1-f2，是因为我们在类外定义了operator-，会把f1(2, 3)作为左值，f2(1, 4)作为右值传入，最后返回f4(5, 12), 计算过程是(2*4-3*1)/(3*4) = 5/12
    cout << f1.toStr() << "+" << f2.toStr() << "=" << f3.toStr() << endl;//利用toStr()方法把分数转换成字符串输出，输出结果是2/3+1/4=11/12
    cout << f1.toStr() << "-" << f2.toStr() << "=" << f4.toStr() << endl;//利用toStr()方法把分数转换成字符串输出，输出结果是2/3-1/4=5/12
    return 0;
}
