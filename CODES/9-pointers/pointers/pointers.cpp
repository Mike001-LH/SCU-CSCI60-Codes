// Several functions demonstrating use of pointers, separated into 4 lessons: 
// 1. Examples of using & to access variables' addresses, 
//    using * to declare variables of pointer type, and 
//    using * to dereference pointers (access the values they point to). 
// 2. Learn about pointer arithmetic and how to use arrays as pointers. 
// 3. Practice memory diagrams for pass-by-reference and pass-by-pointer.
// 4. Learn how to use new and delete with pointers to access heap memory.
//
// Most of the code in this program is output to the console and several calls
// to a utility function waitForUser() effectively pauses execution so main,
// which is separated into four lessons divided by helper functions, can be run/
// presented like a slideshow.
//
// Sara Krehbiel, 10/15/25-10/17/25
//先提前说一下，&是取地址符号，*有两种用法，一种是声明指针变量时使用，表示该变量是一个指针（地址），另一种是解引用指针变量时使用，表示取出指针变量指向的地址中存储的值
//&一方面可以用于引用传参（意思是：可以直接修改传入的变量），另一方面可以用于取变量的地址（从值取出地址）
//*则一方面可以用于声明指针变量（意思是：该变量存储的是一个地址），另一方面可以用于解引用指针变量（从地址取出值）
//注意：在引用传参中，&表示引用符号，可以直接修改传入的变量，而在取地址时，&表示取地址符号，输出的是变量的地址
//题外话1：其实还有指针传参，就是传递变量的地址，然后在函数体内通过解引用来修改变量的值，这种方式比较麻烦，一般不推荐使用，建议使用引用传参
//题外话2: 在C++中，数组名本身就是一个指向数组第一个元素的指针，所以可以使用指针运算来访问数组元素
//题外话3: 在C++中，要管理好指针，避免内存泄露，new和delete用于动态内存分配，new用于在堆上分配内存，delete用于释放堆上的内存，避免内存泄漏。
//具体而言之，使用new分配的内存必须使用delete释放，否则会导致内存泄漏，影响程序性能和稳定性，举个代码例子：int* p = new int(5); // 分配内存    delete p; // 释放内存
//题外话4: 指针运算时要注意类型匹配，避免类型不兼容导致的错误，比方说，不能将double类型的指针赋值给int类型的指针
//题外话5: 指针和引用的使用需要谨慎，避免出现悬空指针、野指针等问题，导致程序崩溃或不可预期的行为
//知识点：arithmetic指的是算术运算，pointer arithmetic指的是指针运算，即对指针进行加减操作，比如指针加减一个整数，表示指针向后或向前移动若干个元素的地址
//观前提示：本代码主要用于教学目的，演示C++中指针的基本用法和概念，适合初学者学习和理解指针的工作原理，另外我代码里面批注的地址都是示例地址，实际运行时地址会有所不同

#include <iostream>

using namespace std;

void waitForUser(); // utility function used throughout to stall the program//中文注释：这个函数用于暂停程序执行，等待用户输入，会在终端输出"Continue (y/n)? "，用户输入y继续，输入n退出程序

void pointersToLocalVariables(); // Lesson 1
void staticArraysAsPointers(); // Lesson 2
void passByRefVsPassByPointer(); // Lesson 3
void usingTheHeap(); // Lesson 4

// can run these four functions sequentially or individually
int main() {
  //pointersToLocalVariables(); 
  staticArraysAsPointers();
  //passByRefVsPassByPointer(); 
  //usingTheHeap();
}

