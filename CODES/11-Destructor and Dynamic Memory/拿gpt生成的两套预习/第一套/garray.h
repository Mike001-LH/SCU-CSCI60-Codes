// garray.h
// Lesson 10 �� Destructor & Dynamic Memory in Classes (Rule of Three)
// Ԥϰ�棺�����������������졢��ֵ����������롢���

#ifndef GARRAY_H
#define GARRAY_H

#include <iostream>
#include <cstddef>

using std::ostream;
using std::cout;
using std::endl;

class GArray {
public:
	// 0-arg ctor: �����飻size_=0, data_=nullptr
	GArray() : size_(0), data_(nullptr) {}

	// Rule of Three
	~GArray();                               // �������ͷŶ�����					//Destructor �� �ͷ���Դ
	GArray(const GArray& other);             // �������죺���					//Copy Constructor �� ���
	GArray& operator=(const GArray& rhs);    // ��ֵ����� + �Ը�ֵ���� + ��ʽ	//Copy Assignment Operator �� �����ֵ

	// ������Ϊ
	void insert(int val);                    // �ԡ��¿��������顱�ķ�ʽβ��
	size_t length() const { return size_; }  // Ԫ�ظ���
	int operator[](size_t i) const { return data_[i]; } // ֻ���±꣨��ʾ�ã�
	int* address() const { return data_; }   // ���صײ������ַ�����ڹ۲죩

	// �����������ѡ������ vector::push_back ����
	void push_back(int val) { insert(val); }

private:
	size_t size_; // ���ó���
	int* data_; // ָ�� size_ �� int �Ķ����飻size_==0 ʱӦΪ nullptr

	// INVARIANT:
	//  - �� size_ > 0���� data_ ָ����ϴ�СΪ size_ �� int ����
	//  - �� size_ == 0���� data_ == nullptr
};

// �ǳ�Ա���������ַ + ���ݡ������ڹ۲��Ƿ���ͬһ����ڴ�
ostream& operator<<(ostream& out, const GArray& a);

#endif // GARRAY_H
