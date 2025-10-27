// Test file illustrating memory management for classes, specifically GArray.
// We'll implement insert to handle dynamic memory for a single object, and 
// by the end of the week, we'll have understood the need for and implemented
// an overloaded assignment operator, a copy constructor, and a destructor.
//
// TODO: 
//   Overview interface in garray.h and insertTests in main
//   Implement insert using dynamic memory
//   Implement DESTRUCTOR with cout statements to see when it's called
//   Overload ASSIGNMENT operator to deep copy rhs
//   Implement a COPY CONSTRUCTOR to deep copy existing object into new one
//   Add cout statements for assignment, copy constructor, and destructor
//    and run passByValueAndReturnObject to see when they are called
//   
// Sara Krehbiel, 10/22/25-10/24/25
// ------------------------------------------------------------
//���룺
// �����ļ�˵������ڴ�����ر���GArray��
// ���ǽ�ʵ��insert������������Ķ�̬�ڴ棬
// ������ĩ�����ǽ���Ⲣʵ�����صĸ�ֵ�������
// ���ƹ��캯�������������ı�Ҫ�ԡ�
// TODO��
// ��garray.h��main�е�insertTests�и����ӿ�
// ʹ�ö�̬�ڴ�ʵ��insert
// ʵ�ִ���cout���������������Բ鿴��ʱ������
// ���ظ�ֵ���������ȸ���rhs
// ʵ��һ�����ƹ��캯���������ж�����ȸ��Ƶ��¶�����
// Ϊ��ֵ�����ƹ��캯���������������cout���
// ������passByValueAndReturnObject�Բ鿴���Ǻ�ʱ������
// ���������ױȶ���2025��10��22����24��
#include <iostream>
#include "garray.h"

using namespace std;

void insertTests();//����һ��������������ʾinsertTests�������ں��涨��
void memoryTests();//����һ��������������ʾmemoryTests�������ں��涨��
GArray passByValueAndReturnObject(GArray arr);//����һ��������������ʾpassByValueAndReturnObject�������ں��涨��//PS��GArray��һ���࣬��ʾ��̬�������飨��h�ļ���

int main() {
  cout << "main is beginning\n\n";//���һ����Ϣ����ʾmain������ʼִ��
  insertTests();//����insertTests���������Բ��빦��
	//memoryTests();
  cout << "\nmain is returning\n";//���һ����Ϣ����ʾmain������������
	return 0;
}

void insertTests() {
  cout << "insertTests is beginning\n\n";//���һ����Ϣ����ʾinsertTests������ʼִ��

  GArray arr;//����һ��GArray����arr����ʼΪ��//������Ϊ���ǵ�����Ĭ�Ϲ��캯��
  cout << "arr: " << arr << endl;//���arr�����ݣ���ʼΪ��
  arr.insert(2);//����insert��������arr�в�������2
  cout << "arr: " << arr << endl;//���arr�����ݣ�Ӧ�ð���2
  arr.insert(4);//����insert��������arr�в�������4
  cout << "arr: " << arr << endl;//���arr�����ݣ�Ӧ�ð���2��4
  arr.insert(6);//����insert��������arr�в�������6
  cout << "arr: " << arr << endl;//���arr�����ݣ�Ӧ�ð���2��4��6
  arr.insert(8);//����insert��������arr�в�������8
  cout << "arr: " << arr << endl;//���arr�����ݣ�Ӧ�ð���2��4��6��8

  // TODO: destructor should free memory
  cout << "\ninsertTests is returning\n";//���һ����Ϣ����ʾinsertTests������������
}

