#include <iostream>

using namespace std;

int main()
{
int arr[] = {11, 13, 15, 17};
int *p=arr, *p3;
cout << p << endl;//output the address of first element of arr
cout << arr << endl;//output the address of first element of arr
cout << arr[3] << endl;//output the 4th element of arr, which is 17
cout << p[3] << endl;//output the 4th element of arr, which is 17

p3 = p + 3;//move from p by 3 integer spots //this is pointer arithmetic, you can change the address stored in p3 by adding 3 to p
cout << p3[0] << endl;//All four of these are accessing the same value in the same spot//output the 4th element of arr, which is 17
cout << *p3 << endl;//output the 4th element of arr, which is 17
cout << *(p + 3) << endl;//output the 4th element of arr, which is 17
cout << p[3] << endl;//output the 4th element of arr, which is 17
cout << endl;
*(p + 3) = 99;//change the 4th element of arr to 99
for (int i = 0; i < 4; i++) {
	cout << p[i] << " = " << *(p + i) << endl;//output all elements of arr//which are now 11, 13, 15, 99
}
cout << endl;
int a = 1, b = 2, c = 3, d = 4, e = 5;
p = &a;//pointer p to address of a
for (int i = 0; i < 4; i++) {
	cout << p[i] << endl;//Undefined Behavior��Խ�磩��p ֻ��֤ p[0]==a������ p[1], p[2], p[3] �޶��壬�������Ԥ��
}
//������1��11��13��15����Ϊ�ڴ沼�ֵ��ɺϣ����߱����ظ���
cout << endl;
p = &e;//pointer p to address of e
for (int i = 0; i < 4; i++) {
	cout << p[i] << endl;//Undefined Behavior���� p[0]==e �ж��壬�������ʲ���Ԥ�⣨�������ֵ/������
}
//������5��0��4��3����Ϊ�ڴ沼�ֵ��ɺϣ����߱����ظ���
cout << endl;
p = &b;//pointer p to address of b
for (int i = 0; i < 10; i++) {
	cout << p[i] << endl;//Undefined Behavior���� p[0]==b �ж��壬���������Ԥ�⣻����ʾ��������߱����ظ���
}
//������2��1��11��13��15��99��-12800��7��4��3����Ϊ�ڴ沼�ֵ��ɺϣ����߱����ظ���
return 0;
}


/*program output :
0x7ffffcc00
0x7ffffcc00
17
17
17
17
17
17

11 = 11
13 = 13
15 = 15
99 = 99

1
11
13
15

5
2
1
11

2
1
11
13
15
99
-12800
7
4
3
*/