// 1. Using & and * for accessing addresses and using pointers on the stack //第一节课：使用&和*来访问地址以及在栈上使用指针
void pointersToLocalVariables() {
  cout << "\nLESSON 1: Using & and * for pointers on and to the stack\n\n";
  int ignore;

  // ACCESSING THE ADDRESS OF YOUR VARIABLES:
  cout << "& gets the address of a variable:\n";

  int a = 2;
  double b = 3.5;
  int c = 4;

  {
    cout << "\nint a = 2;\ndouble b = 3.5;\nint c = 4;\n\n";
  } // braces used here only to suppress couts of code

  cout << "a: " << a << endl;//a: 2
  cout << "b: " << b << endl;//b: 3.5
  cout << "c: " << c << endl;//c: 4

  /* T1：声明 a,b,c 之后
  # function: pointersToLocalVariables     （高地址在上，低地址在下）
┌──────────────────────────────────────────────┐
│ a : int    = 2        (&a = 0x7ffffcc08)     │
│ b : double = 3.5      (&b = 0x7ffffcc00)     │
│ c : int    = 4        (&c = 0x7ffffcbfc)     │
└──────────────────────────────────────────────┘
↑ higher addrs                                           lower addrs ↓
  */
  //注意，之前我们讲过&作为引用符号使用，在引用传参中可以直接使用并修改传进来的值，但这里是取地址符号，输出的是变量的地址

  // note: the first variables go on the bottom of the stack
  //       and the smallest addresses are on top
  cout << "&a: " << &a << endl; //&a: 0x7ffffcc08 //&的意思是取a的地址
  cout << "&b: " << &b << endl; //&b: 0x7ffffcc00
  cout << "&c: " << &c << endl; //&c: 0x7ffffcbfc
  
  cout << "\nsizeof(a)=" << sizeof(a) << "; sizeof(b)=" << sizeof(b) << endl;//sizeof是c++自带的函数，返回变量所占内存大小，单位是字节byte
  //sizeof(a)=4; sizeof(b)=8
  //输出结果是4和8，说明int类型变量a占4个字节，double类型变量b占8个字节。

  waitForUser();//暂停程序，等待用户输入。会在终端输出"Continue (y/n)? "，用户输入y继续，输入n退出程序

  // DECLARING POINTER VARIABLES:
  cout << "* modifies type so int *p holds an address of an int:\n";
  //注意：这里的*是用来声明指针变量的，int *p表示p是一个指向int类型变量的指针
  //*a是从地址中取值，因为a是一个指针变量，而指针其实存储的是一个地址。而&a是取变量a的地址，a是一个值，与*a完全相反

  double* bptr = &b; // This spacing is allowed but ill-advised
  //上面这行这么写*是允许的，但这么写并不明智，建议写成double *bptr=&b;因为* binds to the variable, not int or double
  int *aptr = &a, *cptr = &c, d = 7; // Note: * binds to the variable, not int
  //bptr = &c; // ERROR: incompatible types, cannot assign double* to int*
  //&a = aptr; // ERROR: &a is an r-value; can't reassign where variables live//意思是不能将aptr赋值给&a，因为&a是一个右值，不能被重新赋值，因为右值表示一个临时的值，不能被修改
               // Analogous to f.getDenom() = 4 vs  int d = f.getDenom()

  {
    cout << "\ndouble* bptr = &b;\nint *aptr = &a, *cptr = &c, d = 7;\n\n";
  }

  /*T2：建立指针后
┌────────────────────────────────────────────────────────────┐
│ a : int    = 2          (&a    = 0x7ffffcc08)              │
│ b : double = 3.5        (&b    = 0x7ffffcc00)              │
│ c : int    = 4          (&c    = 0x7ffffcbfc)              │
│ d : int    = 7                                             │
│                                                            │
│ aptr : int*    = (&a)0x7ffffcc08  (&aptr = 0x7ffffcbe8)  ─┐    │
│ bptr : double* = (&b)0x7ffffcc00  (&bptr = 0x7ffffcbf0)  ─┼─→ b │
│ cptr : int*    = (&c)0x7ffffcbfc  (&cptr = 0x7ffffcbe0)  ─┘    │
└────────────────────────────────────────────────────────────┘
  */

  //由于指针变量存储的是地址，所以aptr, bptr, cptr存储的分别是变量a, b, c的地址，又因为指针变量本身也是变量，所以它们也有自己的地址，另外对指针用*来解引用可以取出他们指向的变量的值
  //aptr 存的是别人的地址，&aptr 是它自己的地址。
  cout << "aptr: " << aptr << endl;//输出的是变量a的地址//aptr: 0x7ffffcc08
  cout << "bptr: " << bptr << endl;//输出的是变量b的地址//bptr: 0x7ffffcc00
  cout << "cptr: " << cptr << endl;//输出的是变量c的地址//cptr: 0x7ffffcbfc

  cout << "&aptr: " << &aptr << endl;//输出的是指针变量aptr本身的地址//&aptr: 0x7ffffcbf0
  cout << "&bptr: " << &bptr << endl;//输出的是指针变量bptr本身的地址//&bptr: 0x7ffffcbf8
  cout << "&cptr: " << &cptr << endl;//输出的是指针变量cptr本身的地址//&cptr: 0x7ffffcc10

  cout << "\nsizeof(aptr)=" << sizeof(aptr) << "; sizeof(bptr)=" << sizeof(bptr) << endl;//sizeof(aptr)=8; sizeof(bptr)=8

  waitForUser();//暂停程序，等待用户输入。会在终端输出"Continue (y/n)? "，用户输入y继续，输入n退出程序

  // DEREFERENCING POINTERS://中文注释：解引用指针
  cout << "* gets the value that an already-initialized pointer addresses:\n\n";//注意：这里的*是用来解引用指针变量的，取出指针变量指向的地址中存储的值

  cout << "*aptr: " << *aptr << endl; //输出的是变量a的值//*aptr: 2
  cout << "*bptr: " << *bptr << endl; //输出的是变量b的值//*bptr: 3.5
  cout << "*cptr: " << *cptr << endl; //输出的是变量c的值//*cptr: 4

  waitForUser();//暂停程序，等待用户输入。会在终端输出"Continue (y/n)? "，用户输入y继续，输入n退出程序

  // USING ADDRESS AND DEREFERENCING OPERATORS IN ASSIGNMENT //中文注释：在赋值中使用取地址和解引用操作符
  cout << "As variables, pointers can be reassigned:\n";//注意：指针变量本身也是变量，可以被重新赋值，改变它指向的地址

  c = *aptr;//将c的值改为aptr指向的地址中存储的值，即变量a的值2
  c++;//将c的值加1，即c变为3
  cptr = aptr;//将cptr指向aptr指向的地址，即变量a的地址
  aptr = &c;//将aptr指向变量c的地址
  *bptr *= 3; // If b has value 3.5, this is the same as *bptr = 10.5;//因为3.5*3=10.5
  //*aptr = 12; // reassigns the value of the thing aptr points to (here c)
  //a = &c; // ERROR: a points to an int, not an int pointer//不能将变量c的地址赋值给变量a，因为a是一个int类型变量，不能存储地址


  /*T3：执行重定向与修改后
┌────────────────────────────────────────────────────────────┐
│ a : int    = 2          (&a    = 0x7ffffcc08)              │
│ b : double = 10.5       (&b    = 0x7ffffcc00)              │
│ c : int    = 3          (&c    = 0x7ffffcbfc)              │
│                                                            │
│ aptr : int*    = 0x7ffffcbfc  (&aptr = 0x7ffffcbe8)  ─→ c  │
│ bptr : double* = 0x7ffffcc00  (&bptr = 0x7ffffcbf0)  ─→ b  │
│ cptr : int*    = 0x7ffffcc08  (&cptr = 0x7ffffcbe0)  ─→ a  │
└────────────────────────────────────────────────────────────┘
# 解引用验证：*aptr=3, *bptr=10.5, *cptr=2
  */

  {
    cout << "\nc = *aptr;\nc++;\ncptr = aptr;\naptr = &c;\n*bptr *= 3;\n";//
    cout << "\nDraw memory diagrams to trace the effect of this!\n";
    waitForUser();
  }

  cout << "Note that the addresses of local variables never change,\n\n";//虽然指针指向的地址改变了，但指针变量自己的地址没有变

  cout << "&a: " << &a << endl;//输出：&a: 0x7ffffcc08
  cout << "&b: " << &b << endl;//输出：&b: 0x7ffffcc00
  cout << "&c: " << &c << endl;//输出：&c: 0x7ffffcbfc
  cout << "&aptr: " << &aptr << endl;//输出：&aptr: 0x7ffffcbe8
  cout << "&bptr: " << &bptr << endl;//输出：&bptr: 0x7ffffcbf0
  cout << "&cptr: " << &cptr << endl;//输出：&cptr: 0x7ffffcbe0

  waitForUser();

  cout << "but you can update values, including where pointers point,\n\n";//指针变量指向的地址可以改变
  cout << "a: " << a << endl;//输出：a: 2
  cout << "b: " << b << endl;//输出：b: 10.5
  cout << "c: " << c << endl;//输出：c: 3
  cout << "aptr: " << aptr << endl;//输出：aptr: 0x7ffffcbfc//现在指向变量c的地址
  cout << "bptr: " << bptr << endl;//输出：bptr: 0x7ffffcc00//仍然指向变量b的地址
  cout << "cptr: " << cptr << endl;//输出：cptr: 0x7ffffcc08//现在指向变量a的地址

  waitForUser();
  
  cout << "and value updates are reflected when you dereference pointers.\n\n";//解引用指针变量可以取出它们指向的地址中存储的值，这些值会随着指针指向的地址改变而改变
  cout << "*aptr: " << *aptr << endl;//输出：*aptr: 3 //现在aptr指向变量c，*aptr取出的是变量c的值3
  cout << "*bptr: " << *bptr << endl;//输出：*bptr: 10.5 //bptr仍然指向变量b，*bptr取出的是变量b的值10.5
  cout << "*cptr: " << *cptr << endl;//输出：*cptr: 2 //现在cptr指向变量a，*cptr取出的是变量a的值2

  cout << "\nEND OF LESSON 1.\n";
}

