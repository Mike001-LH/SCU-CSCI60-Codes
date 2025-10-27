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

#include <iostream>
#include "garray.h"

using namespace std;

//�����д����Ǻ������������߱�������Щ�������ں��涨��//���������д����ǲ��Ժ������ֱ����ڲ��Բ��뺯�����ڴ���������Լ����ݺͷ���GArray����ĺ���
void insertTests();//���Բ��뺯�����Ⱥ�������
void memoryTests();//�����ڴ���������Ⱥ�������
GArray passByValueAndReturnObject(GArray arr);//��һ�д�����˼��������һ����ΪpassByValueAndReturnObject�ĺ������ú�������һ��GArray���͵Ĳ���arr��������һ��GArray���͵Ķ���

int main() {
  cout << "main is beginning\n\n";//�����ʾ��Ϣ����ʾmain������ʼִ��
  insertTests();//���ò��Բ��뺯����ʵ�ֲ��빦�ܵĲ���
	//memoryTests();
  cout << "\nmain is returning\n";//�����ʾ��Ϣ����ʾmain������������ִ��
  return 0;//����0����ʾ������������
}

//�����������ȫ�������鶼�Ƕ�̬����
void insertTests() {//���Բ��뺯����ʵ�ֺ�������//�����ǲ���GArray���insert�����Ĺ���
  cout << "insertTests is beginning\n\n";

  GArray arr;//����һ��GArray����arr������GArray�����0�ι�������ʼ��Ϊ������
  cout << "arr: " << arr << endl;//���arr����ĳ�ʼ״̬���������ص�<<���������ʾ����ĵ�ַ������//��������arr: (0x55f8c3e2eeb0)//����֮���������ַ������Ϊ���ص�<<������еĴ����������������ַ��Ȼ��������������ݣ�����ʱ����Ϊ�գ�����ֻ��ʾ��ַ
  arr.insert(2);//����arr�����insert����������ֵ2��������
  cout << "arr: " << arr << endl;//���arr�����״̬����ʾ����ֵ2�����������//��������arr: (0x55f8c3e2eeb0) 2
  arr.insert(4);//����ֵ4��������
  cout << "arr: " << arr << endl;//���arr�����״̬����ʾ����ֵ4�����������//��������arr: (0x55f8c3e2eeb0) 2 4
  arr.insert(6);//����ֵ6��������
  cout << "arr: " << arr << endl;//���arr�����״̬����ʾ����ֵ6�����������//��������arr: (0x55f8c3e2eeb0) 2 4 6
  arr.insert(8);//����ֵ8��������
  cout << "arr: " << arr << endl;//���arr�����״̬����ʾ����ֵ8�����������//��������arr: (0x55f8c3e2eeb0) 2 4 6 8

  arr.~GArray();//��ʽ����arr�������������(destructor)���ͷŶ�̬�ڴ�//�����ǲ��Ժ���������Ҫ���������������ͷ��ڴ棬��ֹ�ڴ�й©

  // TODO: destructor should free memory
  cout << "\ninsertTests is returning\n";//�����ʾ��Ϣ����ʾinsertTests������������ִ��
}

