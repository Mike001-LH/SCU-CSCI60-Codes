// main.cpp
// 预习自测：观察地址变化、深浅拷贝差异、析构调用顺序、链式赋值等

#include <iostream>
#include "garray.h"
using namespace std;

// 传值 + 返回值：会触发拷贝构造（至少能看到形参/临时对象的析构）
GArray passByValueAndReturn(GArray x) {
    cout << "[passByValueAndReturn] got copy at " << x.address()
        << " (size=" << x.length() << ")\n";
    x.insert(999);
    return x; // 返回值优化可能减少拷贝，但局部 x 的析构一定会发生
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

    GArray b(a); // 触发拷贝构造（深拷贝）
    cout << "b (after copy): " << b << "\n";
    b.insert(10);
    cout << "a (unchanged) : " << a << "\n";
    cout << "b (+10 only)  : " << b << "\n";

    cout << "\n[3] assignment operator tests\n";
    GArray c;
    c.insert(7); c.insert(7);
    cout << "c(before) : " << c << "\n";
    c = a; // 深拷贝赋值
    cout << "c(after =) : " << c << "\n";
    c = c; // 自赋值：应为 no-op
    cout << "c(self =)  : " << c << "\n";

    cout << "\n[4] chained assignment tests\n";
    GArray d; d.insert(42);
    cout << "d(before) : " << d << "\n";
    d = c = b; // 链式：先执行 c=b，再 d=c（每步深拷贝）
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
    return 0; // 离开 main 后，依次调用所有对象的析构，释放各自堆内存
}