// 2. Arrays as pointers //第二节课：数组作为指针
void staticArraysAsPointers() {
  cout << "\nLESSON 2: Understanding (static) arrays as pointers\n\n";//静态数组是指在编译时就确定大小的数组，通常分配在栈上

  cout << "If you cout an array, it looks like an address,\n\n";//注意：数组名本身就是一个指向数组第一个元素的指针

  double a[] = { 1.5, 2.5, 3.5 };//数组a有3个double类型的元素，分别是1.5, 2.5, 3.5

  {
    cout << "double a[] = {1.5, 2.5, 3.5};\n\n"; 
  }

  cout << "a: " << a << endl; //输出的是数组a第一个元素的地址//a: 0x7ffee3b8c9c0 

  waitForUser();

  cout << "because arrays ARE pointers!\n\n";//注意：数组名本身就是一个指向数组第一个元素的指针//数组本身就是一个指针

  double *p = a; //将指针p指向数组a的第一个元素的地址

  {
    cout << "double *p = a;\n\n";
  }

  cout << "p: " << p << "\n"; //输出的是数组a第一个元素的地址//p: 0x7ffee3b8c9c0

  waitForUser();

  cout << "An array's value is its address, pointing to its first element:\n\n";//中文：数组的值就是它的地址，指向它的第一个元素

  cout << "a:  " << a << endl;//输出的是数组a第一个元素的地址//a: 0x7ffee3b8c9c0
  cout << "&a: " << &a << endl; //输出的是数组a的地址//&a: 0x7ffee3b8c9c0
  //注意：a和&a的值是一样的，都是数组a第一个元素的地址，但类型不同，a是数组首元素的地址，类型是double*，表示指向double类型变量的指针，
  // 而&a是整个数组对象本身的地址，类型是double (*)[3]，表示指向包含3个double类型元素的数组的指针
  cout << "*a: " << *a << endl;//输出的是数组a第一个元素的值//*a: 1.5
  cout << "p:  " << p << endl; //输出的是指针p的值，即数组a第一个元素的地址//p: 0x7ffee3b8c9c0
  cout << "&p: " << &p << endl; //输出的是指针p自己本身的地址//&p: 0x7ffee3b8c9c0
  cout << "*p: " << *p << endl; //输出的是指针p指向的值，即数组a第一个元素的值//*p: 1.5

  //double *q = &a; // ERROR: a and &a have the same value but different types//因为a是一个double类型的指针，&a是一个指向数组的指针，两者类型不同，不能赋值
  //&a的类型是double (*)[3]，表示指向包含3个double类型元素的数组的指针，而a的类型是double*，表示指向double类型变量的指针
  //double *q = &(a[0]); // This would be OK, 因为a[0]是数组a的第一个元素，&(a[0])是第一个元素的地址，类型是double*，与q的类型匹配
  //cout << q << endl << *q << endl; //输出的是数组a第一个元素的地址和数组a第一个元素的值

  waitForUser();

  cout << "Differentiated pointer types enable pointer arithmetic:\n\n";//知识点：arithmetic指的是算术运算，pointer arithmetic指的是指针运算，即对指针进行加减操作

  double *last = p + 2; // points to the last element of a
  //因为p是第一个元素的地址，p+2表示指针p向后移动2个double类型的元素的地址，即指向数组a的第三个元素的地址
  double* onePast = p + 3; // NOTE: No warning, despite being out of bounds 
  //p+3表示指针p向后移动3个double类型的元素的地址，即指向数组a的第四个元素的地址，但数组a只有3个元素，所以这个地址是越界的，但编译器不会报错
  /*
┌──────────────────────────  staticArraysAsPointers 栈帧  ──────────────────────────┐
│ onePast ─────────────────────────────► 0x…A8   （a 之后一位，禁止解引用）           │
│ last    ─────────────────────────────► 0x…A0   （→ a[2]）                         │
│ p       ─────────────────────────────► 0x…90   （→ a[0]）                         │
│                                                                              地址 │
│ a[0] = 1.5 ───────────────────────────────────────────────────────────────► 0x…90 │
│ a[1] = 2.5 ───────────────────────────────────────────────────────────────► 0x…98 │
│ a[2] = 3.5 ───────────────────────────────────────────────────────────────► 0x…A0 │
│ onePast(⊗) ───────────────────────────────────────────────────────────────► 0x…A8 │
└───────────────────────────────────────────────────────────────────────────────────┘
# 步长：double 8B ⇒ 0x…90, 98, A0, A8
*/
  {
    cout << "double *last = p+2;\n";
    cout << "double *onePast = p+3; // out of bounds, but allowed\n\n";
  }

  cout << "last:     " << last << endl;//输出的是数组a第三个元素的地址//last: 0x7ffee3b8c9c8
  cout << "onePast:  " << onePast << endl;//输出的是数组a第四个元素的地址//onePast: 0x7ffee3b8c9d0//虽然这个地址是越界的，但编译器不会报错，因为它只是一个地址，并没有访问这个地址
  cout << "*last:    " << *last << endl;//输出的是数组a第三个元素的值//*last: 3.5
  cout << "*onePast: " << *onePast << endl;//输出的是数组a第四个元素的值，但这个地址是越界的，访问这个地址会导致未定义行为，可能会报错或者输出垃圾值//*onePast: 0
  //cout << "a[3] =    " << a[3] << " // WARNING: [] does bounds checking\n"; //这里访问越界会报错，因为a[3]表示访问数组a的第四个元素，但数组a只有3个元素，访问越界会导致未定义行为，可能会报错或者输出垃圾值

  waitForUser();

  cout << "Can print an array using pointer arithmetic,\n\n";//注意：这里使用指针运算来访问数组元素

  {
    cout << "for (int i=0; i<3; i++) cout << *(a+i) << \" \";\n\n";
  }

  for (int i = 0; i < 3; i++) //循环3次，i分别为0, 1, 2
	  cout << *(a + i) << " "; // NOTE: a[i] is defined as *(a+i)//输出数组a的第i个元素的值 //最后输出结果是：1.5 2.5 3.5

  cout << "\n\nand can use [] with a pointer to access array contents.\n\n";//可以用[]来访问指针指向的数组元素

  {
	  cout << "for (int i=0; i<3; i++) cout << p[i] << \" \";\n\n";//这句话意思是循环3次，i分别为0, 1, 2，输出指针p指向的数组的第i个元素的值
  }

  for (int i = 0; i < 3; i++)//循环3次，i分别为0, 1, 2
	  cout << p[i] << " ";// NOTE: p[i] is defined as *(p+i) //输出指针p指向的数组的第i个元素的值 //最后输出结果是：1.5 2.5 3.5
  cout << endl;//换行
  //注意：p[i]实际上是*(p+i)的简写形式，表示访问指针p指向的数组的第i个元素的值，所以p[i]和*(p+i)是等价的，这也就是为什么*（a+i）和p[i]最后输出的结果是一样的
  cout << "\nEND OF LESSON 2.\n";
}


