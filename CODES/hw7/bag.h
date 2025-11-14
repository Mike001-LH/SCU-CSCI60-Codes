// Interface for templatized dynamic array implementation of Bag.
// Also includes all the implementation normally in the cpp file.
// Sara Krehbiel, class design by Natalie Linnell and Nicholas Tran, 11/3/25

#ifndef BAG_H
#define BAG_H

#include <ostream>
using std::size_t;
using std::ostream;

// INTERFACE

template <typename T>
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
  bool erase_one(T val); // removes first occurrence of val, returns true if found
  size_t erase(T val); // removes all occurrences of val, returns count removed
  size_t erase_fast(T val); // removes all occurrences more efficiently, returns count removed
  Bag<T>& operator +=(const Bag<T>& rhs); // appends all elements from rhs

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

template <typename T> // outside class, so need new template prefix
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
//milestone1 : Finish our implementation of erase_one
//If erase_one decreases the size from 0.25×cap to <= 0.25×cap, you should deep copy the contents of the array(at some sensible point in your implementation!) to a new array with half the capacity of the bag when the function was called.

template <typename T>
bool Bag<T>::erase_one(T val) {
  //return false;
  // WEDNESDAY TODO: start this implementation together
  // HW7 TODO: finish it yourself!  
    for (size_t i = 0; i < size_; i++) {
        if (data_[i] == val) {
            for (size_t j = i; j < size_ - 1; j++) {
                data_[j] = data_[j + 1];
            }
            size_--;

            if (cap_ > 0 && size_ <= cap_ / 4) {//when size_ is less than or equal to one-fourth of cap_, we shrink the capacity,
                //之所以是四分之一，是因为插入时是翻倍的，所以删除时是缩小到一半的四分之一，这样可以保持平衡，防止频繁的扩展和收缩。举个例子：如果当前容量是 8，当元素数量减少到 2（即 8 的四分之一）时，我们就会将容量缩小到 4。
				size_t new_cap = cap_ / 2;//capacity halved
                if (new_cap == 0) new_cap = 1; // 防止缩小到 0
				cap_ = new_cap;
                T* temp = new T[cap_];//在heap上分配新的更小的数组
                for (size_t k = 0; k < size_; k++) {
                    temp[k] = data_[k];//逐个复制元素到新的数组
                }
                delete[] data_;
                data_ = temp;//删除并指向新的数组
            }
            return true;
        }
    }
    return false;
}

//milestone2 : Implement erase.
//The precondition of erase should be that the bag is well-formed
//the post-condition should be that the bag is well-formed with all occurrences of the target value removed and with the number of removed elements returned. 
template <typename T>
size_t Bag<T>::erase(T val) {
	size_t count = 0;
    while (erase_one(val)) {
		count++;
    }
    return count;
}

//Milestone 3: Implement erase_fast.
//The pre- and post-conditions of erase_fast are the same as those of erase, but this implementation will have to be more clever than the one inspired by our previous implementation.
//In particular, you need to write a linear time algorithm, and you may only need only one pass of the bag’s array at most twice for each call to erase_fast.
//Hint: You’ll want to use one of these passes to erase the elements, and once to reallocate and populate a smaller array if needed.
template <typename T>
size_t Bag<T>::erase_fast(T val) {
    size_t count = 0;//the number of element
	size_t write_pos = 0;//the position to write the next non-val element
	//first loop: move element that are not equal to val to the front
    for (size_t i = 0; i < size_; i++) {
        if (data_[i] != val) {
			data_[write_pos++] = data_[i];  // 不是要删的，写到前面,举个例子：data_ = [1,2,3,2,4], val=2,第一次循环后data_=[1,3,4,2,4],write_pos=3 ,2 and 4 are garbage now
        }
        else {
            count++;  // 是要删的，计数+1
        }
    }
	size_ = write_pos;  // 更新新的size //once size_ is updated, the elements beyond size_ are considered garbage and will be ignored in future operations.
	//second loop: shrink the capacity if needed
	if (cap_ > 0 && size_ <= cap_ / 4) {//when size_ is less than or equal to one-fourth of cap_, we shrink the capacity,这是因为插入时是翻倍的，所以删除时是缩小到一半的四分之一，这样可以保持平衡，防止频繁的扩展和收缩。举个例子：如果当前容量是 8，当元素数量减少到 2（即 8 的四分之一）时，我们就会将容量缩小到 4。
		size_t new_cap = cap_ / 2;//capacity halved
		if (new_cap == 0) new_cap = 1;// 防止缩小到 0
		T* temp = new T[new_cap];//在heap上分配新的更小的数组（临时的）
        for (size_t i = 0; i < size_; i++) {
			temp[i] = data_[i];//逐个复制元素到新的数组
        }
		delete[] data_;//删除旧数组并指向新的数组
        data_ = temp;
        cap_ = new_cap;
	}
	return count;
}

//Milestone 4: Overload += as a member function.
//The pre-conditions for += are that the calling object and righthand operand are both well-formed bags,
//and the post-condition is that the calling object has all of the contents of the righthand operand appended to the end.
template <typename T>
Bag<T>& Bag<T>::operator +=(const Bag<T>& rhs) {
    for (size_t i = 0; i < rhs.size(); i++) {
		insert(rhs[i]);//using insert function to add each element from rhs to the calling object(this)
    }
    return *this;
}

#endif
