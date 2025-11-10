#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Box {
private:
    T value_;
public:
    Box();                // TODO 1: initialize value_ with default value
    Box(T v);             // TODO 2: initialize value_ with v
    T getValue() const;   // TODO 3
    void setValue(T v);   // TODO 4
    void print() const;   // TODO 5
};

int main() {
    Box<int> b1(42);
    Box<string> b2("hello");
    b1.print();   // Box: 42
    b2.print();   // Box: hello
}
