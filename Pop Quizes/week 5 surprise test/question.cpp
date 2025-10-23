//��Ŀ1�� What is the output of the following C++ code snippet?
//��Ŀ2��which line of code first causes a orphaned memory? Circle it out and add a line of code above it to fix the memory leak.
//PS: orphaned����˼�ǹ¶��ڴ棬û��ָ��ָ�������ڴ棬����Ҳ�޷��ͷ������޷����������ᵼ���ڴ�й©���˷�heap memory�ռ䡣
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