// 3. Memory diagrams for functions with arrays/pointers and references //第三节课：使用数组/指针和引用的函数的内存图
void arrayParam(int arr[]);//这是一个函数声明，表示arrayParam函数接受一个int类型的数组作为参数
//注：void arrayParam(int arr[]);它在语义上完全等价于：void arrayParam(int* a)
void foo(int arr[], int size, int& sum);//这是一个函数声明，表示foo函数接受一个int类型的数组，一个int类型的size参数和一个int类型的引用sum参数
void bar(int* arr, int size, int* sum);//这是一个函数声明，表示bar函数接受一个int类型的指针，一个int类型的size参数和一个int类型的指针sum参数
void passByRefVsPassByPointer() {
  cout << "\nLESSON 3: Functions using pointers and references\n\n";//函数使用指针和引用

  cout << "Though often bad practice, sizeof tells a static array's size,\n\n";//虽然通常不推荐这样做，但sizeof可以告诉我们静态数组的大小

  int a1[] = { 5,0,1 };//数组a1有3个int类型的元素，分别是5, 0, 1

  {
    cout << "int a1[] = {5,0,1};\n\n";//注意：这里的数组a1是静态数组，大小在编译时就确定了
  }

  cout << "a1 = " << a1 << endl;//输出的是数组a1第一个元素的地址//a1 = 0x7ffee3b8c9b0
  cout << "sizeof(a1) = " << sizeof(a1) << endl;//sizeof(a1) = 12//数组a1有3个int类型的元素，每个int类型的元素占4个字节，所以sizeof(a1)返回的是12
  cout << "sizeof(a1)/sizeof(a1[0]) = " << sizeof(a1) / sizeof(a1[0]) << endl;//sizeof(a1)/sizeof(a1[0]) = 3
  //sizeof(a1)是数组a1的总大小=3*4=12，sizeof(a1[0])是数组a1第一个元素的大小=4，两个相除得到的是数组a1的元素个数=12/4=3

  cout << "\nbut this doesn't work for arrays passed into functions:\n\n";//但是这种方法不能用于传递给函数的数组
  /*
┌─────────── caller: passByRefVsPassByPointer ────────────┐//注意，这里的A1表示数组a1的第一个元素的地址
│ a1[0] = 5  ───────────────────────────────►  A1         │
│ a1[1] = 0  ───────────────────────────────►  A1+4       │
│ a1[2] = 1  ───────────────────────────────►  A1+8       │
└─────────────────────────────────────────────────────────┘
  */
  {
    cout << "arrayParam(a1);\n\n";//调用arrayParam函数，传递数组a1作为参数
  }

  arrayParam(a1);//调用arrayParam函数，传递数组a1作为参数，输出数组a1的第一个元素的地址，数组a1第一个元素的值，数组a1第二个元素的值

  cout << "because they are passed in as pointers.\n";//因为传递给函数的数组实际上是作为指针传递的

  waitForUser(); 

  cout << "Parameters can also be declared as references:\n\n";//参数也可以声明为引用
  
  {
    cout << "int a2[] = {1,2,3,4};\nint sum = 0;\n";
    cout << "foo(a2,sizeof(a2)/sizeof(a2[0]),sum);\n\n";
  }

  int a2[] = { 1,2,3,4 };//数组a2有4个int类型的元素，分别是1, 2, 3, 4
  int sum = 0;//定义一个int类型的变量sum，初始值为0
  /*
┌─────────── caller: passByRefVsPassByPointer ────────────┐
│ a2[0] = 1  ───────────────────────────────►  A2         │
│ a2[1] = 2  ───────────────────────────────►  A2+4       │
│ a2[2] = 3  ───────────────────────────────►  A2+8       │
│ a2[3] = 4  ───────────────────────────────►  A2+12      │
│ sum   = 0  ───────────────────────────────►  S          │
└─────────────────────────────────────────────────────────┘

  */
  foo(a2, sizeof(a2) / sizeof(a2[0]), sum);//调用foo函数，传递数组a2，数组a2的元素个数，变量sum作为参数//函数体内将数组a2的每个元素加1，并将原来的值加到sum上
  /*
┌─────────── caller: passByRefVsPassByPointer ────────────┐
│ a2: {2,3,4,5}  @ A2..A2+12                              │
│ sum = 10        @ S                                     │
└─────────────────────────────────────────────────────────┘

  */

  cout << "sum after function call: " << sum << endl;//输出函数调用后sum的值//sum after function call: 10

  for (int i = 0; i < 4; i++) {//用for循环遍历数组a2的每个元素
    cout << *(a2+i) << " ";//输出数组a2的第i个元素的值
  }
  cout << endl;//换行

  waitForUser();

  cout << "You can also pass pointers explicitly:\n\n";//你也可以显式地传递指针，意思是传递变量的地址

  {
    cout << "int *p = &sum;\nbar(a1,3,p);\n\n";//调用bar函数，传递数组a1，3，指针p作为参数
  }

  int* p = &sum;//定义一个int类型的指针p，指向变量sum的地址
  bar(a1, 3, p);//调用bar函数，传递数组a1，3，指针p作为参数//函数体内将数组a1的每个元素加1，并将原来的值加到sum上

  cout << "sum = " << sum << "\na1: ";
  for (int i=0; i<3; i++) {
    cout << a1[i] << " ";
  }
  cout << "\n\nEND OF LESSON 3.\n";
}

