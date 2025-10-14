#include "strbag.h"
#include <iostream>
#include <fstream>
using namespace std;

// ============================================================
// 主函数：分阶段测试 StrBag 类的所有功能
// ============================================================
int main() {

    // --------------------------------------------------------
    // ① 测试构造函数与插入函数
    // --------------------------------------------------------
    cout << "[TEST 1] Default constructor + insert()" << endl;
    StrBag b;
    b.insert("apple");
    b.insert("banana");
    cout << "b = " << b << endl;
    cout << "size(b) = " << b.size() << endl << endl;

    // --------------------------------------------------------
    // ② 测试带数组参数的构造函数
    // --------------------------------------------------------
    cout << "[TEST 2] Array constructor" << endl;
    string arr[] = { "cs", "bag", "bag", "c++" };
    StrBag b2(arr, 4);
    cout << "b2 = " << b2 << endl;
    cout << "count('bag') = " << b2.count("bag") << endl << endl;

    // --------------------------------------------------------
    // ③ 测试 erase_one() 与 erase()
    // --------------------------------------------------------
    cout << "[TEST 3] erase_one() and erase()" << endl;
    b2.erase_one("bag");
    cout << "After erase_one('bag'): " << b2 << endl;
    b2.erase("bag");
    cout << "After erase('bag'): " << b2 << endl << endl;

    // --------------------------------------------------------
    // ④ 测试 operator+= 与 operator+
    // --------------------------------------------------------
    cout << "[TEST 4] operator+= and operator+" << endl;
    StrBag b3;
    b3.insert("x");
    b3.insert("y");
    b2 += b3; // +=（成员重载）
    cout << "b2 += b3 → " << b2 << endl;

    StrBag b4 = b + b2; // +（非成员重载）
    cout << "b4 = b + b2 → " << b4 << endl << endl;

    // --------------------------------------------------------
    // ⑤ 测试文件输出（ofstream + operator<<）
    // --------------------------------------------------------
    cout << "[TEST 5] File output test" << endl;
    ofstream fout("strbag_output.txt");
    fout << "b4 contents: " << b4 << endl;
    fout.close();
    cout << "Output saved to strbag_output.txt ✅" << endl;

    return 0;
}
