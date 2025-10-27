// Interface for GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/22/25

#ifndef GARRAY_H
#define GARRAY_H

#include <iostream>

//using namespace std;
using std::ostream;//ostream��һ�����������
using std::cout; // for debugging
using std::endl; // for debugging

class GArray {
public:
  GArray() : size_(0), data_(nullptr) {} // a basic 0-arg constructor//������캯����ʼ����һ���յ�GArray���󣬴�СΪ0������ָ��Ϊnullptr

  // TODO: declare dynamic memory management functions

  // mutator to insert in new slightly larger array
  void insert(int val); // TODO: implement in garray.cpp//�����������garray.cpp��ʵ�֣������ڶ�̬�����в���һ���µ�����ֵ

  // accessors to get size, individual elements, and location of array
  size_t length() const { return size_; }//���ص�ǰ�洢����������
  int operator [](size_t i) const { return data_[i]; }//���� ������ �������ʹ������� arr[i] ����Ԫ�أ�ֻ����
  int* address() const { return data_; }//����ָ��̬���������ָ��	// ���صײ�����ָ�룬��������ʹ�ã��ⲿ��Ҫ delete[]

private:
  size_t size_;// �洢����������
  int* data_;//����һ��ָ��̬���������ָ��
  // INVARIANT: data_ addresses a dynamic array of size_ ints if size_>0, 
  //            or data_ is nullptr
};

ostream& operator <<(ostream& out, const GArray& a); //������������������ ostream&�����ã���������ʽ�����cout << a << b;
// TODO: implement
//ostream& out������������ã�const GArray& a��Ҫ�����GArray����ĳ�������

#endif