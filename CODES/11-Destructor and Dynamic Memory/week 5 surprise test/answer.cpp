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
	delete p1; //所以我们在这里加一行delete，因为p1原本指向heap上的42，p2重新指向90后，42就没有指针指向它了，变成孤儿内存了，所以我们要先delete掉42，防止内存泄漏
	p1 = p2;//orphans the 42 on the heap if we don't delete it first//圈出这一行
    cout << n << " " << *p1 << " " << *p2 << endl;
    return 0;
}
/*
memory diagram:逐步分析代码执行过程中的内存状态变化
stack:                        heap:
n:53                          p2:42
p1:->&n
p2:--------------------------->heap:42
————————————————After *p1=88:————————————————————
stack:                        heap:
n:88                          p2:42
p1:->&n
p2:--------------------------->heap:42
————————————————After p1=p2:————————————————————
stack:                        heap:
n:88                          p2:42
p1:--------------------------->heap:42
p2:--------------------------->heap:42
————————————————After p2=new int(90):————————————————————
stack:                        heap:
n:88                          p2:90
p1:--------------------------->heap:42
p2:--------------------------->heap:90
————————————————After p1=p2:————————————————————
stack:                        heap:
n:88                          p2:90
p1:--------------------------->heap:90
p2:--------------------------->heap:90
*/
/*
输出结果是：
88 88 42
88 90 90
*/
