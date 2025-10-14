// Function definitions for static array implementation of Bag data structure
// Sara Krehbiel, 10/8/25

#include "bag.h"

// constructs bag pre-populated with contents according to array a //被注释掉的是旧版本的2参构造器
/*Bag::Bag(int a[], size_t n) : size_(n)  {
	for (size_t i=0; i<n; i++) {
		data_[i] = a[i];
	}
}*/


// 10:15 section 2-arg constructor initializes empty bag and uses insert
// 调用 0参构造器（构造委托）
/*
Bag() 是内联定义的构造函数；
Bag(int a[], size_t n) : Bag() 表示先调用上面的构造函数，把 size_ 初始化为 0；
然后执行 for 循环插入数组内容。
*/
//新版本的2参构造器不同之处在于：它先调用默认构造器（0参构造器），初始化一个空bag，然后通过insert方法插入数组a的前n个元素
Bag::Bag(int a[], size_t n) : Bag() { // NOTE知识点: constructor delegation!//这里的: Bag()调用了默认构造器，初始化了一个空bag//constructor delegation的意思是构造函数委托,调用另一个构造函数来初始化对象
	//先调用默认构造器，初始化一个空bag，由于Bag():size_(0){}是我们的默认构造器，所以size_被初始化为0
	for (size_t i=0; i<n; i++) {
		insert(a[i]);//调用insert方法插入数组a的前n个元素,insert方法会检查bag是否已满,防止溢出。从而初始化一个有内容的bag
	}
}

// loops through data_, keeping track of and then returning # times val occurs
//作用：计算val在bag中出现的次数
size_t Bag::count(int val) const {
	size_t counter = 0;//计数器，记录val出现的次数，初始值为0
	for (size_t i=0; i<size_; i++) {
		if (data_[i] == val) counter++;//如果data_[i]等于val，计数器加1
	}
	return counter;
}



// inserts each element of the bag, separated by spaces, into o, and returns o
//作用：重载<<运算符，打印bag的内容
ostream& operator <<(ostream& o, const Bag& b) {//ostream& operator是重载运算符，ostream& o是输出流对象，const Bag& b是要打印的bag对象//&的意思是传引用，避免拷贝，提高效率（相当于直接把原本的拿过来用）
	size_t n = b.size();//用b.size()获取bag的大小，赋值给n
	for (size_t i=0; i<n; i++) {
		o << b[i] << " ";//o是输出流对象，所以可以当作cout用，b[i]是bag中第i个元素
	}
	return o;//返回ostream对象，以便支持链式调用，例如cout << b1 << b2;//不然只能打印一个bag
}

// searches for first instance of val and moves all subsequent values back
//作用：删除bag中第一个出现的val
bool Bag::erase_one(int val) {
	bool found = false;//标志变量，表示是否找到val，初始值为false
	for (size_t i = 0; i < size_; i++) {//遍历bag中的每个元素
		// when val is FIRST found, flip found bool and decrement size
		if (!found && data_[i] == val) {//如果找到val且之前没有找到过
			found = true;//将found置为true，表示找到了val
			size_--;//将size_减1，表示bag中元素数量减少了1
		}
		// if val has already been found, overwrite current entry with next
		if (found) data_[i] = data_[i + 1];//如果已经找到了val，将当前元素覆盖为下一个元素，实现删除效果
		//注意：这里没有break，因为要把后面的元素都往前移一位，覆盖掉被删除的元素
		//越界读风险说明：data_[i + 1]在i=size_-1时会越界读，但这是安全的，因为size_已经减1了，data_[size_]是未定义内容，不会被访问到
	}
	return found;//返回是否找到了val
}

// uses erase_one to remove all copies of val and return # removed
//作用：删除bag中所有出现的val，并返回删除的数量
size_t Bag::erase(int val) {
	size_t counter = 0;//计数器，记录删除的val的数量，初始值为0
	while (erase_one(val)) {//调用erase_one函数删除第一个出现的val，直到没有val为止
		counter++;//每删除一个val，计数器加1
	}
	return counter;//返回删除的val的数量
}

// FRIDAY TODO: overload += and +

// add contents of rhs to the data_ array of calling object
//作用：重载+=运算符，将rhs中的内容添加到当前bag中，不改变rhs 
void Bag::operator +=(const Bag& rhs) {
	for (size_t i = 0; i < rhs.size_; i++) {
		//insert(rhs[i]);	//也可以用insert方法插入rhs中的每个元素，但这样会多次检查容量，效率较低
		data_[size_++] = rhs.data_[i];//data_ 与 size_ 是 Bag 的私有成员；成员函数可直接访问它们。//这行代码的作用是将 rhs 中的每个元素依次插入到当前 bag 的 data_ 数组中，并更新 size_。
		//data_[size_++]是左值（left-hand side）,当前（calling object，也就是 lhs）的 data_ 数组中下标为 size_ 的位置
		//rhs.data_[i]是右值（right-hand side）,这个 Bag 中的第 i 个元素//size_++是后置递增运算符，表示先使用当前的 size_ 值，然后再将 size_ 增加 1
	}
}///具体使用说明：
// Bag b1, b2;  b1 += b2;  // 将b2的内容添加到b1中
//编译器会自动把上面↑这行代码翻译成函数调用：b1.operator+=(b2);
//函数定义：void Bag::operator+=(const Bag& rhs) { ... } //编译器在调用时自动代入：lhs 就是 b1，rhs 就是 b2。
//我们之所以这里只写了rhs，是因为lhs是调用该函数的对象，所以隐含地存在于函数内部，可以直接使用。
//lhs和rhs都要写的情况为：Bag operator+(const Bag& lhs, const Bag& rhs) { ... } //因为这个函数不是类的成员函数，所以必须显式地传入两个参数。
//而我们的void Bag::operator+=(const Bag& rhs) { ... }属于类的成员函数，所以只有rhs需要显式传入。
//lhs是调用该函数的对象，隐含地存在于函数内部，可以直接使用。rhs是传入的另一个bag，需要显式传入。

// create and return third bag object with combined contents of lhs and rhs
//作用：重载+运算符，返回一个新的bag，包含lhs和rhs的内容，且不改变lhs和rhs
Bag operator +(const Bag& lhs, const Bag& rhs) {//这是非成员函数，没有 this；因此左右两个操作数都必须显式以参数传入（const Bag& lhs, const Bag& rhs）。
//函数内创建局部对象 sum，先拷 lhs 再拷 rhs 的有效元素到 sum，按值返回（通常触发 RVO/NRVO）；不修改 lhs、rhs。
	Bag sum;//创建一个新的bag对象sum，用于存储lhs和rhs的内容
	size_t n = lhs.size();//获取lhs的大小，赋值给n
	for (size_t i = 0; i < n; i++) {
		sum.insert(lhs[i]);//insert函数将lhs中的每个元素插入到sum中
	}
	n = rhs.size();//获取rhs的大小，赋值给n
	for (size_t i = 0; i < n; i++) {
		sum.insert(rhs[i]);//insert函数将rhs中的每个元素插入到sum中
	}
	return sum;//返回新的bag对象sum
}
//具体使用说明：
// Bag b1, b2;  Bag b3 = b1 + b2;  // 将b1和b2的内容合并到b3中，b1和b2不变//例如b1有{1,2}，b2有{3,4}，则b3有{1,2,3,4}，b1和b2不变