// shows why sizeof method can't find #elems in an array passed into a function
//作用：接受一个“数组参数” int a[]。打印出：a：数组第一个元素的地址（即指针的值）；* a：数组第一个元素的值；a[1]：数组第二个元素的值；
void arrayParam(int a[]) {
  {
    cout << "void arrayParam(int a[]) {\n  // WARNING: a is now an int*\n"; //注意：这里的a是一个int类型的指针，不是一个数组
  }
  cout << "  a = " << a << endl;//输出的是数组a第一个元素的地址的地址
  // WARNING: sizeof(a) is the size of an int *//注意：sizeof(a)返回的是指针a的大小，不是数组的大小
  //cout << "  sizeof(a)/sizeof(a[0]) = " << sizeof(a)/sizeof(a[0]) << "\n"; 
  cout << "  *a = " << *a << endl;//输出的是数组a第一个元素的值
  cout << "  a[1] = " << a[1] << "\n}\n\n";//输出的是数组a第二个元素的值
}
/*
┌──────────── callee: arrayParam(int a[]) ──────────────┐
│ a  ────────────────────────────────────►  A1          │
│                                                    地址│
│ *a   == 5                                           A1│
│ a[1] == 0                                         A1+4│
│ // sizeof(a) == 8（指针大小），不是数组大小              │
└───────────────────────────────────────────────────────┘
*/