void memoryTests() {//�����ڴ��������ʵ�ֺ�������
  cout << "memoryTests is beginning\n\n";
  // set up two GArray objects and cout their contents
  GArray first;//������һ��GArray����first����
  first.insert(1);//����ֵ1��first������
  first.insert(2);//����ֵ2��first������
  GArray second;//�����ڶ���GArray����second����
  second.insert(3);//����ֵ3��second������
  second.insert(4);//����ֵ4��second������
  second.insert(5);//����ֵ5��second������
  cout << "First: " << first << endl;//���first���������//��������First: (0x55f8c3e2eeb0) 1 2
  cout << "Second: " << second << endl;//���second���������//��������Second: (0x55f8c3e2ef0) 3 4 5

  // TODO: assignment should enforces give identical objects separate memory
  cout << "\nsecond = first;\n";//���Ը�ֵ����������
  second = first; // without overloading =, this makes a shallow copy//���û�����ظ�ֵ������=���⽫����ǳ��������˼��second��first������ͬһ�鶯̬�ڴ�
  cout << "\nFirst: " << first << endl;//���first���������//��������First: (0x55f8c3e2eeb0) 1 2
  cout << "Second: " << second << endl;//���second���������//��������Second: (0x55f8c3e2eeb0) 1 2
  /*memory diagramʾ��ͼ��
    stack:               heap:
	first.data_  ������
				   ��
				   ������> [1][2]
				   ��
	second.data_ ������
  */

  // TODO: copy-constructor should deep copying an existing object's contents//�������캯��Ӧ�����һ�����ж��������
  cout << "\nGArray third(first);\n";//���Կ������캯��
  GArray third(first); // calls copy-constructor to make deep copy of first into new object third//���ÿ������캯������first���������������¶���third��
  cout << "\nFirst: " << first << endl;//���first���������//��������First: (0x55f8c3e2eeb0) 1 2
  cout << "Second: " << second << endl;//���second���������//��������Second: (0x55f8c3e2eeb0) 1 2
  cout << "Third: " << third << endl;//���third���������//��������Third: (0x55f8c3e2f30) 1 2
  // memory diagramʾ��ͼ��
  /*
    stack:               heap:
	first.data_  ������
				   ��
				   ������> [1][2]
				   ��       ��
	second.data_ ������       ��
					       ��
	third.data_ ������������> [1][2]
  */
  //֪ʶ�㽲�⣺
  //copy-constructor(�������캯��)�������Ǵ���һ���¶��󣬲������ж��������������¶����У�ȷ����������ӵ�ж����Ķ�̬�ڴ�ռ䣬�Ӷ����⹲���ڴ���������⡣
  //�������ʾ��ͼ�У�first��second������ͬһ�鶯̬�ڴ棬��third����ӵ���Լ������Ķ�̬�ڴ�ռ䣬�洢��first��������ݡ�
  //copy-constructor��ʵ���߼����ڣ�����һ���µĶ�̬���飬������������ж����Ԫ�ص��������У�ȷ���¶���ӵ�ж������ڴ�ռ䣬����ѵ�ַ�����ƹ�ȥ��
  // �﷨ʾ����
  // GArray::GArray(const GArray& other) { //�������캯�����壬����һ�����ж���other�ĳ�������
  //    size_ = other.size_; //���¶����size_����Ϊother�����size_
  //    if (size_ > 0) { //���size_����0����ʾ�ж�̬������Ҫ����
  //        data_ = new int[size_]; //�ڶ��Ϸ����µĶ�̬�����ڴ�
  //        for (size_t i = 0; i < size_; i++) { //�������other����Ķ�̬�������ݵ��¶���Ķ�̬������
  //            data_[i] = other.data_[i]; //���ÿ��Ԫ�أ�ȷ���¶���ӵ�ж������ڴ�ռ䣬����ѵ�ַ�����ƹ�ȥ
  //        }
  //    } else {//���size_Ϊ0����ʾû�ж�̬����
  //        data_ = nullptr;//��data_ָ������Ϊnullptr����ʾû�ж�̬����
  //    }
  // }
  //
  //��������������е�GArray third(first);���ʵ���Ͼ��ǵ��������涨��Ŀ������캯����������һ���µ�third���󣬲���first��������������third�����С�
  //Ȼ���ܳ������ǣ����ǲ�û����garray.cpp��ʵ������������캯��������ʵ����GArray third(first);��δ�����������ģ�����ʱ�����δ������Ϊ��undefined behavior�������ܻᵼ�³�����������������Ľ����

  // modifying one object shouldn't affect others if dynamic memory isn't shared//�޸�����һ������Ӧ��Ӱ�����������������û�й���̬�ڴ�
  cout << "\nfirst.insert(6);\n";//���Բ���������޸�first����
  first.insert(6); //����ֵ6��first������
  cout << "\nFirst: " << first << endl;//���first���������//��������First: (0x55f8c3e2eeb0) 1 2 6
  cout << "Second: " << second << endl;//���second���������//��������Second: (0x55f8c3e2eeb0) 1 2 6
  cout << "Third: " << third << endl;//���third���������//��������Third: (0x55f8c3e2f30) 1 2 
  //����second��first����̬�ڴ棬����secondҲ��Ӱ�죬��thirdû����Ӱ�죬����Ϊthirdͨ���񿽱����Լ������Ķ�̬�ڴ�

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

  //������Щע�͵��Ĵ�����Ϊ�˲��Դ��ݺͷ���GArray����ĺ������Լ���ʽ����������������ʽ��ֵ������������Ŀǰ��û��ʵ����ع��ܣ�������ʱע�͵��ˡ�
  cout << "\nmemoryTests is returning\n"; 
}

// note: the copy-constructor gets called when parameters are passed by val
// and when objects are returned by value; note destructor calls, too!
GArray passByValueAndReturnObject(GArray arr) { //ʵ�ֺ�������,����һ��GArray����arr������һ��GArray����
  cout << "passByValueAndReturnObject is running\n"; //�����ʾ��Ϣ����ʾ������������
  return arr; //���ش����GArray����arr
}

