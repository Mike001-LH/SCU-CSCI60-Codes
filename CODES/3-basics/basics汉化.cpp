// 本文件演示了一些基本的 C++ 概念和语法，
// 并强调了与 Python/其他语言的区别。
// Sara Krehbiel, CSCI 60, 2025/9/26

#include <iostream> // 与周一相同的库，用于输入输出
#include <fstream>  // 新库，用于文件读写
using namespace std; 


/* 函数声明 */

void wednesday();   // 控制台输入输出、数组、条件语句、循环
void friday();      // 函数与文件读写
void functions();   // 调用各种辅助函数的示例代码
void hooray();      // 一个无参数、无返回值的函数声明
void hoorayN(int n); // 带参数的 hooray 版本
bool isPrime(int n); // 判断 n 是否是质数
void fileIO();      // 文件读写的示例代码
void fileIOBonus(); // 课堂上延伸问题的更多文件读写示例


/* 主函数：程序入口 */

// 调用多个辅助函数，展示基本 C++ 语法
int main() { 
    wednesday(); // 控制台 I/O、数组、条件语句和循环
    friday();    // 函数与文件 I/O
    return 0;
}


/* 函数定义 */ 

// 示例代码：输出字符串/数字，使用变量、条件语句和循环
void wednesday() {
    // 0 控制台输出

    cout << "Hello\n"; // 注意换行符和制表符
    cout << "It was the best of times, it was the worst of times, "
            << "it was the age of wisdom, it was the age of foolishness, ";
    cout << "it was the epoch belief, it was the epoch of incredulity...\n";
    cout << "\n\tHere's a new paragraph that is indented." << endl;

    // 不使用变量直接计算
    cout << (5+3) << endl; // 5+3 不在引号内，所以会作为计算而非文本
    cout << (5%3) << endl; // 取模运算
    cout << (5/3) << endl; // 注意整型除法会截断
    cout << (5.0/3) << endl; // 带 .0 则视为浮点数除法

    // 1 变量（数字、字符串、数组）

    // 不同类型变量的声明与初始化
    double n = 5; // 试试改成 5.5，然后声明为 int
    int d = 3;

    // 使用已声明变量进行输出
    cout << "The numerator is " << n << endl;
    n = 17;
    cout << "The numerator is now " << n << endl;
    cout << "The fraction is " << n << "/" << d << endl;
    cout << "The fraction evaluates to " << (n/d) << endl;

    // 从用户获取输入
    int userVal; // 变量可以声明时不初始化
    cout << "Enter an integer: "; // 提示用户输入
    cin >> userVal; // 将输入存入变量
    cout << "You entered " << userVal << endl; // 输出存储的值

    // 数组的声明、赋值与访问
    int threeInts[3] = {4, 6, 7}; // 声明一个含 3 个 int 的数组并初始化
    int size = 3; // 存储数组大小是个好习惯
    cout << "First value: " << threeInts[0] << endl; // 访问第一个元素
    cout << "Last value: " << threeInts[2] << endl;  // 访问最后一个元素
    threeInts[size-1] = 12; // 修改最后一个元素（注意下标）
    cout << "The last value in my array is " << threeInts[size-1] << endl;
    
    // 2 布尔值与条件语句

    bool eligible = false;
    cout << eligible << endl; // 输出布尔值：false 为 0，true 为 1

    if (eligible) cout << "You're eligible.\n";
    else cout << "You're not eligible.\n";
    
    // 使用三目运算符输出不同的字符串
    //cout << "You're " << (eligible ? "" : "not ") << "eligible." << endl;

    int age = 18;
    // 注意 age>=21 会返回布尔值，尽管 age 和 21 都是整数
    if (age>=21) cout << "Welcome to the bar!\n";
    else cout << "Come back when you're older.\n";

    // 3 循环

    // 一个标准的 for 循环，循环 3 次
    for (int i=0; i<3; i++) {
        cout << i << " Hip hip hooray!\n";
    }
    //cout << i << endl; // 编译错误：i 的作用域仅在循环内部

    // 等效的 while 循环，先初始化，再判断，再自增
    int j=0;
    while (j<3) {
        cout << j << " Hop hop hiray!\n";
        j++; // 尝试：如果去掉这行会怎样？//会死循环，用ctrl+c在终端跳出死循环
    }
    cout << j << endl; // 正常编译，因为 j 在循环外声明
}

// 用户自定义函数与文件读写示例
void friday() {
    // 4 函数
    functions();

    // 5 文件 I/O
    fileIO();
    fileIOBonus();
}

void functions() {
    // 调用无参数与有参数函数
    hooray();
    hoorayN(4);
    hoorayN(2);

    // 调用布尔函数
    int n=5;
    if (isPrime(n)) cout << n << " is prime\n";
    else cout << n << " is not prime\n";
    n=15;
    if (isPrime(n)) cout << n << " is prime\n";
    else cout << n << " is not prime\n";
}

// 输出三行文本，无返回值
void hooray() {
    for (int i=3; i>0; i--) { // 注意循环头部参数变化的效果
        cout << i << " Hooray hip hip!\n";
    }
}

// 输出 n 行文本，n 为参数
void hoorayN(int n) {
    for (int i=0; i<n; i++) {
        cout << "Hooray\n";
    }
}

// 返回 n 是否为质数
bool isPrime(int n) {
    // 检查所有可能的非平凡因子
    for (int i=2; i<=n-1; i++) {
        // 若找到因子，立即返回 false
        if (n%i==0) return false;
    }
    return true;
}

// 从文件中读取整数，只将质数写入另一个文件
void fileIO() {
    int nextInt; // 存储从 ints.txt 读取的数字
    ifstream fin("ints.txt");    // 要读取的现有文件
    ofstream fout("primes.txt"); // 要写入的文件（可新建）
    while (fin >> nextInt) {     // 当有新的数字时循环
        if (isPrime(nextInt)) {  // 检查是否为质数
            fout << nextInt << endl; // 写入文件
            //cout << nextInt << " is prime\n"; // 也可输出到控制台
        } 
    }
    // 用完关闭文件流
    fin.close();
    fout.close();
}

// 来自课堂提问的进阶示例
void fileIOBonus() {
    // 可以同时打开多个输入/输出文件
    int nextInt; 
    ifstream fin("ints.txt"); 
    ofstream fout("primes.txt"); 
    ofstream fout2("notprimes.txt"); 

    // 如果要存储未知数量的数据到数组…
    int primes[10]; // 声明一个比实际需要大的数组
    int nextIndex = 0; // 记录下一个可用位置
    while (fin >> nextInt) { // 按数字逐个读取
        if (isPrime(nextInt)) { 
            fout << nextInt << endl; // 将质数写入 primes.txt
            primes[nextIndex] = nextInt; // 存入数组
            nextIndex++; // 下一个索引
        } else {
            fout2 << nextInt << endl; // 非质数写入 notprimes.txt
        }
    }
    // 用完关闭文件流
    fin.close();
    fout.close();
    fout2.close();
}

