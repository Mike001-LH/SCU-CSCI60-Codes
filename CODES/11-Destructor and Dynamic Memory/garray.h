// Interface for GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/22/25

#ifndef GARRAY_H
#define GARRAY_H

#include <iostream>

//using namespace std;
using std::ostream;
using std::cout; // for debugging
using std::endl; // for debugging

class GArray {
public:
	GArray() : size_(0), data_(nullptr) {} // a basic 0-arg constructor, initializes empty array//0�ι���������ʼ��Ϊ�ն�̬����
  ~GArray(); // destructor (automatically called by compiler)//destructor�������ͷŶ�̬�ڴ�ģ�����Ϊ���ͷŶ�̬������ڴ棬д��Ϊ
			 // GArray::~GArray() {
			 //    delete [] data_;
			 //    data_ = nullptr;
			 // }

  // TODO: declare dynamic memory management functions = and copy constructor

  // mutator to insert in new slightly larger array//���ģ�����һ���µ���΢��һ�������
  void insert(int val); 

  // accessors to get size, individual elements, and location of array//��ȡ��С������Ԫ�غ�����λ�õķ�����
  size_t length() const { return size_; }//��������ĳ���
  int operator [](size_t i) const { return data_[i]; }//����[]����������������е�i��Ԫ�ص�ֵ
  int* address() const { return data_; }//��������ĵ�ַ

private:
  size_t size_;//�洢����Ĵ�С
  int* data_;//ָ��̬��������������ָ��
  // INVARIANT: data_ addresses a dynamic array of size_ ints if size_>0, 
  //            or data_ is nullptr
};

ostream& operator <<(ostream& out, const GArray& a); // insertion overload//���ز��������

#endif