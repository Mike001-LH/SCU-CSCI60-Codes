// Driver program to test a templatized Bag class that uses dynamic arrays.
// MONDAY: Implement <<, insert, copy-constructor, assignment, and destructor
// WEDNESDAY TODO: A doubly templatized function; start implementing erase_one
//
// Sara Krehbiel, 11/3/25

#include <iostream>
#include "bag.h"
using namespace std;

int main() {
  // overload << and test 0-arg constructor and size accessor
  Bag<int> b1;
  cout << "Initial bag size: " << b1.size() << endl;//输出： Initial bag size: 0
  cout << "b1 contents: " << b1 << endl; //输出： b1 contents:

  // test insert for Bag
  size_t n = 5;
  cout << "Adding " << n << " 1s to a capacity " << b1.cap() << " bag\n";//输出： Adding 5 1s to a capacity 0 bag
  for (int i = 0; i < n; i++) {//插入5个1
    b1.insert(1); // note: insert for bag plays the role of push_back for vector
    cout << "Capacity " << b1.cap() << " after insertion " << (i+1) << endl;
  }
  /*输出：
  Capacity 1 after insertion 1
  Capacity 2 after insertion 2
  Capacity 4 after insertion 3
  Capacity 4 after insertion 4
  Capacity 8 after insertion 5
  */
  cout << "b1: " << b1 << endl;//输出： b1: 1 1 1 1 1  //PS：这里之所以会输出5个1，是因为我们重载了<<运算符，使其能够正确地输出Bag对象的内容。

  // dynamic memory management tests
  Bag<int> b2(b1); // call copy constructor to construct new bag object//调用拷贝构造函数，用b1初始化b2（）
  cout << "After Bag<int> b2(b1): \b1: " << b1 << "\nb2: " << b2 << endl;
  //输出： After Bag<int> b2(b1):1: 1 1 1 1 1
  //       b2: 1 1 1 1 1
  // 注：
  //\b是退格符，表示将光标向后移动一个位置，但不会删除字符。\n是换行符，表示将光标移动到下一行的开头。//这里由于
  
  // copy constructor should allow us to modify two bags independently
  b2.insert(2);
  cout << "After b2.insert(2): \nb1: " << b1 << "\nb2: " << b2 << endl;
  //After b2.insert(2):
  //b1: 1 1 1 1 1
  //b2: 1 1 1 1 1 2


  b1.insert(3);
  cout << "After b1.insert(3): \nb1: " << b1 << "\nb2: " << b2 << endl;
  //After b1.insert(3):
  //b1: 1 1 1 1 1 3
  //b2: 1 1 1 1 1 2
   
  // assignment operator should, too
  b1 = b2; 
  cout << "After b1 = b2: \nb1: " << b1 << "\nb2: " << b2 << endl;
  //After b1 = b2:
  //b1: 1 1 1 1 1 2
  //b2: 1 1 1 1 1 2

  b2.insert(2);
  cout << "After b2.insert(2): \nb1: " << b1 << "\nb2: " << b2 << endl;
  //After b2.insert(2):
  //b1: 1 1 1 1 1 2
  //b2: 1 1 1 1 1 2 2

  b1.insert(3);
  cout << "After b1.insert(3): \nb1: " << b1 << "\nb2: " << b2 << endl;
  //After b1.insert(3):
  //b1: 1 1 1 1 1 2 3
  //b2: 1 1 1 1 1 2 2

  // NOTE: obj=obj is easy for bag but might cause problems for other classes!//注意：obj=obj对于bag类来说很简单，但对于其他类可能会引起问题！
  b2 = b2; 

  
  // erase_one tests
  cout << "Erasing one 2\n";
  b1.erase_one(2); 
  cout << b1 << endl;//输出： 1 1 1 1 1 3
  
  cout << "Erasing 1s, one-by-one\n";
  for (int i = 0; i < n + 2; i++) {//n是5，所以这里循环7次，之所以是7次，是因为我们想要测试删除1的功能，直到所有的1都被删除为止。b1中最初有5个1和2个其他数字（2和3），所以我们需要尝试删除7次，以确保所有的1都被删除。
    b1.erase_one(1); 
    cout << b1 << endl;
    cout << "Size " << b1.size() << " and capacity " << b1.cap() << endl;
  }
  /*输出：
  1 1 1 1 3
  Size 5 and capacity 8
  1 1 1 3
  Size 4 and capacity 8
  1 1 3
  Size 3 and capacity 8
  1 3
  Size 2 and capacity 4
  3
  Size 1 and capacity 2
  3
  Size 1 and capacity 2
  3
  Size 1 and capacity 2
  */

  // check that everything works for a bag of different template type
  Bag<string> sb;
  sb.insert("hello");
  sb.insert("world");
  cout << "sb: " << sb << endl;//输出： sb: hello world

  // TODO: exercise for doubly templatized functions
  //cout << "b1 is " << ((b1>sb) ? "" : "not ") << "bigger than sb\n";
  
  return 0;
}

