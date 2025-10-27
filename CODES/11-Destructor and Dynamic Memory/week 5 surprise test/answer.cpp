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
	delete p1; //���������������һ��delete����Ϊp1ԭ��ָ��heap�ϵ�42��p2����ָ��90��42��û��ָ��ָ�����ˣ���ɹ¶��ڴ��ˣ���������Ҫ��delete��42����ֹ�ڴ�й©
	p1 = p2;//orphans the 42 on the heap if we don't delete it first//Ȧ����һ��
    cout << n << " " << *p1 << " " << *p2 << endl;
    return 0;
}
/*
memory diagram:�𲽷�������ִ�й����е��ڴ�״̬�仯
stack:                        heap:
n:53                          p2:42
p1:->&n
p2:--------------------------->heap:42
��������������������������������After *p1=88:����������������������������������������
stack:                        heap:
n:88                          p2:42
p1:->&n
p2:--------------------------->heap:42
��������������������������������After p1=p2:����������������������������������������
stack:                        heap:
n:88                          p2:42
p1:--------------------------->heap:42
p2:--------------------------->heap:42
��������������������������������After p2=new int(90):����������������������������������������
stack:                        heap:
n:88                          p2:90
p1:--------------------------->heap:42
p2:--------------------------->heap:90
��������������������������������After p1=p2:����������������������������������������
stack:                        heap:
n:88                          p2:90
p1:--------------------------->heap:90
p2:--------------------------->heap:90
*/
/*
�������ǣ�
88 88 42
88 90 90
*/