// increments entries in arr and adds original values to sum (passed-by-ref)
//作用：接受一个“数组参数” int arr[]，一个int类型的size参数，一个int类型的引用sum参数。打印出：sum during foo：函数调用前sum的值；函数体内将数组arr的每个元素加1，并将原来的值加到sum上；函数结束
void foo(int arr[], int size, int& sum) { 
  {
    cout << "void foo(int arr[], int size, int& sum) {\n";
    cout << "  cout << \"sum during foo: \" << sum << endl;\n";
    cout << "  for (int i=0; i<size; i++) sum += arr[i]++;\n}\n\n";
  }
  cout << "sum during foo: " << sum << endl;
  for (int i = 0; i < size; i++) {//用for循环遍历数组arr的每个元素
	  sum += arr[i]++;//将数组arr的第i个元素加1，并将原来的值加到sum上//例如：如果arr[i]是2，那么先将2加到sum上，然后将arr[i]变为3，原数组如果是{2,3,4}，那么执行完这行代码后，sum增加2，arr变为{3,3,4}，最后arr变为{3,4,5}，sum增加2+3+4=9
  }
}
/*
┌────────────────── callee: foo ───────────────────┐
│ arr  ────────────────────────────────►  A2       │
│ size = 4                                         │
│ sum(ref) ────────────────┐                       │
│                          └────────►  S（与 caller 的 sum 同地址）│
│                                                地址│
│ 原始累加：1+2+3+4 = 10 → 写入 S                    │
│ 自增后 arr: {2,3,4,5} 写回 A2…                    │
└──────────────────────────────────────────────────┘
*/

// increments entries in arr and adds original values to sum (passed-by-pointer)
//作用：接受一个“指针参数” int* arr，一个int类型的size参数，一个int类型的指针sum参数。打印出：函数体内将数组arr的每个元素加1，并将原来的值加到sum上；函数结束
//int* arr是一个指向int类型变量的指针，实际上它指向的是一个数组的第一个元素，size是数组的元素个数，int* sum是一个指向int类型变量的指针，实际上它指向的是变量sum的地址
void bar(int *arr, int size, int* sptr) { 
  {
    cout << "void bar(int *arr, int size, int* sptr) {\n";
    cout << "  for (int i=0; i<size; i++) *sptr += (*(arr+i))++;\n}\n\n";
  }
  for (int i = 0; i < size; i++) {//用for循环遍历数组arr的每个元素
    *sptr += (*(arr+i))++; // NOTE: parens are important here //将数组arr的第i个元素加1，并将原来的值加到sum上
	//sptr是一个指针，*sptr表示取出指针sptr指向的地址中存储的值，即变量sum的值
	//*(arr+i)是从指针arr+i取值，取出数组arr的第i个元素的值
	//等价于 sum += arr[i]++；
  }
}

