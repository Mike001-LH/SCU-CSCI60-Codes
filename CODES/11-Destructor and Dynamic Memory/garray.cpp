// Implementation of GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/22/25

#include "garray.h"

// updates object so data_ addresses larger heap array with new value added//����һ���µ���΢��һ��Ķ�̬����
void GArray::insert(int val) {
  int* temp = new int[size_ + 1]; // allocate space for new bigger array//��������heap�Ϸ���һ���µĸ���Ķ�̬���飨�ڴ�+1��
  for (size_t i = 0; i < size_; i++) { //���϶�̬���������������Ƶ��µĶ�̬������
    temp[i] = data_[i];
  }
  temp[size_++] = val; // ����Ѵ����val����ֵ�ŵ��¶�̬��������һ��λ�ã�����size_����1
  //�ȷ�˵��ԭ��size_=3������һ��val��size_���4��val����temp[3]λ��
  //�����õ��˺���++�������������size_�ĵ�ǰֵ����val��Ȼ���ٰ�size_��1����������ȷ�ظ����˶�̬����Ĵ�С
  delete[] data_; //�ͷ�ԭ��data_ָ��Ķ�̬�����ڴ棬��ֹԭ��data_ָ����ڴ��ɹ¶��ڴ棬�����data_��nullptr��ʲô������
  data_ = temp; //��data_ָ���µĸ���Ķ�̬���飬Ҳ�������Ǹոմ�����temp��̬���飬����data_ָ�룬�����������ھ��������µĶ�̬���飬��ɲ������
} 

// outputs location and contents of a GArray object//���GArray�����λ�ú�����
ostream& operator <<(ostream& out, const GArray& a) {//���ز�����������������GArray�������Ϣ������ostream���ú�GArray����ĳ������ã�����ostream����
	//out���������������cout��a��Ҫ�����GArray������һ���������ã���ʾ���������޸�a����a�Ƕ�̬�������//���⣬֮���Է���ostream���ã���Ϊ��֧����ʽ���ã�����cout << a << b;
  out << "(" << a.address() << ") "; // output address of array//�����̬����ĵ�ַ
  for (size_t i=0; i<a.length(); i++) { // output array contents//�����̬��������
	  out << a[i] << " ";//�����̬������ÿ��Ԫ�ص�ֵ��ʹ�����ص�[]���������Ԫ��
  }
  return out; // return modified ostream//�����޸ĺ�����������
}
/*����ʾ�⣺
cout << a << b;
         ��
Step 1: operator<<(cout, a)
         ��� a
         ���� cout ������
         ��
Step 2: operator<<(cout, b)
         ��� b
         ���� cout ������
         ��
Step 3: cout.flush()
         ������
*/

// destructor releases dynamic memory for the associated GArray object//����������destructor���ͷ���GArray��������Ķ�̬�ڴ�
GArray::~GArray() {
  cout << "Destructor called!\n";//����������destructor��������ʱ�����ʾ��Ϣ��������Ժ͸��ٶ�����������
  delete[] data_; // avoid orphaning the dynamic array when object leaves scope//�ͷ�data_ָ��Ķ�̬�����ڴ棬��ֹ�ڴ�й©���µĹ¶��ڴ�
  data_ = nullptr; // TODO: discuss why is this useful//��data_ָ������Ϊnullptr����ֹ����ָ�����⣬ȷ��ָ�벻��ָ�����ͷŵ��ڴ�
  // TODO: discuss what other step should be added
}
//֪ʶ�㽲�⣺
//1. ����������destructor�������ã������������ڶ����������ڽ���ʱ�Զ����õ������Ա��������Ҫ�����ͷŶ����ڶ��Ϸ���Ķ�̬�ڴ棬��ֹ�ڴ�й©��
//��Ҫע����ǣ��������������ܲ�����Ҳû�з���ֵ����������������ͬ����ǰ����ϲ��˺ţ�~����
//������Ҫ��delete��delete[]���ͷŶ�̬������ڴ档Ȼ��ָ������Ϊnullptr�����Է�ֹ����ָ�����⣬ȷ��ָ�벻��ָ�����ͷŵ��ڴ棬�Ӷ�����Ǳ�ڵ�δ������Ϊ��

// FRIDAY TODO: recap/polish destructor and implement = and copy constructor