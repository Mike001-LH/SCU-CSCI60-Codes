// Program for CSCI 60 Homework 4; due Wednesday 10/22/25
// Use this homework as a self-quiz. Draw memory diagrams to predict the
// output of the code. Then run it, and either become more confident that 
// you know what's going on, or identify where you need more pointer practice!
//
// Sara Krehbiel, 10/20/25

#include <iostream>

using namespace std;

void sumAndIncrementArray(double& sum, double a[], int size);// increments entries in arr and adds original values to sum (passed-by-ref)
//中文注释：接受一个“数组参数” double a[]，一个int类型的size参数和一个double类型的引用sum参数。将数组a的每个元素加1，并将原来的值加到sum上
double* tripleArray(double* arr, int size);// returns a new array on the heap with each entry tripled
//中文注释：接受一个“指针参数” double* arr，一个int类型的size参数。返回一个新的数组指针，数组中的每个元素都是原数组元素的三倍
double triple(double d);// returns triple the value passed in
//中文注释：接受一个double类型的参数d，返回d的三倍
double* doubleDoubleOnHeap(double d);// returns a pointer to a double on the heap that is double the value passed in
//中文注释：接受一个double类型的参数d，返回一个指向堆内存的指针，指向的值是d的两倍

int main() {
  int a = 3; 
  int *q; 
  q = &a; 
  cout << *q << endl; 
  *q = 5;
  cout << *q << endl; 
  double total = 0, arr[3] = {1.5,2.5,3.5};

  // DIAGRAM 1
  //	[STACK - main（在下）]
  //	q → & a
  //    a : 5
  //    total : 0
  //    arr : [1.5] [2.5] [3.5]
  // q 指向变量 a 的地址，a 的值被修改为 5

  sumAndIncrementArray(total, arr, 3);// increments entries in arr and adds original values to total
  cout << "total=" << total << endl;

  // DIAGRAM 4
  //	[STACK - main（在下）]
  //	q → & a
  //    a : 5
  //    total : 7.5
  //    arr : [2.5] [3.5] [4.5]
  //	q : ──► a
  //	p : (未定义)

  double* p = tripleArray(arr, 3);// returns a new array on the heap with each entry tripled

  // DIAGRAM 7
  //	[STACK - main（在下）]                [HEAP]
  //	q → & a
  //    a : 5  
  //    total : 7.5 
  //    arr : [2.5] [3.5] [4.5]
  //	p	─────→─────→─────→─────→─────→ 	p[0]=7.5 p[1]=10.5 p[2]=13.5

  // p 指向堆上的新数组

  cout << "p contents: "; 
  for (int i = 0; i < 3; i++) cout << *(p + i) << " ";// outputs: 7.5 10.5 13.5
  delete[] p; //删除p在堆上分配的数组内存
  p = nullptr; //将p指针设置为nullptr，表示它不再指向任何有效的内存地址
  double value = 5;//这是为了给triple函数传参准备的变量
  double thrice = triple(value);//调用triple函数，传递value变量的值5，返回15赋值给thrice

  // DIAGRAM 9
  //	[STACK - main（在下）]
  //	q → & a
  //    a : 5
  //    total : 7.5
  //    arr : [2.5] [3.5] [4.5]
  //	p : nullptr
  //	value : 5
  //	thrice : 15
  // triple函数结束，栈帧被销毁

  p = doubleDoubleOnHeap(thrice); //调用doubleDoubleOnHeap函数，传递thrice变量的值15，返回一个指向堆内存的指针p(我们之前设为nullptr的那个)，指向的值是30

  // DIAGRAM 11
  //	[STACK - main（在下）]
  //	q → & a
  //    a : 5
  //    total : 7.5
  //    arr : [2.5] [3.5] [4.5]
  //	p : ─────→─────→─────→─────→─────→ H: (double) 30
  //	value : 5
  //	thrice : 15
  // doubleDoubleOnHeap函数结束，栈帧被销毁
  


  cout << "\np contents: "; 
  for (int i=0; i<3; i++) cout << *(p+i) << " ";
  delete p; 
  p = nullptr; 

  // DIAGRAM 12
  //	[STACK - main（在下）]
  //	q → & a
  //    a : 5
  //    total : 7.5
  //    arr : [2.5] [3.5] [4.5]
  //	p : nullptr
  //	value : 5
  //	thrice : 15
  // 堆内存已被释放，p指针设置为nullptr
  
  return 0;
}

