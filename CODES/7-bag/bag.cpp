// Function definitions for static array implementation of Bag data structure
// Sara Krehbiel, 10/6/25

#include "bag.h"

// TODO: implement 2-arg constructor using constructor delegation and insert

// inserts each element of the bag, separated by spaces, into o, and returns o
ostream& operator <<(ostream& o, const Bag& b) {//override << operator to print bag //链式输出，传参o和b，意思是print bag to o//o 是输出流（如 cout）对象，b 是要输出的 Bag 对象
	size_t n = b.size();//获取袋子的大小
	for (size_t i=0; i<n; i++) {
		o << b[i] << " ";//使用重载的 [] 运算符访问袋子中的每个元素，并将其插入到输出流 o 中，元素之间用空格分隔
	}
	return o;//返回输出流对象，以便支持链式输出
}

// TODO: overload += and +

// TODO: work through the erase_one code below

// searches for first instance of val and moves all subsequent values back
bool Bag::erase_one(int val) {
	bool found = false;
	for (size_t i=0; i<size_; i++) {
		// when val is FIRST found, flip found bool and decrement size
		if (!found && data_[i]==val) {
			found = true;
			size_--;
		}
		// if val has already been found, overwrite current entry with next
		if (found) data_[i] = data_[i+1];
	}
	return found;
}

// TODO: implement erase and count