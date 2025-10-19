// Week 4 Quiz (clean solution)
// Sara Krehbiel, 10/15/25
#include <iostream>
#include <string>
using namespace std;

class Fraction {
public:
    // 0����2�ι��죨�ó�ʼ���б�
    Fraction() : n(0), d(1) {}
	Fraction(int n, int d) : n(n), d(d) {}   // ����ʵ��С���һ����дһ��2�ι�������ʼ��������//2-arg constructorҪ��������д����

    // �����ӿ�
    string toStr() const { return to_string(n) + "/" + to_string(d); }
    int getN() const { return n; }
    int getD() const { return d; }

    // ��Ա�ӷ��� (a/b) + (c/d) = (ad+bc)/(bd)
    Fraction operator+(const Fraction& rhs) const {
        return Fraction(n * rhs.d + d * rhs.n, d * rhs.d);
    }

private:
    int n;
    int d;
};

//���������friend��������getters�����ڷǳ�Ա�������ܷ���˽�г�Ա������ֻ�����Լ������getters����
// �ǳ�Ա�������������汾�� getters�������� friend��
Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.getN() * rhs.getD() - lhs.getD() * rhs.getN(),
        lhs.getD() * rhs.getD());
}

// ����ѡ����������������������� toStr() ��ӡ������˳�ֲ���
ostream& operator<<(ostream& o, const Fraction& f) {
    return o << f.toStr();
}

// driver program �����һ��
int main() {
    Fraction f1(2, 3);
    Fraction f2(1, 4);
    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;

	cout << f1.toStr() << "+" << f2.toStr() << "=" << f3.toStr() << endl;//�������������f3��˵������Ҫ����f3Ϊf1+f2
	cout << f1.toStr() << "-" << f2.toStr() << "=" << f4.toStr() << endl;//�������������f4��˵������Ҫ����f4Ϊf1-f2
    return 0;
}