// 4. Using pointers with new and delete to access heap memory
int *getSquareArray(int);
void usingTheHeap() {
  cout << "\nLESSON 4: Using pointers to access heap memory\n\n";

  cout << "Use \'new\' to allocate memory on the stack:\n\n";

  int stackInt = 4; // a named local variable for an int on the stack //栈上的一个命名的局部变量
  int* stackIntP = &stackInt; // a pointer on the stack to a //指向栈上int的指针
  int* heapIntP = new int(3); // pointer the int itself is anonymous //指向堆上匿名int的指针 
  //这里是一个新知识点：new操作符用于在堆上动态分配内存，返回一个指向新分配内存的指针
  //所谓堆内存，是指程序运行时动态分配的内存，通常用于存储需要在函数调用结束后仍然存在的数据
  //与之相对的是栈内存，栈内存用于存储函数的局部变量和参数，函数调用结束后，这些变量和参数会被自动释放
  //因此这里使用new int(3)在堆上分配了一个int类型的内存，并初始化为3，返回一个指向该内存的指针heapIntP
  //注意：使用new分配的内存需要手动释放（用delete），否则会导致内存泄漏
  /*（new 之后）
# Stack (usingTheHeap)
heapIntP      H
stackIntP     &stackInt
stackInt      4

# Heap
H:            (int) 3
  */
  {
    cout << "int stackInt = 4;\n";
    cout << "int *stackIntP = &stackInt;\n";
    cout << "int *heapIntP = new int(3);\n";
  }

  // DIAGRAM 1

  waitForUser();

  cout << "stackInt:   " << stackInt << endl;//输出栈上变量stackInt的值//stackInt: 4
  cout << "&stackInt:  " << &stackInt << endl << endl;//输出栈上变量stackInt的地址//&stackInt: 0x7ffee3b8c9ac
  cout << "stackIntP:  " << stackIntP << endl;//输出指针stackIntP的值，即栈上变量stackInt的地址//stackIntP: 0x7ffee3b8c9ac
  cout << "&stackIntP: " << &stackIntP << endl;//输出指针stackIntP自己本身的地址（谁叫指针也是一个变量呢）//&stackIntP: 0x7ffee3b8c9a0
  cout << "*stackIntP: " << *stackIntP << endl << endl;//从地址取值，输出指针stackIntP指向的值，即栈上变量stackInt的值//*stackIntP: 4
  cout << "heapIntP:   " << heapIntP << endl;//输出指针heapIntP的值，即堆上匿名int的地址//heapIntP: 0x600003b26020//这里之所以是地址，是因为堆内存的地址是动态分配的，每次运行程序可能会不同
  cout << "&heapIntP:  " << &heapIntP << endl;//输出指针heapIntP自己本身的地址（谁叫指针也是一个变量呢）//&heapIntP: 0x7ffee3b8c998
  cout << "*heapIntP:  " << *heapIntP << endl;//从地址取值，输出指针heapIntP指向的值，即堆上匿名int的值//*heapIntP: 3

  waitForUser();

  cout << "Use \'delete\' to avoid orphaning heap memory:\n\n";

  delete heapIntP; // Your code will be functional without this,//这里我们使用delete操作符来释放堆上分配的内存，避免内存泄漏
  heapIntP = stackIntP; // but then this would orphan your 3.//这里原来heapIntP指向的堆内存已经被释放了，现在heapIntP指向栈上变量stackInt的地址
  /*删除后并重定向
# Stack
heapIntP      &stackInt
stackIntP     &stackInt
stackInt      4

# Heap
H:            freed     //原来heapIntP指向的堆内存已经被释放了，不再可用。(H: freed表示这块内存已经被释放)
  */

  {
	  cout << "delete heapIntP; // Your code will be functional without this,\n";//翻译：删除heapIntP指向的堆内存；你的代码在没有这行的情况下也能运行，
	  cout << "heapIntP = stackIntP; // but then this would orphan your 3.\n";//翻译：但这样会让你的3变成孤儿（无法访问的内存）。
  }

  waitForUser();

  cout << "This is particularly relevant for arrays on the heap:\n\n";//这对于堆上的数组尤其重要

  cout << "How many ints in your dynamically-allocated array? size = ";//提示用户输入动态分配数组的大小
  int size;
  cin >> size;//读取用户输入的数组大小

  int* a = new int[size];//在堆上动态分配一个int类型的数组，大小为用户输入的size，返回一个指向该数组第一个元素的指针a

  {
    cout << "\nint *a = new int[size];\n\n";
  }

  // DIAGRAM 2

  cout << "Enter " << size << " ints: ";  
  for (int i=0; i<size; i++) {
    cin >> a[i];//挨个输入数组a的每个元素的值
  }

  cout << "How many more? extra = ";
  int extra;
  cin >> extra;//读取用户输入的额外元素个数

  int* tempPtr = new int[size + extra]; //在堆上动态分配一个int类型的数组，大小为size+extra，返回一个指向该数组第一个元素的指针tempPtr

  {
    cout << "\nint *tempPtr = new int[size+extra];\n\n";
  }

  cout << "Enter " << extra << " more: ";//提示用户输入额外的元素值

  for (int i = 0; i < size + extra; i++) {//循环size+extra次，对应新数组tempPtr的每个元素
	if (i < size) {//如果i小于size，说明是原数组a的元素
	  tempPtr[i] = a[i];//将原数组a的第i个元素复制到新数组tempPtr的第i个元素
	}
	else {//否则，说明是额外的元素
	  cin >> tempPtr[i];//读取用户输入的额外元素值，存储到新数组tempPtr的第i个元素
    }
  }

  cout << "a contents: ";//输出原数组a的内容
  for (int i=0; i<size; i++) {
    cout << a[i] << " ";//挨个输出原数组a的第i个元素的值
  }
  cout << "\ntempPtr contents: ";//输出新数组tempPtr的内容
  for (int i=0; i<size+extra; i++) {
    cout << tempPtr[i] << " ";//挨个输出新数组tempPtr的第i个元素的值
  }
  cout << "\na: " << a << "\ntempPtr: " << tempPtr << endl;//输出原数组a的地址和新数组tempPtr的地址

  waitForUser();

  cout << "Use delete [] to free memory before updating array pointers:\n\n";//在更新数组指针之前，使用delete []来释放内存

  delete[] a;//现在我们已经不需要原数组a了，使用delete []来释放堆上分配的内存
  a = tempPtr;//将指针a指向新数组tempPtr的地址
  tempPtr = nullptr;//将指针tempPtr设置为nullptr，表示它不再指向任何有效的内存地址

  {
    cout << "delete [] a;\na = tempPtr;\ntempPtr = nullptr;\n\n";
  }

  // DIAGRAM 3

  cout << "a: " << a << endl;//输出指针a的值，即新数组tempPtr的地址
  cout << "tempPtr: " << tempPtr << endl;//输出指针tempPtr的值，即nullptr
  cout << "a contents: ";
  for (int i=0; i<size+extra; i++) {
    cout << a[i] << " ";//挨个输出新数组tempPtr的每个元素的值
  }
  cout << endl;

  waitForUser();

  cout << "By allocating heap memory, we can now return arrays:\n\n";

  {
    cout << "int *squares = getSquareArray(4);\n\n";
  }
  
  int* squares = getSquareArray(4);//调用getSquareArray函数（下面定义了），传递4作为参数，返回一个指向堆上分配的包含4个元素的数组的指针squares
  //最后结果是squares指向的数组是{0, 1, 4, 9}，因为0*0=0, 1*1=1, 2*2=4, 3*3=9

  // ANOTHER DIAGRAM

  for (int i=0; i<4; i++) {
	  cout << squares[i] << " ";//这里使用squares[i]来访问上面数组squares的每个元素，并输出它们的值
    //cout << *(squares+i) << " ";
  }
  cout << endl;
  
  delete[] squares;//现在我们已经使用完数组squares了，使用delete []来释放堆上分配的内存
  squares = nullptr;//将指针squares设置为nullptr，表示它不再指向任何有效的内存地址

  {
    cout << "delete [] squares;\nsquares = nullptr;\n";//释放堆上分配的内存，并将指针squares设置为nullptr
  }

  waitForUser();

  cout << "Finally, note that dereferencing a nullptr causes a segfault:\n\n";//最后，注意解引用nullptr会导致段错误（segfault）
  //例子：如果我们尝试用（*）来解引用squares指针，因为我们刚才将它设置为nullptr，所以会导致运行时错误（RUNTIME ERROR）

  {
    cout << "int dereferencedVal = *squares; // compiles fine but segfaults\n";//翻译：int dereferencedVal = *squares; // 编译没问题但会导致段错误
	cout << "cout << dereferencedVal << endl; // so we never get here\n\n";//翻译：cout << dereferencedVal << endl; // 所以我们永远到不了这里
  }

  int dereferencedVal = *squares; // RUNTIME ERROR
  //if (squares!=nullptr) dereferencedVal = *squares;
  cout << dereferencedVal << endl; // this code isn't reached
}

