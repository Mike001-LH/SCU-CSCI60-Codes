#include <iostream>
using namespace std;

template <typename T>
class GArray {
private:
    T* data_;
    size_t size_;
    size_t cap_;
public:
    GArray();                             // TODO 1
    void push_back(const T& item);        // TODO 2: double capacity when full
    size_t size() const;                  // TODO 3
    T& operator[](size_t i);              // TODO 4
    const T& operator[](size_t i) const;  // TODO 5
    ~GArray();                            // TODO 6: delete[]
};
