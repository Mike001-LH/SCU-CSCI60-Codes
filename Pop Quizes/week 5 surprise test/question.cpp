//题目1： What is the output of the following C++ code snippet?
//题目2：which line of code first causes a orphaned memory? Circle it out and add a line of code above it to fix the memory leak.
//PS: orphaned的意思是孤儿内存，没有指针指向它的内存，我们也无法释放它，无法访问他。会导致内存泄漏，浪费heap memory空间。
#include <iostream>
using namespace std;

int main() {
    int n = 53;
    int* p1, * p2;
    p1 = &n;
    p2 = new int(42);
    *p1 = 88;
    cout << n << " " << *p1 << " " << *p2 << endl;
    p1 = p2;
    p2 = new int(90);
    p1 = p2;                                       
    cout << n << " " << *p1 << " " << *p2 << endl; 
    return 0;
}
