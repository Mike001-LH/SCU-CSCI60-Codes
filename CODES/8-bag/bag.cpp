// Function definitions for static array implementation of Bag data structure
// Sara Krehbiel, 10/8/25

#include "bag.h"

// constructs bag pre-populated with contents according to array a //��ע�͵����Ǿɰ汾��2�ι�����
/*Bag::Bag(int a[], size_t n) : size_(n)  {
	for (size_t i=0; i<n; i++) {
		data_[i] = a[i];
	}
}*/


// 10:15 section 2-arg constructor initializes empty bag and uses insert
// ���� 0�ι�����������ί�У�
/*
Bag() ����������Ĺ��캯����
Bag(int a[], size_t n) : Bag() ��ʾ�ȵ�������Ĺ��캯������ size_ ��ʼ��Ϊ 0��
Ȼ��ִ�� for ѭ�������������ݡ�
*/
//�°汾��2�ι�������֮ͬ�����ڣ����ȵ���Ĭ�Ϲ�������0�ι�����������ʼ��һ����bag��Ȼ��ͨ��insert������������a��ǰn��Ԫ��
Bag::Bag(int a[], size_t n) : Bag() { // NOTE֪ʶ��: constructor delegation!//�����: Bag()������Ĭ�Ϲ���������ʼ����һ����bag//constructor delegation����˼�ǹ��캯��ί��,������һ�����캯������ʼ������
	//�ȵ���Ĭ�Ϲ���������ʼ��һ����bag������Bag():size_(0){}�����ǵ�Ĭ�Ϲ�����������size_����ʼ��Ϊ0
	for (size_t i=0; i<n; i++) {
		insert(a[i]);//����insert������������a��ǰn��Ԫ��,insert��������bag�Ƿ�����,��ֹ������Ӷ���ʼ��һ�������ݵ�bag
	}
}

// loops through data_, keeping track of and then returning # times val occurs
//���ã�����val��bag�г��ֵĴ���
size_t Bag::count(int val) const {
	size_t counter = 0;//����������¼val���ֵĴ�������ʼֵΪ0
	for (size_t i=0; i<size_; i++) {
		if (data_[i] == val) counter++;//���data_[i]����val����������1
	}
	return counter;
}



// inserts each element of the bag, separated by spaces, into o, and returns o
//���ã�����<<���������ӡbag������
ostream& operator <<(ostream& o, const Bag& b) {//ostream& operator�������������ostream& o�����������const Bag& b��Ҫ��ӡ��bag����//&����˼�Ǵ����ã����⿽�������Ч�ʣ��൱��ֱ�Ӱ�ԭ�����ù����ã�
	size_t n = b.size();//��b.size()��ȡbag�Ĵ�С����ֵ��n
	for (size_t i=0; i<n; i++) {
		o << b[i] << " ";//o��������������Կ��Ե���cout�ã�b[i]��bag�е�i��Ԫ��
	}
	return o;//����ostream�����Ա�֧����ʽ���ã�����cout << b1 << b2;//��Ȼֻ�ܴ�ӡһ��bag
}

// searches for first instance of val and moves all subsequent values back
//���ã�ɾ��bag�е�һ�����ֵ�val
bool Bag::erase_one(int val) {
	bool found = false;//��־��������ʾ�Ƿ��ҵ�val����ʼֵΪfalse
	for (size_t i = 0; i < size_; i++) {//����bag�е�ÿ��Ԫ��
		// when val is FIRST found, flip found bool and decrement size
		if (!found && data_[i] == val) {//����ҵ�val��֮ǰû���ҵ���
			found = true;//��found��Ϊtrue����ʾ�ҵ���val
			size_--;//��size_��1����ʾbag��Ԫ������������1
		}
		// if val has already been found, overwrite current entry with next
		if (found) data_[i] = data_[i + 1];//����Ѿ��ҵ���val������ǰԪ�ظ���Ϊ��һ��Ԫ�أ�ʵ��ɾ��Ч��
		//ע�⣺����û��break����ΪҪ�Ѻ����Ԫ�ض���ǰ��һλ�����ǵ���ɾ����Ԫ��
		//Խ�������˵����data_[i + 1]��i=size_-1ʱ��Խ����������ǰ�ȫ�ģ���Ϊsize_�Ѿ���1�ˣ�data_[size_]��δ�������ݣ����ᱻ���ʵ�
	}
	return found;//�����Ƿ��ҵ���val
}