void sumAndIncrementArray(double& sum, double a[], int size) {//作用：接受一个“数组参数” double a[]，一个int类型的size参数和一个double类型的引用sum参数。将数组a的每个元素加1，并将原来的值加到sum上
  double temp = 0;

  // DIAGRAM 2
  //[STACK - sumAndIncrementArray]                     [HEAP]
  //    sum(ref) ───→ 绑定到 main.total               （空）
  //    a       ─────→ 指向 main.arr[0]
  //    size         3
  //    temp         0

  //    [STACK - main（在下）]
  //    q → & a   a : 5  total : 0  arr : [1.5] [2.5] [3.5]

  for (int i=0; i<size; i++) { 
    temp += a[i]++; 
  }

  // DIAGRAM 3
  //[STACK - sumAndIncrementArray]                     [HEAP]
  //    sum(ref) ───→ 绑定到 main.total               （空）
  //    a       ─────→ 指向 main.arr[0]
  //    size         3
  //    temp        7.5
  //	main.arr : [2.5] [3.5] [4.5]
  
  //	[STACK - main（在下）]
  //	q → & a   a : 5  total : 0  arr : [2.5] [3.5] [4.5]

  sum = temp;
}

double* tripleArray(double* arr, int size) {
  double *p = new double[size];

  // DIAGRAM 5
  //[STACK - tripleArray]                     [HEAP]
  //    arr     ─────→ 指向 main.arr[0]       
  //    size         3                        [未初始化的 double 数组]
  //	p	─────→─────→─────→─────→─────→	p[0]p[1]p[2]
  //
  //	[STACK - main（在下）]
  //	q → & a   a : 5  total : 7.5  arr : [2.5] [3.5] [4.5]

  for (int i=0; i<size; i++) {
    p[i]=3*arr[i];
  }

  // DIAGRAM 6 
  //[STACK - tripleArray]                     [HEAP]
  //    arr     ─────→ 指向 main.arr[0]
  //    size         3                        [已初始化的 double 数组]
  //	p	─────→─────→─────→─────→─────→ 	p[0]=7.5 p[1]=10.5 p[2]=13.5
  //
  //	[STACK - main（在下）]
  //	q → & a   a : 5  total : 7.5 arr : [2.5] [3.5] [4.5]
  return p;
}

double triple(double d) {
  double temp = 3*d;

  // DIAGRAM 8 
  //[STACK - triple]                     [HEAP]
  //    d         （传入值）5
  //    temp      3*5=15

  //	[STACK - main（在下）]
  //	q → & a
  //    a : 5  
  //    total : 7.5 
  //    arr : [2.5] [3.5] [4.5]
  //	p : nullptr
  //	value : 5
  //	thrice : (待接收，会是15)

  return temp;
}

double* doubleDoubleOnHeap(double d) {
  double *ptr = new double;
  *ptr = d*2;

  // DIAGRAM 10
  //[STACK - doubleDoubleOnHeap]                     [HEAP]
  //    d         （传入值）15                     
  //    ptr    ─────→─────→─────→─────→─────→─────→ H: (double) 30
  //
  //	[STACK - main（在下）]
  //	q → & a
  //    a : 5
  //    total : 7.5
  //    arr : [2.5] [3.5] [4.5]
  //	p : (待接收，会指向 H)//指向ptr所指向的堆内存
  //	value : 5
  //	thrice : 15
  // doubleDoubleOnHeap函数结束，栈帧被销毁

  return ptr;
}