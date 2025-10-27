// Implementation of GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/24/25

#include "garray.h"

// outputs location and contents of a GArray object//输出GArray对象的位置和内容//输出符号重载函数
ostream& operator <<(ostream& out, const GArray& a) {//out是输出流的引用，任何输出流都可以作为左操作数传进来。a是GArray对象的常量引用，是传入的数组
  out << "(" << a.address() << ") "; // show where the array lives
  for (size_t i=0; i<a.length(); i++) { // output array contents
    out << a[i] << " ";
  }
  return out; // return modified ostream//返回修改后的输出流，以支持链式输出
}

// updates object so data_ addresses larger heap array with new value added//这个函数的作用是将一个新的值插入到动态数组中，并且动态地调整数组的大小以容纳新值
void GArray::insert(int val) {//插入一个整数值val到动态数组中
  int *temp = new int[size_+1]; // allocate space for new bigger array //先在堆上分配一个新的动态数组，大小比原来大1
  for (size_t i=0; i<size_; i++) { // copy contents from old array
    temp[i] = data_[i];//逐个将原数组中的元素复制到新数组中
  }
  //复制完旧数组的内容后，将新值添加到新数组的最后一个位置
  temp[size_++] = val; // add new value//很巧妙的写法，先用size_作为索引插入val，然后size_自增1，这样先保证了插入的位置正确，再更新size_的值//size_++是后缀递增运算符，先使用当前值再增加
  delete[] data_; // does nothing if data_ is nullptr, deallocates otherwise //首先把旧数组释放掉
  data_ = temp; // repoints data_ to the new bigger heap array//然后将data_指向新数组，这样就得到一个包含新值的data_动态数组
} 

// destructor releases dynamic memory for the associated GArray object//析构函数负责释放GArray对象所使用的动态内存
GArray::~GArray() {
  cout << "Destructor: (" << data_ << ")\n";//调试信息，输出当前对象的data_指针地址
  delete[] data_; // avoid orphaning the dynamic array when object leaves scope//在对象生命周期结束时，释放data_指向的动态数组，防止内存泄漏造成孤儿内存
  data_ = nullptr; // avoid leaving object with dangling pointer//将data_指针设为nullptr，防止悬挂指针问题
  size_ = 0; // leave object as well-formed empty array to allow future use//将size_设为0，保持对象处于良好状态，允许未来继续使用
}

// assignment deep copies rhs data into separate dynamic array for calling object//赋值运算符重载（将rhs深拷贝到this中），当一个对象被赋值给另一个对象时调用。
void GArray::operator =(const GArray& rhs) {//rhs是传入的一个数组对象的引用
  cout << "Assignment: (" << data_ << ") <- (" << rhs.data_ << ")\n";//data_是调用对象的data_指针，rhs.data_是传入对象的data_指针//比方说，a = b; 这里的data_就是a的data_，rhs.data_就是b的data_
  size_ = rhs.size_; //复制rhs的size_到调用对象的size_
  //data_ = rhs.data_; // shallow copy (what compiler does without an overload)因为这里直接把指针地址赋值过去了，所以是浅拷贝，会导致两个对象指向同一块内存
  delete[] data_;//现在把原来的data_释放掉，防止内存泄漏
  data_ = new int[size_];//为调用对象分配一个新的动态数组，大小和rhs的size_相同
  for (size_t i=0; i<size_; i++) {
    data_[i] = rhs.data_[i];//逐个将rhs的数据复制到调用对象的data_数组中，实现深拷贝，这样一来就只复制了数据，而不是指针地址
  }
}

// copy constructor constructs new object by deep copying other existing object //拷贝构造函数（将other深拷贝到新对象中），当用一个对象初始化另一个对象时调用。
GArray::GArray(const GArray& other) : GArray() {//传入一个已有的GArray对象other，使用构造函数委托调用默认构造函数初始化新对象
  cout << "Copy constructor: (" << other.data_;//调试信息，输出other的data_指针地址
  size_ = other.size_;//将other的size_复制到新对象的size_
  data_ = new int[size_];//为新对象分配一个新的动态数组，大小和other的size_相同
  cout << ") -> (" << data_ << ")\n";//输出新对象的data_指针地址
  for (size_t i=0; i<size_; i++) {
    data_[i] = other.data_[i];//逐个将传入的other的数据复制到新对象的data_数组中，实现深拷贝
  }
}

// alternative copy constructor uses constructor delegation and =
/*GArray::GArray(const GArray& other) : GArray() {
  cout << "Copy constructor called\n";
  *this = other;
}*/