//这个函数的作用是接受一个int类型的size参数，返回一个指向int类型变量的指针，实际上它指向的是一个包含size个元素的数组，这个数组的每个元素是其索引的平方值
//例如：如果size是4，那么返回的数组是{0, 1, 4, 9}，因为0*0=0, 1*1=1, 2*2=4, 3*3=9
int* getSquareArray(int size) {//这里是一个新知识点：函数返回一个指向int类型变量的指针，实际上它指向的是一个数组的第一个元素
  {
    cout << "int* getSquareArray(int size) {\n";
    cout << "  int *a = new int[size];\n";
    cout << "  for (int i=0; i<size; i++) a[i]=i*i;\n  return a;\n}\n\n";
  }
  int* a = new int[size];//在堆上动态分配一个int类型的数组，大小为size，返回一个指向该数组第一个元素的指针a
  for (int i=0; i<size; i++) {
    a[i] = i*i;//挨个将数组a的第i个元素赋值为i的平方
  }
  return a;//返回指针a，指向堆上分配的数组
}

// stalls program excecution until user enters a non-whitespace input//这里我们定义了一个辅助函数waitForUser，用于在程序执行过程中暂停，直到用户输入一个非空白字符为止
void waitForUser() {
  cout << "\nContinue (y/n)? ";//提示用户输入是否继续
  string uInput;//定义一个字符串变量uInput，用于存储用户输入
  cin >> uInput;//读取用户输入并存储到uInput中
  if (toupper(uInput[0]) == 'N') exit(1);//如果用户输入的第一个字符是'n'或'N'，则退出程序
  cout << endl;
}