void memoryTests() {
  cout << "memoryTests is beginning\n\n";//���һ����Ϣ����ʾmemoryTests������ʼִ��
  // set up two GArray objects and cout their contents
  GArray first;//����һ��GArray����first����ʼΪ��//������Ϊ���ǵ�����Ĭ�Ϲ��캯��
  first.insert(1);//����insert��������first�в�������1
  first.insert(2);//����insert��������first�в�������2
  GArray second;//����һ��GArray����second����ʼΪ��//������Ϊ���ǵ�����Ĭ�Ϲ��캯��
  second.insert(3);//����insert��������second�в�������3
  second.insert(4);//����insert��������second�в�������4
  second.insert(5);//����insert��������second�в�������5
  cout << "First: " << first << endl;//���first�����ݣ�Ӧ�ð���1��2
  cout << "Second: " << second << endl;//���second�����ݣ�Ӧ�ð���3��4��5

  // TODO: assignment should enforces give identical objects separate memory
  cout << "\nsecond = first;\n";//���һ����Ϣ����ʾ��first��ֵ��second
  second = first; // without overloading =, this makes a shallow copy //û������=��������⽫����ǳ��������˼��second��first������ͬһ���ڴ�
  cout << "\nFirst: " << first << endl;//���first������//Ӧ�ð���1��2
  cout << "Second: " << second << endl;//���second������//Ӧ��Ҳ����1��2����Ϊ����first��ǳ����

  // TODO: copy-constructor should deep copying an existing object's contents
  cout << "\nGArray third(first);\n";//���һ����Ϣ����ʾʹ��first��ʼ��third
  GArray third(first); // calls copy-constructor //���ø��ƹ��캯��������third��Ϊfirst�����//��˼��third�����Լ��������ڴ�//����copy-constructor���ǻ�ûд���������ʵ�����ǣ����ø��ƹ��캯����Ŀǰ��δʵ�֣��������ǳ������
  cout << "\nFirst: " << first << endl;//���first�����ݣ�Ӧ�ð���1��2
  cout << "Second: " << second << endl;//���second�����ݣ�Ӧ��Ҳ����1��2
  cout << "Third: " << third << endl;//���third�����ݣ�Ӧ��Ҳ����1��2����Ϊ����first�����

  //֪ʶ��عˣ�
  //ǳ������shallow copy���������ǽ�һ������ֵ����һ������ʱ�����ֻ�Ǽ򵥵ظ��ƶ����ָ������ã���������ʵ�ʵ��������ݣ��ͻᷢ��ǳ�������������������󽫹���ͬһ���ڴ������޸�����һ����������ݻ�Ӱ����һ������
  //�����deep copy���������ǽ�һ������ֵ����һ������ʱ������������ƶ����ָ������ã�������ʵ�ʵ��������ݣ��ͻᷢ���������������������ӵ�и��Զ������ڴ������޸�����һ����������ݲ���Ӱ����һ������

  // modifying one object shouldn't affect others if dynamic memory isn't shared//���ģ������̬�ڴ�û�й����޸�һ������Ӧ��Ӱ����������
  cout << "\nfirst.insert(6);\n";//���һ����Ϣ����ʾ��first�в�������6
  first.insert(6); // modify first only //ֻ�޸�first
  cout << "\nFirst: " << first << endl;//���first�����ݣ�Ӧ�ð���1��2��6
  cout << "Second: " << second << endl;// ���� second �� first ��ǳ�������� insert ����ͬһ���ڴ棬�����Ҳ����� 1��2��6��ʵ��Ч��ȡ���� insert ʵ�֣�
  cout << "Third: " << third << endl;//����third��first����������third��������Ȼֻ����1��2

  // TODO: note other places that copy-constructor is called automatically
  /*cout << "\nsecond = passByValueAndReturnObject(first);\n";
  second = passByValueAndReturnObject(first);*/

  // TODO: make sure destructor maintains well-formedness of object
  /*second.~GArray(); // not common, but can call destructor explicitly
  cout << "\nsecond.~GArray();\n\nsecond: " << second;
  second.insert(7); 
  cout << "\nsecond.insert(7);\n\nsecond: " << second;*/

  // TODO: implement chained assignment
  /*cout << "\nfirst = second = third;\n";
  first = second = third;
  cout << "\nFirst: " << first << endl;
  cout << "Second: " << second << endl;
  cout << "Third: " << third << endl;*/

  cout << "\nmemoryTests is returning\n"; 
}

// note: the copy-constructor gets called when parameters are passed by val
// and when objects are returned by value; note destructor calls, too!
GArray passByValueAndReturnObject(GArray arr) { //����һ���������壬����һ��GArray������Ϊ������������һ��GArray����
  cout << "passByValueAndReturnObject is running\n"; 
  return arr; 
}

