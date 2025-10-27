// Implementation of GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/24/25

#include "garray.h"

// outputs location and contents of a GArray object//���GArray�����λ�ú�����//����������غ���
ostream& operator <<(ostream& out, const GArray& a) {//out������������ã��κ��������������Ϊ���������������a��GArray����ĳ������ã��Ǵ��������
  out << "(" << a.address() << ") "; // show where the array lives
  for (size_t i=0; i<a.length(); i++) { // output array contents
    out << a[i] << " ";
  }
  return out; // return modified ostream//�����޸ĺ�����������֧����ʽ���
}

// updates object so data_ addresses larger heap array with new value added//��������������ǽ�һ���µ�ֵ���뵽��̬�����У����Ҷ�̬�ص�������Ĵ�С��������ֵ
void GArray::insert(int val) {//����һ������ֵval����̬������
  int *temp = new int[size_+1]; // allocate space for new bigger array //���ڶ��Ϸ���һ���µĶ�̬���飬��С��ԭ����1
  for (size_t i=0; i<size_; i++) { // copy contents from old array
    temp[i] = data_[i];//�����ԭ�����е�Ԫ�ظ��Ƶ���������
  }
  //���������������ݺ󣬽���ֵ��ӵ�����������һ��λ��
  temp[size_++] = val; // add new value//�������д��������size_��Ϊ��������val��Ȼ��size_����1�������ȱ�֤�˲����λ����ȷ���ٸ���size_��ֵ//size_++�Ǻ�׺�������������ʹ�õ�ǰֵ������
  delete[] data_; // does nothing if data_ is nullptr, deallocates otherwise //���ȰѾ������ͷŵ�
  data_ = temp; // repoints data_ to the new bigger heap array//Ȼ��data_ָ�������飬�����͵õ�һ��������ֵ��data_��̬����
} 

// destructor releases dynamic memory for the associated GArray object//�������������ͷ�GArray������ʹ�õĶ�̬�ڴ�
GArray::~GArray() {
  cout << "Destructor: (" << data_ << ")\n";//������Ϣ�������ǰ�����data_ָ���ַ
  delete[] data_; // avoid orphaning the dynamic array when object leaves scope//�ڶ����������ڽ���ʱ���ͷ�data_ָ��Ķ�̬���飬��ֹ�ڴ�й©��ɹ¶��ڴ�
  data_ = nullptr; // avoid leaving object with dangling pointer//��data_ָ����Ϊnullptr����ֹ����ָ������
  size_ = 0; // leave object as well-formed empty array to allow future use//��size_��Ϊ0�����ֶ���������״̬������δ������ʹ��
}

// assignment deep copies rhs data into separate dynamic array for calling object//��ֵ��������أ���rhs�����this�У�����һ�����󱻸�ֵ����һ������ʱ���á�
void GArray::operator =(const GArray& rhs) {//rhs�Ǵ����һ��������������
  cout << "Assignment: (" << data_ << ") <- (" << rhs.data_ << ")\n";//data_�ǵ��ö����data_ָ�룬rhs.data_�Ǵ�������data_ָ��//�ȷ�˵��a = b; �����data_����a��data_��rhs.data_����b��data_
  size_ = rhs.size_; //����rhs��size_�����ö����size_
  //data_ = rhs.data_; // shallow copy (what compiler does without an overload)��Ϊ����ֱ�Ӱ�ָ���ַ��ֵ��ȥ�ˣ�������ǳ�������ᵼ����������ָ��ͬһ���ڴ�
  delete[] data_;//���ڰ�ԭ����data_�ͷŵ�����ֹ�ڴ�й©
  data_ = new int[size_];//Ϊ���ö������һ���µĶ�̬���飬��С��rhs��size_��ͬ
  for (size_t i=0; i<size_; i++) {
    data_[i] = rhs.data_[i];//�����rhs�����ݸ��Ƶ����ö����data_�����У�ʵ�����������һ����ֻ���������ݣ�������ָ���ַ
  }
}

// copy constructor constructs new object by deep copying other existing object //�������캯������other������¶����У�������һ�������ʼ����һ������ʱ���á�
GArray::GArray(const GArray& other) : GArray() {//����һ�����е�GArray����other��ʹ�ù��캯��ί�е���Ĭ�Ϲ��캯����ʼ���¶���
  cout << "Copy constructor: (" << other.data_;//������Ϣ�����other��data_ָ���ַ
  size_ = other.size_;//��other��size_���Ƶ��¶����size_
  data_ = new int[size_];//Ϊ�¶������һ���µĶ�̬���飬��С��other��size_��ͬ
  cout << ") -> (" << data_ << ")\n";//����¶����data_ָ���ַ
  for (size_t i=0; i<size_; i++) {
    data_[i] = other.data_[i];//����������other�����ݸ��Ƶ��¶����data_�����У�ʵ�����
  }
}

// alternative copy constructor uses constructor delegation and =
/*GArray::GArray(const GArray& other) : GArray() {
  cout << "Copy constructor called\n";
  *this = other;
}*/



