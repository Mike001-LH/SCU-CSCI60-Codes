// Implementation of GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/22/25

#include "garray.h"

// updates object so data_ addresses larger heap array with new value added//插入一个新的稍微大一点的动态数组
void GArray::insert(int val) {
  int* temp = new int[size_ + 1]; // allocate space for new bigger array//首先先在heap上分配一个新的更大的动态数组（内存+1）
  for (size_t i = 0; i < size_; i++) { //把老动态数组的内容逐个复制到新的动态数组中
    temp[i] = data_[i];
  }
  temp[size_++] = val; // 这里把传入的val新增值放到新动态数组的最后一个位置，并且size_自增1
  //比方说：原来size_=3，新增一个val后，size_变成4，val放在temp[3]位置
  //这里用到了后置++运算符，是先用size_的当前值插入val，然后再把size_加1，这样就正确地更新了动态数组的大小
  delete[] data_; //释放原来data_指向的动态数组内存，防止原本data_指向的内存变成孤儿内存，但如果data_是nullptr则什么都不做
  data_ = temp; //把data_指向新的更大的动态数组，也就是我们刚刚创建的temp动态数组，更新data_指针，这样对象现在就引用了新的动态数组，完成插入操作
} 

// outputs location and contents of a GArray object//输出GArray对象的位置和内容
ostream& operator <<(ostream& out, const GArray& a) {//重载插入运算符，用于输出GArray对象的信息，传入ostream引用和GArray对象的常量引用，返回ostream引用
	//out是输出流对象，类似cout，a是要输出的GArray对象，是一个常量引用，表示函数不会修改a对象，a是动态数组对象//此外，之所以返回ostream引用，是为了支持链式调用，比如cout << a << b;
  out << "(" << a.address() << ") "; // output address of array//输出动态数组的地址
  for (size_t i=0; i<a.length(); i++) { // output array contents//输出动态数组内容
	  out << a[i] << " ";//输出动态数组中每个元素的值，使用重载的[]运算符访问元素
  }
  return out; // return modified ostream//返回修改后的输出流对象
}
/*机制示意：
cout << a << b;
         ↓
Step 1: operator<<(cout, a)
         输出 a
         返回 cout 的引用
         ↓
Step 2: operator<<(cout, b)
         输出 b
         返回 cout 的引用
         ↓
Step 3: cout.flush()
         输出完成
*/

// destructor releases dynamic memory for the associated GArray object//析构函数（destructor）释放与GArray对象关联的动态内存
GArray::~GArray() {
  cout << "Destructor called!\n";//析构函数（destructor）被调用时输出提示信息，方便调试和跟踪对象生命周期
  delete[] data_; // avoid orphaning the dynamic array when object leaves scope//释放data_指向的动态数组内存，防止内存泄漏导致的孤儿内存
  data_ = nullptr; // TODO: discuss why is this useful//将data_指针设置为nullptr，防止悬空指针问题，确保指针不再指向已释放的内存
  // TODO: discuss what other step should be added
}
//知识点讲解：
//1. 析构函数（destructor）的作用：析构函数是在对象生命周期结束时自动调用的特殊成员函数，主要用于释放对象在堆上分配的动态内存，防止内存泄漏。
//需要注意的是，析构函数不接受参数，也没有返回值，其名称与类名相同，但前面加上波浪号（~）。
//里面需要用delete或delete[]来释放动态分配的内存。然后将指针设置为nullptr，可以防止悬空指针问题，确保指针不再指向已释放的内存，从而避免潜在的未定义行为。

// FRIDAY TODO: recap/polish destructor and implement = and copy constructor