// Week 4 Quiz (clean solution)
// Sara Krehbiel, 10/15/25
#include <iostream>
#include <string>
using namespace std;

class Fraction {
public:
    // 0参与2参构造（用初始化列表）
    Fraction() : n(0), d(1) {}
	Fraction(int n, int d) : n(n), d(d) {}   // 首先实现小测第一步：写一个2参构造器初始化两个数//2-arg constructor要在括号里写参数

    // 基本接口
    string toStr() const { return to_string(n) + "/" + to_string(d); }
    int getN() const { return n; }
    int getD() const { return d; }

    // 成员加法： (a/b) + (c/d) = (ad+bc)/(bd)
    Fraction operator+(const Fraction& rhs) const {
        return Fraction(n * rhs.d + d * rhs.n, d * rhs.d);
    }

private:
    int n;
    int d;
};

//如果不想用friend，可以用getters，由于非成员函数不能访问私有成员，所以只能用自己定义的getters方法
// 非成员减法（课堂最后版本用 getters，而不是 friend）
Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.getN() * rhs.getD() - lhs.getD() * rhs.getN(),
        lhs.getD() * rhs.getD());
}

// （可选）流输出；课堂里最终是用 toStr() 打印，这里顺手补上
ostream& operator<<(ostream& o, const Fraction& f) {
    return o << f.toStr();
}

// driver program 与课堂一致
int main() {
    Fraction f1(2, 3);
    Fraction f2(1, 4);
    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;

	cout << f1.toStr() << "+" << f2.toStr() << "=" << f3.toStr() << endl;//由于这里出现了f3，说明我们要定义f3为f1+f2
	cout << f1.toStr() << "-" << f2.toStr() << "=" << f4.toStr() << endl;//由于这里出现了f4，说明我们要定义f4为f1-f2
    return 0;
}
