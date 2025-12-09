#include <iostream>
#include "bag.h"
#include "node.h"
using namespace std;

int main() {
    bagTests();
    //iteration();
    //bagIteratorTests();
    return 0;
}

// test code for basic bag functions
void bagTests() {
    // construct empty bag and insert
    Bag<int> b;
    b.insert(1);//插入元素1
    b.insert(2);//插入元素2
    b.insert(2);//插入元素2
    b.insert(3);//插入元素3

    // test << overload and size/count
    cout << "b: " << b << endl;
	cout << "size: " << b.size() << endl;//输出袋子的大小
	cout << "#1s: " << b.count(1) << endl;//输出袋子中元素1的个数
	cout << "#2s: " << b.count(2) << endl;//输出袋子中元素2的个数
	cout << "#3s: " << b.count(3) << endl;//输出袋子中元素3的个数
	cout << "#4s: " << b.count(4) << endl;//输出袋子中元素4的个数

    Bag<int> empty;
    cout << "#1s in an empty bag: " << empty.count(1) << endl;//输出：0

    // test erase_one and erase functions
    cout << b.erase_one(2) << endl;
	cout << b.erase_one(3) << endl; //also replace with
	cout << b.erase_one(5) << endl;
	cout << "b: " << b << endl;
    //cout << b.erase(2) << endl;
}
