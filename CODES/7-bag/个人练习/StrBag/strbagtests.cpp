#include <iostream>   // for console I/O
#include <fstream>    // for file I/O
#include "strbag.h"
using namespace std;

int main() {
    // ====== TODO[阶段 1]：最小功能自测 ======
    // 目标：能插入两个字符串并打印；size() 正确
    
    StrBag b;
    b.insert("apple");
    b.insert("banana");
    cout << "size=" << b.size() << "\n";
    cout << "b=" << b << "\n";  // 预期：apple banana
    

    // ====== TODO[阶段 2]：带数组构造函数自测 ======
    // 目标：用 string 数组初始化，并检查顺序
    
    string a[4] = {"cs","bag","bag","c++"};
    StrBag b2(a,4);
    cout << "b2=" << b2 << "\n"; // 预期：cs bag bag c++
    

    // ====== TODO[阶段 3]：count / erase_one / erase 自测 ======
    // 覆盖：删头/删中/删尾；删不存在；删到一个不剩
    
    StrBag b3;
    b3.insert("x"); b3.insert("y"); b3.insert("x"); b3.insert("x");
    cout << "count(x)=" << b3.count("x") << "\n"; // 3
    b3.erase_one("x");                            // 删除第一次出现的 x
    cout << "after erase_one: " << b3 << "\n";    // 预期：y x x（或按你的实际顺序）
    cout << "removed=" << b3.erase("x") << "\n";  // 预期：2
    cout << "after erase all: " << b3 << "\n";    // 预期：y
    cout << "removed none=" << b3.erase("zzz") << "\n"; // 0
    

    // ====== TODO[阶段 4]：+= 与 + 自测 ======
    
    string A[3] = {"a","b","c"};
    string B[2] = {"b","b"};
    StrBag b1(A,3), b4(B,2);
    b4 += b1;
    cout << "b4=" << b4 << "\n"; // 预期：b b a b c
    StrBag b5 = b1 + b4;
    cout << "b5=" << b5 << "\n"; // 预期：a b c b b a b c
    

    // ====== TODO[阶段 5]：文件输出 ======
    
    ofstream fout("strcontents.txt");
    fout << "b5=" << b5 << "\n";
    fout.close(); // 打开同目录文件检查内容是否与控制台一致
    

    return 0;
}
