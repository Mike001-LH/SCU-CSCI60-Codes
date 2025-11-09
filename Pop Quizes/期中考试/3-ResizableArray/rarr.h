/*
3 Resizable Array (15 points)

Below is a modified partial implementation of our GArray class called RArr.
The primary modification is that there is a new member variable cap_ representing the size of the dynamically allocated array,
and the new class invariant allows capacity to be larger than the number of entries in the array.
A new constructor allows for a client to declare an empty RArr object with a pre-allocated array.

Continue developing this class by defining two functions on the following page (both of which must maintain the invariant and not orphan any memory) and then declaring three additional functions in the class below.

Define the insert function declared below.
The logic should be similar to our implementation of insert for GArray in that it moves data from a full dynamic array to a new dynamic array with one additional spot for the new value,
but it should be updated to reflect that now capacity may be larger than size, and in that case no new dynamic array is required.

Define the resize function declared below.
If the new capacity is smaller than the current size, the function should do nothing.
Otherwise, it should copy all the current contents into a new dynamically allocated array with the specified capacity.

Declare but do not define a destructor, copy constructor, and assignment operator.
Write a one-sentence comment for each of these describing why it is necessary and what it should do.
*/
#include <iostream>
using namespace std;

class RArr {
public:
    RArr(size_t cap) : size_(0), cap_(cap), data_(cap == 0 ? nullptr : new int[cap]) {}

    void insert(int val);
    void resize(size_t cap);

	//3, declare destructor, copy constructor, and assignment operator
    ~RArr();                        // Destructor cleans up all the memory on the heap
    RArr(const RArr& other);        // Copy constructor allows deep copy from one to another
    RArr& operator=(const RArr& rhs); // Assignment operator allows redefining existing value

private:
    size_t size_;
    size_t cap_;
    int* data_;

    // INVARIANTS:
    // cap_ >= size_, and data_ addresses a dynamic array of cap_ ints
    // with size_ ints stored in data_[0], ..., data_[size_-1]
};
