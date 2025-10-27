// Interface for GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/24/25

#ifndef GARRAY_H
#define GARRAY_H

#include <iostream>

//using namespace std;
using std::ostream;// for operator <<��ostream�Ǳ�׼�����������
using std::cout; // for debugging
using std::endl; // for debugging

class GArray {
public:
	// constructor and dynamic memory management functions//�������Ͷ�̬�ڴ������
	//rule of three: ���һ������Ҫ�Զ��������������������캯����ֵ������е��κ�һ������ôͨ����Ҫ�Զ���������������ȷ����Դ�����һ���Ժ���ȷ�ԡ�
  GArray() : size_(0), data_(nullptr) {} // a basic 0-arg constructor
  GArray(const GArray&); // copy constructor (deep copy other into new object)//1���������캯������other������¶����У�������һ�������ʼ����һ������ʱ���á�
  ~GArray(); // destructor (automatically called by compiler)//2�������������ɱ������Զ����ã����������������ڽ���ʱ�Զ����ã������ͷ���Դ��
  void operator =(const GArray& rhs); // assignment (deep copy rhs into this) //3����ֵ���������rhs�����this�У�����һ�����󱻸�ֵ����һ������ʱ���á�

  // mutator to insert in new slightly larger array
  void insert(int val); 

  // accessors to get size, individual elements, and location of array
  size_t length() const { return size_; }
  int operator [](size_t i) const { return data_[i]; }
  int *address() const { return data_; }

private:
  size_t size_;//��������ĵ�ǰ��С
  int* data_;//����һ��ָ��̬��������������ָ��
  // INVARIANT: data_ addresses a dynamic array of size_ ints if size_>0, 
  //            or data_ is nullptr
};

ostream& operator <<(ostream& out, const GArray& a); // insertion overload //������أ�һ����˵������ض�Ҫͨ������ostream���ú�const����������ʵ����ʽ���

#endif

/*��ڿε���֪ʶ�㽲�⣺
1. �����ǳ����������
2. ��̬�ڴ�������ͷ�
3. ��������������
4. �������캯����ʵ��
5. Rule of Three��������

1. �����ǳ����������
ǳ����ֻ�Ǽ򵥵ظ���ָ���ַ�����¶��������ͬһ���ڴ棬���ܻ���һ����������ʱ�����������������ָ�����⡣
�������Ϊÿ���������������ڴ�ռ䣬����ʵ�����ݣ��������������⡣
ǳ������shallow copy������ʾ����
GArray a;
GArray b = a; // Ĭ��ǳ������b.data_ �� a.data_ ָ��ͬһ����ڴ棡
�����deep copy������ʾ����
//����дһ���򵥵����ʵ��
void GArray::operator =(const GArray& rhs) {// ���ظ�ֵ�����ʵ�����
	size_ = rhs.size_;//size_��rhs.size_��ȣ��ȷ�˵���ڵ��� GArray a = b; ʱ, size_����a��size_rhs, rhs.size_����b��size_//����֮���Բ���д��lhs.size_������Ϊlhs�������ĵ��ö�����Ϊ����һ��member function
	data_ = new int[size_];//����һ���µĶ�̬���飬�����ڴ�
	for (size_t i=0; i<size_; i++) {
		data_[i] = rhs.data_[i];//�������ݣ�ʵ������������Ǽ򵥵ظ���ָ���ַ
	}
}
��������ͨ�������ַ����rhs�������µ��ڴ棬���������ݣ�ʵ���������

2. ��̬�ڴ�������ͷţ�
��̬�ڴ�����������������ʱ�����ڴ�ռ䣬ʹ��new�ؼ��ַ����ڴ棬ʹ��delete�ͷ��ڴ棬��ֹ�ڴ�й©��

3. �������������ã�
�������������ͷŶ���ռ�õ���Դ��������̬������ڴ档���ڶ����������ڽ���ʱ�Զ����ã�ȷ����Դ�õ���ȷ�ͷţ���ֹ�ڴ�й©��
�﷨Ϊ��
~ClassName() {
	// �ͷ���Դ�Ĵ��룬����delete����ָ���ÿյȲ���
}
// ���磺
GArray::~GArray() {
	delete [] data_; // �ͷŶ�̬�����ڴ�
	data_ = nullptr; // ��������ָ��
	size_ = 0; // ���ô�С
}
//������������������ͷ�GArray����Ķ�̬�����ڴ棬��ֹ�ڴ�й©�����⣬size_����Ϊ0����Ϊ�����������ڽ�����size_���������塣

4. �������캯����ʵ�֣�
�������캯�����ڴ���һ���¶��󣬲�����һ��ͬ���Ͷ�������ݸ��Ƶ��¶����С���ͨ�����ڰ�ֵ���ݶ���򷵻ض���ʱ��
�﷨Ϊ��
ClassName(const ClassName& other) {
	// ����other��������ݵ��¶���
}
	// ���磺
GArray a;
GArray b = a; // ���ÿ������캯��
GArray::GArray(const GArray& other) : GArray() {//���������Ĭ�Ϲ��캯����ʼ���¶���Ч�����Ƚ�size_��Ϊ0��data_��Ϊnullptr//���⣬���ﴫ�����const���õ�other���󣨰ѱ��崫�����������޸ģ�
	//other���Ѿ����ڵĶ�������Ҫ���������ݸ��Ƶ��¶�����
	size_ = other.size_;//��other��size_��ֵ���¶����size_
	data_ = new int[size_];
	for (size_t i=0; i<size_; i++) {
		data_[i] = other.data_[i];
	}
}

5. Rule of Three�������򣩣�
���һ������Ҫ�Զ�������������destructor�����������캯����copy constructor����ֵ�������assignment operator���е��κ�һ������ôͨ����Ҫ�Զ���������������ȷ����Դ�����һ���Ժ���ȷ�ԡ�
�﷨ʾ����
class ClassName {
public:
	ClassName(); // Ĭ�Ϲ��캯��
	ClassName(const ClassName&); // �������캯��
	~ClassName(); // ��������
	void operator =(const ClassName&); // ��ֵ�����
	private:
	// ��Ա����
	};
}



*/