// uses erase_one to remove all copies of val and return # removed
//���ã�ɾ��bag�����г��ֵ�val��������ɾ��������
size_t Bag::erase(int val) {
	size_t counter = 0;//����������¼ɾ����val����������ʼֵΪ0
	while (erase_one(val)) {//����erase_one����ɾ����һ�����ֵ�val��ֱ��û��valΪֹ
		counter++;//ÿɾ��һ��val����������1
	}
	return counter;//����ɾ����val������
}

// FRIDAY TODO: overload += and +

// add contents of rhs to the data_ array of calling object
//���ã�����+=���������rhs�е�������ӵ���ǰbag�У����ı�rhs 
void Bag::operator +=(const Bag& rhs) {
	for (size_t i = 0; i < rhs.size_; i++) {
		//insert(rhs[i]);	//Ҳ������insert��������rhs�е�ÿ��Ԫ�أ����������μ��������Ч�ʽϵ�
		data_[size_++] = rhs.data_[i];//data_ �� size_ �� Bag ��˽�г�Ա����Ա������ֱ�ӷ������ǡ�//���д���������ǽ� rhs �е�ÿ��Ԫ�����β��뵽��ǰ bag �� data_ �����У������� size_��
		//data_[size_++]����ֵ��left-hand side��,��ǰ��calling object��Ҳ���� lhs���� data_ �������±�Ϊ size_ ��λ��
		//rhs.data_[i]����ֵ��right-hand side��,��� Bag �еĵ� i ��Ԫ��//size_++�Ǻ��õ������������ʾ��ʹ�õ�ǰ�� size_ ֵ��Ȼ���ٽ� size_ ���� 1
	}
}///����ʹ��˵����
// Bag b1, b2;  b1 += b2;  // ��b2��������ӵ�b1��
//���������Զ�����������д��뷭��ɺ������ã�b1.operator+=(b2);
//�������壺void Bag::operator+=(const Bag& rhs) { ... } //�������ڵ���ʱ�Զ����룺lhs ���� b1��rhs ���� b2��
//����֮��������ֻд��rhs������Ϊlhs�ǵ��øú����Ķ������������ش����ں����ڲ�������ֱ��ʹ�á�
//lhs��rhs��Ҫд�����Ϊ��Bag operator+(const Bag& lhs, const Bag& rhs) { ... } //��Ϊ�������������ĳ�Ա���������Ա�����ʽ�ش�������������
//�����ǵ�void Bag::operator+=(const Bag& rhs) { ... }������ĳ�Ա����������ֻ��rhs��Ҫ��ʽ���롣
//lhs�ǵ��øú����Ķ��������ش����ں����ڲ�������ֱ��ʹ�á�rhs�Ǵ������һ��bag����Ҫ��ʽ���롣

// create and return third bag object with combined contents of lhs and rhs
//���ã�����+�����������һ���µ�bag������lhs��rhs�����ݣ��Ҳ��ı�lhs��rhs
Bag operator +(const Bag& lhs, const Bag& rhs) {//���Ƿǳ�Ա������û�� this���������������������������ʽ�Բ������루const Bag& lhs, const Bag& rhs����
//�����ڴ����ֲ����� sum���ȿ� lhs �ٿ� rhs ����ЧԪ�ص� sum����ֵ���أ�ͨ������ RVO/NRVO�������޸� lhs��rhs��
	Bag sum;//����һ���µ�bag����sum�����ڴ洢lhs��rhs������
	size_t n = lhs.size();//��ȡlhs�Ĵ�С����ֵ��n
	for (size_t i = 0; i < n; i++) {
		sum.insert(lhs[i]);//insert������lhs�е�ÿ��Ԫ�ز��뵽sum��
	}
	n = rhs.size();//��ȡrhs�Ĵ�С����ֵ��n
	for (size_t i = 0; i < n; i++) {
		sum.insert(rhs[i]);//insert������rhs�е�ÿ��Ԫ�ز��뵽sum��
	}
	return sum;//�����µ�bag����sum
}
//����ʹ��˵����
// Bag b1, b2;  Bag b3 = b1 + b2;  // ��b1��b2�����ݺϲ���b3�У�b1��b2����//����b1��{1,2}��b2��{3,4}����b3��{1,2,3,4}��b1��b2����
