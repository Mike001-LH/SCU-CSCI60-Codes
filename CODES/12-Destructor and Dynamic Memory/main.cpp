// Test file illustrating memory management for classes, specifically GArray.
// We'll implement insert to handle dynamic memory for a single object, and 
// by the end of the week, we'll have understood the need for and implemented
// an overloaded assignment operator, a copy constructor, and a destructor.
//
// WEDNESDAY: 
//   Overview interface in garray.h and insertTests in main
//   Implement insert using dynamic memory
// FRIDAY: 
//   Implement DESTRUCTOR with cout statements to see when it's called
//   Overload ASSIGNMENT operator to deep copy rhs
//   Implement a COPY CONSTRUCTOR to deep copy existing object into new one
// MINI-LECTURE:
//   Run passByValueAndReturnObject to learn when various functions are called
//   Modify assignment operator to allow for chained assigment
//   
// Sara Krehbiel, 10/22/25-10/24/25

#include <iostream>
#include "garray.h"

using namespace std;

void insertTests();//���ǲ�����Ժ���������
void memoryTests();//�����ڴ���Ժ���������
GArray passByValueAndReturnObject(GArray arr);//����һ����������������һ��GArray���󣬷���һ��GArray����

int main() {
  cout << "main is beginning\n";
  //insertTests();
	memoryTests();
  cout << "\nmain is returning\n";
	return 0;
}

void insertTests() {//����insert�����Ĺ���
  cout << "\ninsertTests is beginning\n\n";

  GArray arr;//����һ��GArray����arr����
  cout << "arr: " << arr << endl;
  arr.insert(2);
  cout << "arr: " << arr << endl;
  arr.insert(4);
  cout << "arr: " << arr << endl;
  arr.insert(6);
  cout << "arr: " << arr << endl;
  arr.insert(8);
  cout << "arr: " << arr << endl;

  cout << "\ninsertTests is returning\n";
  // NOTE: destructor automatically gets called (should free memory)
}

void memoryTests() {//�����ڴ������صĹ���
  cout << "\nmemoryTests is beginning\n\n";
  // set up two GArray objects and cout their contents
  GArray first;//������һ��GArray����first����
  first.insert(1);
  first.insert(2);
  GArray second;//�����ڶ���GArray����second����
  second.insert(3);
  second.insert(4);
  second.insert(5);
  cout << "First: " << first << endl;//����� First: (First�ĵ�ַ) 1 2
  cout << "Second: " << second << endl;//����� Second: (Second�ĵ�ַ) 3 4 5

  // assignment should give identical objects separate memory
  cout << "\nsecond = first;\n";//��������Ҫ���Ը�ֵ���������صĹ���
  second = first; // without overloading =, this makes a shallow copy//���û������=����������������ǳ�������������Ѿ������ˣ����Ի�������
  cout << "\nFirst: " << first << endl;//����� First: (First�ĵ�ַ) 1 2
  cout << "Second: " << second << endl;//����� Second: (Second�ĵ�ַ) 1 2

  // copy-constructor should deep copy an existing object's contents
  cout << "\nGArray third(first);\n";//��������Ҫ���Կ������캯���Ĺ���
  GArray third(first); //���ÿ������캯��������third������first����� //ps������Ҳ����д�� GArray third = first;Ч����һ���ģ���Ϊ���ǵ��ÿ������캯��
  //�������ڣ�GArray third(first); �Ƕ�����һ��GArray���third����Ȼ��ֱ������һ����first�Ķ�������ʼ���¶���
  //�� GArray third = first; ��� third �Ѿ����ڣ��ǵ��õ��ǿ�����ֵ�������operator=��//��� third �����ڣ��ǵ��õ��ǿ������캯����
  cout << "\nFirst: " << first << endl;//����� First: (First�ĵ�ַ) 1 2
  cout << "Second: " << second << endl;//����� Second: (Second�ĵ�ַ) 1 2
  cout << "Third: " << third << endl;//����� Third: (Third�ĵ�ַ) 1 2

  // modifying one object shouldn't affect others if dynamic memory isn't shared
  cout << "\nfirst.insert(6);\n";
  first.insert(6); //��first�����в���6
  cout << "\nFirst: " << first << endl;//����� First: (First�ĵ�ַ) 1 2 6
  cout << "Second: " << second << endl;//����� Second: (Second�ĵ�ַ) 1 2
  cout << "Third: " << third << endl;//����� Third: (Third�ĵ�ַ) 1 2

  // note that destructor maintains well-formedness of object
  cout << "\nsecond.~GArray();\n";//����second����������������ͷ��䶯̬�ڴ�
  second.~GArray(); // not common, but can call destructor explicitly//ͨ������������������ʽ������������
  //PS�����������������﷨�� ������.~����(); �����������GArray
  cout << "\nSecond: " << second;//����� Second: (0x0) ����Ϊ����������data_��Ϊnullptr��size_��Ϊ0
  second.insert(7); //��second�����в���7 //��Ȼ���������������ͷ���second�Ķ�̬�ڴ棬��������Ϊnullptr����insert�������½�һ���µĶ�̬����Ȼ������second������7�����������ǺϷ���
  cout << "\n\nsecond.insert(7);\n\nFirst: " << first << endl;//���: First: (First�ĵ�ַ) 1 2 6
  cout << "Second: " << second << endl;//���: Second: (Second�ĵ�ַ) 7
  cout << "Third: " << third << endl;//���: Third: (Third�ĵ�ַ) 1 2

  // TODO: note other places that copy-constructor is called automatically
  cout << "\nsecond = passByValueAndReturnObject(first);\n\n";
  second = passByValueAndReturnObject(first);//���ú���������first���󣬷���һ��GArray����Ȼ��ֵ��second����//�������ÿ������캯���͸�ֵ���������
  cout << "\nFirst: " << first << endl;//����� First: (First�ĵ�ַ) 1 2 6
  cout << "Second: " << second << endl;//����� Second: (Second�ĵ�ַ) 1 2 6
  cout << "Third: " << third << endl;//����� Third: (Third�ĵ�ַ) 1 2

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
//��������������Ǵ���һ��GArray����arr����������ݣ������ظö��󣬿����������Կ������캯�������������ĵ���ʱ��
GArray passByValueAndReturnObject(GArray arr) { //����һ��GArray����arr������һ��GArray����
  cout << "passByValueAndReturnObject is running\n"; //������Ϣ����ʾ������������
  cout << "arr: " << arr << endl;//��������arr���������
  return arr; //���ش����arr�����������ÿ������캯������һ���µ�GArray������Ϊ����ֵ
}

