// Test code while completing the static array implementation of Bag.
//
// Note: You must compile this and the implementation file to run this, e.g.,
//   $ g++ bagtests.cpp bag.cpp -std=c++11
//
// Sara Krehbiel, 10/6/25

#include <iostream>// for cout, endl
#include <fstream>// for ofstream
#include "bag.h"// include the interface for Bag

using namespace std;

int main() {
	cout << "Any Bag has capacity " << Bag::CAPACITY << endl; // static const CAPACITY �� public static const �ೣ�����༶�����ж���������ֱ��ͨ�� Bag::CAPACITY ���ʣ�ֵ�� 1000

	// construct an empty bag and add to it

	Bag b1; // default/0-arg constructor ����һ����b1�Ŀ�bag //b1��һ����bag
	size_t n = b1.size(); //��˼�ǵ���b1��size()���������ص�ǰbag��int����������ֵ��n // nӦ����0
	cout << "Initial bag size: " << n << endl;//�����ʼbag�Ĵ�С��Ӧ����0
	b1.insert(2); // insert 2 into the bag
	b1.insert(3); // insert 3 into the bag
	cout << "Size after inserting 2 and 3: " << b1.size() << endl; // should be 2 //�������2��3���bag��С��Ӧ����2
	cout << "The first entry is " << b1[0] << endl;// should be 2 //���bag�е�һ��Ԫ�أ�Ӧ����2
	cout << "The next entry is " << b1[1] << endl;// should be 3 //���bag�еڶ���Ԫ�أ�Ӧ����3
	cout << "The next entry is " << b1[2] << endl; // undefined content!//���bag�е�����Ԫ�أ�Ӧ����δ�������ݣ���Ϊֻ����������Ԫ��
	cout << "The next entry is " << b1[3] << endl; // undefined content! //���bag�е��ĸ�Ԫ�أ�Ӧ����δ�������ݣ���Ϊֻ����������Ԫ��

	// use << to print contents of bag to console
	cout << b1 << endl;//����������<<����������Կ���ֱ����cout��ӡbag������

	// use the same << to print contents of bag to file
	ofstream fout("contents.txt");//����һ��ofstream����fout����һ����Ϊcontents.txt���ļ�
	fout << b1 << endl;//��bag������д���ļ�
	fout.close();//�ر��ļ�����ֹ���ݶ�ʧ


	// construct a bag initialized with some contents, query, and erase from it

	int arr[5];// = {5, 4, 5, 5, 1}; // initialize an array
	arr[0] = 5; arr[1] = 4; arr[2] = 5; arr[3] = 5; arr[4] = 1;//�����鸳ֵ
	Bag b2(arr, 5); // 2-arg constructor //����2�ι�����������һ����b2��bag��������arr�����ǰ5��Ԫ��
	cout << "Bag 2:\n" << b2 << endl; // use of overloaded insertion //���bag2�����ݣ�����"5 4 5 5 1 " //�������� Bag 2: 5 4 5 5 1
	cout << "Bag 2 size: " << b2.size() << endl;//���bag2�Ĵ�С��Ӧ����5//�������� Bag 2 size: 5

	cout << b2.count(5) << " 5s\n";// should be 3 //���bag2��5���ֵĴ�����Ӧ����3 //�������� 3 5s

	cout << "Attempting to erase 4:\n";
	bool erased = b2.erase_one(4);// should be true //����erase_one����������ɾ��bag2�е�һ�����ֵ�4������ֵ����erased��Ӧ����true
	cout << (erased ? "C" : "Not c") << "hanged: " << b2 << endl;//������Ŀ����������erasedΪtrue�����"Changed: "���������"Not changed: "��Ȼ�����bag2������ //�������� Changed: 5 5 5 1
	cout << "Attempting to erase -1:\n";
	erased = b2.erase_one(-1);// should be false //����ɾ��bag2�е�һ�����ֵ�-1������û��-1������ֵ����erased��Ӧ����false
	cout << (erased ? "C" : "Not c") << "hanged: " << b2 << endl;//����� Not changed: 5 5 5 1
	cout << "Erasing all 5s:\n";
	cout << b2.erase(5) << " erased: " << b2 << endl;//����erase������ɾ��bag2�����е�5������ɾ����������Ӧ����3��Ȼ�����bag2������ //�������� 3 erased: 1 //Ҳ����˵bag2��ɾ��4��5֮������ֻ��"1 "��
	
	// test code to make sure erasing at end of bag works

	Bag b3; // call 0-arg constructor for an empty bag //����һ����b3�Ŀ�bag
	b3.insert(1);// insert 1 into the bag
	b3.insert(2);// insert 2 into the bag
	b3.insert(3);// insert 3 into the bag
	cout << b3 << endl; //���bag3��Ӧ����"1 2 3 "
	b3.erase_one(3);//ɾ��bag3�е�һ�����ֵ�3
	cout << b3 << endl;//���bag3��Ӧ����"1 2 "

	// test code for += and +

	cout << "b1: " << b1 << "\nb2: " << b2 << endl;//���bag1��bag2�����ݣ�Ӧ����"2 3 "��"1 "
	b2 += b1; // += mutates left operand (b2) without creating a new object//����+=���������bag1��������ӵ�bag2�У�bag2��Ϊ"1 2 3 "
	cout << "b2, after b2+=b1: " << b2 << endl;//���bag2�����ݣ�Ӧ����"1 2 3 "
	// + creates new object, but this test code inserts it without naming
	cout << "b1+b2: " << b1 + b2 << endl; //����+�����������һ���µ�bag����������bag1��bag2�����ݵĽ�ϣ�Ȼ����������bag�����ݣ�Ӧ����"2 3 1 2 3 "

	return 0;
}

