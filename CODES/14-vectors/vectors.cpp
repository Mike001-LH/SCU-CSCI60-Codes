// Tasks: Learn the basics of vectors from the standard template library.
// Sara Krehbiel, 10/29/25

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// outputs vector<T> contents, assuming T is insertable
template <typename T>//template是一个关键字，表示接下来定义的是一个模板，typename T表示定义了一个类型参数T，可以在模板中使用
ostream& operator <<(ostream& out, const vector<T>& v) {// overload << for vector//传入一个ostream引用和一个vector引用
  for (size_t i=0; i<v.size(); i++) {
	  out << v[i] << " "; // assumes T has << overloaded //使用下标运算符访问vector的元素，并将其插入到输出流中，逐个输出元素
  }
  return out;
}

int main() {
  // declare an empty vector and insert 4 elements using push_back 
  // note how size and capacity change!
  vector<double> v; // 1. Define the 0-arg bag constructor inline
  cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;//输出：size: 0, capacity: 0
  v.push_back(3); //插入元素3到vector的末尾
  cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;//输出：size: 1, capacity: 1
  v.push_back(6);
  cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;//输出：size: 2, capacity: 2
  v.push_back(4);
  cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;//输出：size: 3, capacity: 4
  v.push_back(4);
  cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;//输出：size: 4, capacity: 4
  v.push_back(12);
  // 2. Declare insert for bag

  cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;//输出：size: 5, capacity: 8
  // 3. Define corresponding bag accessors inline

  //exit(0); // same as return 0; nice for demos!

  // output contents
  for (size_t i=0; i<v.size(); i++) {
    cout << v[i] << " "; // 4. Overload [] for bag
  }
  cout << endl;

  cout << v << endl; // 5. Note that << wasn't automatically overloaded! 
  // 6. Can we make it work for bag?

  //exit(0);

  // 7. Why can't we similarly modify bag using array-style syntax?
  v[2] = 12; // replace the first 4 with a 12
  v[5] = 42; // 8. Describe the memory diagram here

  cout << v << endl;
  

  // you might be allowed to read/write out of bounds, but you shouldn't do it!
  cout << "out of bounds access with []: " << v[5] << endl;

  //exit(0);
  
  try { // accessing with at vs [] will throw an out of bounds exception
    cout << "in bounds access with at: " << v.at(2) << endl;//v.at(2)访问index为2的元素，也就是第三个元素
	cout << "out of bounds access with at: " << v.at(5) << endl;//v.at(5)尝试访问index为5的元素，但由于vector只有5个元素（索引0到4），所以会抛出异常，因此下面的catch块会被执行，此外这一行不会被执行
    // 9. Declare at for bag and compare it to documentation for vector
  } catch (exception e) { // catch block executes if try block throws exception
    cout << "vector member function \"at\" threw out-of-bounds exception!\n";//捕获上面尝试访问index为5的元素异常并输出提示信息
  }

  exit(0); // We didn't talk about anything in class 10/29 after this point!
  //exit的作用是立即终止程序的执行，并返回一个状态码给操作系统。在这个例子中，exit(0)表示程序正常结束，状态码0通常表示没有错误发生。

  cout << "Sorting v:";
  sort(v.begin(), v.end()); // 10. Is this a member function? Declare it!//这是一个非成员函数，定义在<algorithm>头文件中，用于对容器中的元素进行排序，v是一个vector对象，v.begin()返回指向vector第一个元素的迭代器，v.end()返回指向vector最后一个元素之后位置的迭代器，sort函数会对这两个迭代器范围内的元素进行排序
  // range-based for loop can be used with explicit or auto type declaration
  for (int elem : v)//遍历vector v中的每个元素，并将其赋值给变量elem
    cout << elem << " ";//输出每个元素，元素之间用空格分隔
  cout << endl;

  exit(0);

  vector<double> v2(5); //新建了一个包含5个double类型元素的vector v2，初始值为默认值0.0
  v2[3] = 17.5;
  // 11. Guess what the next block of code outputs -- look into documentation!
  for (auto e : v2) { // auto type declaration for range-based for loops //auto的作用是让编译器自动推断变量的类型，在这个例子中，e的类型会被推断为vector<double>中的元素类型double
    cout << e << " ";//遍历vector v2中的每个元素，并将其赋值给变量e，然后输出每个元素，元素之间用空格分隔
  }
  cout << endl;

  exit(0);

  // 12. Guess the size and capacity
  cout << "size: " << v2.size() << ", capacity: " << v2.capacity() << endl;//输出：size: 5, capacity: 5

  // can initialize explicitly similarly to array notation (with or without =)
  vector<string> v3 {"Happy", "families", "are", "all", "alike;",
    "every", "unhappy", "family", "is", "unhappy", "in", "its", "own", "way."};

  // iterators are like pointers that know where the collection begins and ends
  cout << "v3 using an iterator:\n";
  for (vector<string>::iterator it = v3.begin(); it < v3.end(); it++) {//定义了一个迭代器it，指向vector v3的第一个元素，然后通过循环遍历v3中的每个元素，直到it达到v3的末尾，此外vector<string>::iterator的意思是定义了一个指向string类型元素的vector的迭代器类型，这里的::是作用域解析运算符，表示iterator是vector<string>类的一个成员类型, iterator是一种特殊的指针类型，可以用来遍历容器中的元素，it则是一个具体的迭代器对象，初始时指向v3的第一个元素
	  //此外，begin和end是vector类的成员函数，begin返回一个指向第一个元素的迭代器，end返回一个指向最后一个元素之后位置的迭代器
    cout << *it << " ";
  }
  cout << endl;
  // reverse_iterators are what they sound like!
  cout << "v3 using a reverse iterator:\n";
  for (vector<string>::reverse_iterator it = v3.rbegin(); it < v3.rend(); it++) {//定义了一个反向迭代器it，指向vector v3的最后一个元素，然后通过循环遍历v3中的每个元素，直到it达到v3的开头，此外vector<string>::reverse_iterator的意思是定义了一个指向string类型元素的vector的反向迭代器类型，这里的::是作用域解析运算符，表示reverse_iterator是vector<string>类的一个成员类型, reverse_iterator是一种特殊的指针类型，可以用来反向遍历容器中的元素，it则是一个具体的反向迭代器对象，初始时指向v3的最后一个元素
	  //此外，rbegin和rend是vector类的成员函数，rbegin返回一个指向最后一个元素的反向迭代器，rend返回一个指向第一个元素之前位置的反向迭代器
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}


//新知识点：
//1. Vector 是 C++ 标准模板库（STL）中的一个动态数组，可以根据需要自动调整大小。类似java中的ArrayList。
//2. 头文件 #include <vector> 用于包含 Vector 类的定义
//3. 定义 Vector：使用 vector<T> 来定义一个存储类型
//   例如：vector<int> vec; // 定义一个存储整数的 Vector
//4. 常用操作：
//   - push_back(value)：在 Vector 末尾添加一个元素
//   - size()：返回 Vector 中当前元素的数量
//   - capacity()：返回 Vector 当前分配的存储空间大小
//   - at(index)：访问指定索引处的元素，并进行边界检查
//   - [] 运算符：访问指定索引处的元素，但不进行边界检查
//5. 迭代器：Vector 支持迭代器，可以使用 begin
//   和 end() 方法获取指向第一个元素和最后一个元素之后位置的迭代器
//6. 排序：可以使用标准库中的 sort() 函数对 Vector
//   进行排序，传入 begin() 和 end() 迭代器作为参数
//7. 范围基 for 循环：可以使用范围基 for 循环遍历 Vector 中的元素
//   例如：for (const auto& elem : vec) { /* 使用 elem */ }
//8. 自动类型推断：使用 auto 关键字让编译器自动推断变量类型
//   例如：for (auto elem : vec) { /* 使用 elem */ }
//9. 异常处理：使用 try-catch 块捕获访问越界时抛出的异常，例如使用 at() 方法访问元素
//例如：
/*
try {
  cout << v.at(5) << endl;
} catch (const out_of_range& e) {
  cerr << "Caught out_of_range exception: " << e.what() << endl;
}
*/
//10. Vector 的容量（capacity）会根据需要自动增长，通常是当前容量的 1.5 倍
//11. 可以使用初始化列表来初始化 Vector，例如：vector<string> vec = {"Hello", "World"};
//12. Vector 的大小（size）和容量（capacity）是不同的概念，size 是当前存储的元素数量，而 capacity 是分配的存储空间大小
//例如：
/*
* vector<int> vec;
* vec.push_back(1);
* cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity
* << endl; // 输出 Size: 1, Capacity: 1
* vec.push_back(2);
* cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity
* << endl; // 输出 Size: 2, Capacity: 2
* vec.push_back(3);
* cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity
* << endl; // 输出 Size: 3, Capacity: 4
* vec.push_back(4);
* cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity
* << endl; // 输出 Size: 4, Capacity: 4
* vec.push_back(5);
* cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity
* << endl; // 输出 Size: 5, Capacity: 8
* */
//由此可见，一旦 Vector 的大小超过当前容量，容量会自动增长以适应新的元素数量。
//总结：Vector 是 C++ 中非常有用的动态数组容器，提供了丰富的功能和灵活性，适用于需要动态调整大小的场景。
//sort(v.begin(), v.end());//这一句的意思是：对 vector v 中的元素进行排序，v.begin()是指向 vector 第一个元素的迭代器，v.end()是指向 vector 最后一个元素之后位置的迭代器，sort 函数会对这两个迭代器范围内的元素进行排序。
//13.vector也可以这么初始化：
//vector<string> v3 {"Happy", "families", "are", "all", "alike;","every", "unhappy", "family", "is", "unhappy", "in", "its", "own", "way."};
//14. 迭代器（Iterator）是一种对象，提供了一种访问容器中元素的统一方式，而不需要了解容器的底层实现细节。迭代器类似于指针，可以用来遍历容器中的元素。
// 例子：
//ps：iterator是c++本身就有的一个类型，不需要自己定义，而it则是我们自己定义的一个迭代器变量，用于遍历vector容器中的元素。
/*
* for (vector<string>::iterator it = v3.begin(); it < v3.end(); it++) {
*   cout << *it << " ";
* }
* cout << endl;
*/
//15. 反向迭代器（Reverse Iterator）是一种特殊类型的迭代器，用于反向遍历容器中的元素。与普通迭代器不同，反向迭代器从容器的末尾开始，向前移动，直到到达容器的开头。
// 例子：
//ps：reverse_iterator是c++本身就有的一个类型，不需要自己定义，而it则是我们自己定义的一个反向迭代器变量，用于反向遍历vector容器中的元素。
/*
* for (vector<string>::reverse_iterator it = v3.rbegin(); it < v3.rend(); it++) {
*   cout << *it << " ";
* }
* cout << endl;
*/