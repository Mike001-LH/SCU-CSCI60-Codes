#include <iostream>   // for console I/O
#include <fstream>    // for file I/O
#include "strbag.h"
using namespace std;

int main() {
    // ====== TODO[�׶� 1]����С�����Բ� ======
    // Ŀ�꣺�ܲ��������ַ�������ӡ��size() ��ȷ
    
    StrBag b;
    b.insert("apple");
    b.insert("banana");
    cout << "size=" << b.size() << "\n";
    cout << "b=" << b << "\n";  // Ԥ�ڣ�apple banana
    

    // ====== TODO[�׶� 2]�������鹹�캯���Բ� ======
    // Ŀ�꣺�� string �����ʼ���������˳��
    
    string a[4] = {"cs","bag","bag","c++"};
    StrBag b2(a,4);
    cout << "b2=" << b2 << "\n"; // Ԥ�ڣ�cs bag bag c++
    

    // ====== TODO[�׶� 3]��count / erase_one / erase �Բ� ======
    // ���ǣ�ɾͷ/ɾ��/ɾβ��ɾ�����ڣ�ɾ��һ����ʣ
    
    StrBag b3;
    b3.insert("x"); b3.insert("y"); b3.insert("x"); b3.insert("x");
    cout << "count(x)=" << b3.count("x") << "\n"; // 3
    b3.erase_one("x");                            // ɾ����һ�γ��ֵ� x
    cout << "after erase_one: " << b3 << "\n";    // Ԥ�ڣ�y x x�������ʵ��˳��
    cout << "removed=" << b3.erase("x") << "\n";  // Ԥ�ڣ�2
    cout << "after erase all: " << b3 << "\n";    // Ԥ�ڣ�y
    cout << "removed none=" << b3.erase("zzz") << "\n"; // 0
    

    // ====== TODO[�׶� 4]��+= �� + �Բ� ======
    
    string A[3] = {"a","b","c"};
    string B[2] = {"b","b"};
    StrBag b1(A,3), b4(B,2);
    b4 += b1;
    cout << "b4=" << b4 << "\n"; // Ԥ�ڣ�b b a b c
    StrBag b5 = b1 + b4;
    cout << "b5=" << b5 << "\n"; // Ԥ�ڣ�a b c b b a b c
    

    // ====== TODO[�׶� 5]���ļ���� ======
    
    ofstream fout("strcontents.txt");
    fout << "b5=" << b5 << "\n";
    fout.close(); // ��ͬĿ¼�ļ���������Ƿ������̨һ��
    

    return 0;
}
