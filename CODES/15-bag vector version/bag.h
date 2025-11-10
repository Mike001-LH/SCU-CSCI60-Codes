// Interface for templatized dynamic array implementation of Bag.
// Also includes all the implementation normally in the cpp file.
// Sara Krehbiel, class design by Natalie Linnell and Nicholas Tran, 11/3/25

#ifndef BAG_H
#define BAG_H

#include <ostream>
using std::size_t;
using std::ostream;

// INTERFACE

template <typename T>//这里之所以每一段代码都要加一行这个，是因为每一段代码都是独立的文件，编译器在编译每个文件时都需要知道这是一个模板定义，因此每个文件都需要包含 template <typename T> 这一行，以确保模板的正确识别和使用。
class Bag {
public:
  // constructor
  Bag() : size_(0), cap_(0), data_(nullptr) {}

  // dynamic memory management functions
  Bag(const Bag<T>& other); // copy constructor
  ~Bag(); // destructor
  Bag<T>& operator =(const Bag<T>& rhs); // assignment operator

  // mutator
  void insert(T val);
  bool erase_one(T val); // TODO WEDNESDAY: start to implement

  // accessor(s)  
  size_t size() const { return size_; }
  size_t cap() const { return cap_; }
  T operator [](size_t index) const { return data_[index]; } 

private:
  T *data_; // the address associated with a dynamic array
  size_t size_; // how much memory is currently used
  size_t cap_; // how much memory is currently allocated
  // INVARIANTS: data_[0],...,data_[size_-1] always contain the elements; 
  //             cap_ is the smallest power of two at least size_ (or 0)
  // NEW:        cap_=size_=0 or .25*cap_<size_<= cap_
};

// NON-MEMBER FUNCTION DECLARATIONS

template <typename T> // outside class, so need new template prefix//由于在类外定义函数，因此需要新的模板前缀
ostream& operator <<(ostream& out, const Bag<T>& b);


// IMPLEMENTATION

// pre: out is an ostream, b is a well-formed bag
// post: out has the contents of b inserted, b is unchanged
template <typename T> 
ostream& operator <<(ostream& out, const Bag<T>& b) { 
  size_t n=b.size(); // small optimization to avoid multiple function calls
  for (size_t i=0; i<n; i++) {
    out << b[i] << " "; // same as our previous implementations
  }
  return out; 
}

// IMPLEMENTATION

// pre: other is a well-formed bag
// post: *this is a well-formed deep copy of other, which is unchanged
template <typename T>
Bag<T>::Bag(const Bag<T>& other) : cap_(other.cap_), size_(other.size_) {
  data_ = new T[cap_]; // note data_ was garbage before
  for (size_t i=0; i<size_; i++) { // deep copy from other array to new one
    data_[i] = other.data_[i];
  }
}

// pre: *this and rhs are well-formed bags
// post: *this is a deep-copy of other (unchanged), and old memory is released
template <typename T>
Bag<T>& Bag<T>::operator =(const Bag<T>& rhs) {
  if (this==&rhs) return *this; // skip deep copy if rhs is the calling object
  if (cap_!=rhs.cap_) { // only delete and allocated new array if caps differ
    cap_ = rhs.cap_;
    delete [] data_;
    data_ = new T[cap_];
  }
  // deep copy rhs contents into calling object's dynamic array
  size_ = rhs.size_;
  for (size_t i=0; i<size_; i++) {
    data_[i] = rhs.data_[i];
  }
  return *this; // return reference to modified calling object
}

// pre: *this is a well-formed bag
// post: old memory is released and *this is a well-formed empty bag
template <typename T>
Bag<T>::~Bag() {
  delete [] data_; // free memory when pointer is about to pass out of scope
  data_ = nullptr; // don't leave a dangling pointer
  size_ = cap_ = 0; // built-in chained assignment to reset other member vars
}

// pre: a well-formed bag
// post: a well-formed bag with one extra T val in the last spot 
template <typename T>
void Bag<T>::insert(T val) { 
  if (cap_==size_) { // need new bigger array if at capacity
    cap_*=2; // double cap_ variable
    if (cap_==0) cap_=1; // edge case: doubling doesn't work for first insert
    T *temp = new T[cap_]; // allocate new space for bigger array
    for (size_t i=0; i<size_; i++) { // copy old contents into new array
      temp[i] = data_[i];
    }
    delete [] data_; // clean up old array
    data_ = temp; // point object to new array
  }
  data_[size_++] = val; // put new value in next spot of (non-full) array
}

// pre: a well-formed bag
// post: a well-formed bag with the first copy of val removed if present;
//       function returns whether val was present
template <typename T>
bool Bag<T>::erase_one(T val) {
  // WEDNESDAY TODO: start this implementation together
  // HW7 TODO: finish it yourself!  
  
  return false;
}

#endif



//模板定义：
//template <typename T>
//每一段代码都要加一行这个，是因为每一段代码都是独立的文件，编译器在编译每个文件时都需要知道这是一个模板定义，因此每个文件都需要包含 template <typename T> 这一行，以确保模板的正确识别和使用。
//比方说，在一个类的定义中使用了模板，那么在类的实现文件中也需要包含模板定义，以便编译器能够正确地处理模板类的成员函数。
//例如：
/*
* template <typename T>
* class MyClass {
* public:
*  void doSomething(T value);
* };
* 
* template <typename T>
* void MyClass<T>::doSomething(T value) {
*  // implementation
* }
*/


//新知识点：
//Template + Vector Bag vs 普通 Bag
//普通 Bag（固定 int）：
/*
class Bag {
    int *data_;  // 只能是 int，改不了
};

Bag b;
b.insert(10);      // 可以
b.insert("hi");    // 不行！
*/
//Template Bag（支持任何类型）：
/*
template <typename T>
class Bag {
    T *data_;      // 可以是任何类型！
};

Bag<int> b1;
b1.insert(10);     // 可以

Bag<string> b2;
b2.insert("hi");   // 也可以！

Bag<MyClass> b3;   // 还能这样用！
*/

