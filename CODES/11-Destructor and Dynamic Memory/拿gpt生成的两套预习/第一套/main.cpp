// main.cpp
// Ԥϰ�Բ⣺�۲��ַ�仯����ǳ�������졢��������˳����ʽ��ֵ��

#include <iostream>
#include "garray.h"
using namespace std;

// ��ֵ + ����ֵ���ᴥ���������죨�����ܿ����β�/��ʱ�����������
GArray passByValueAndReturn(GArray x) {
    cout << "[passByValueAndReturn] got copy at " << x.address()
        << " (size=" << x.length() << ")\n";
    x.insert(999);
    return x; // ����ֵ�Ż����ܼ��ٿ��������ֲ� x ������һ���ᷢ��
}

void insertTests() {
    cout << "\n[1] insert tests\n";
    GArray a;
    cout << "a: " << a << "\n";
    a.insert(2);  cout << "a: " << a << "\n";
    a.insert(4);  cout << "a: " << a << "\n";
    a.insert(6);  cout << "a: " << a << "\n";
    a.insert(8);  cout << "a: " << a << "\n";
}

void memoryTests() {
    cout << "\n[2] copy-ctor (deep copy) tests\n";
    GArray a;
    a.insert(1); a.insert(2); a.insert(3);
    cout << "a: " << a << "\n";

    GArray b(a); // �����������죨�����
    cout << "b (after copy): " << b << "\n";
    b.insert(10);
    cout << "a (unchanged) : " << a << "\n";
    cout << "b (+10 only)  : " << b << "\n";

    cout << "\n[3] assignment operator tests\n";
    GArray c;
    c.insert(7); c.insert(7);
    cout << "c(before) : " << c << "\n";
    c = a; // �����ֵ
    cout << "c(after =) : " << c << "\n";
    c = c; // �Ը�ֵ��ӦΪ no-op
    cout << "c(self =)  : " << c << "\n";

    cout << "\n[4] chained assignment tests\n";
    GArray d; d.insert(42);
    cout << "d(before) : " << d << "\n";
    d = c = b; // ��ʽ����ִ�� c=b���� d=c��ÿ�������
    cout << "b         : " << b << "\n";
    cout << "c(after)  : " << c << "\n";
    cout << "d(after)  : " << d << "\n";

    cout << "\n[5] pass-by-value / return tests\n";
    GArray e = passByValueAndReturn(a);
    cout << "e(returned): " << e << "\n";
}

int main() {
    cout << "=== Lesson 10 Prep: Destructor & Rule of Three ===\n";
    insertTests();
    memoryTests();
    cout << "\n=== End of main (watch destructors below) ===\n";
    return 0; // �뿪 main �����ε������ж�����������ͷŸ��Զ��ڴ�
}
