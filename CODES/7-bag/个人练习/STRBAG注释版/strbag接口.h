#ifndef STRBAG_H
#define STRBAG_H

#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::size_t;

class StrBag {
public:
    // ============================================================
    // ① 静态常量（Static Constant）
    // ============================================================
    // CAPACITY 表示袋子最大容量，全类共享，不能被修改。
    static const size_t CAPACITY = 1000;

    // ============================================================
    // ② 构造函数（Constructors）
    // ============================================================
    StrBag();                            // 默认构造器，创建空袋子
    StrBag(string a[], size_t n);        // 用已有字符串数组初始化袋子

    // ============================================================
    // ③ 访问器（Accessors / Getters）
    // ============================================================
    size_t size() const;                 // 返回当前袋中字符串数量
    string operator[](size_t index) const; // 按索引访问袋子中第 index 个字符串
    size_t count(const string& val) const; // 统计特定字符串在袋中出现的次数

    // ============================================================
    // ④ 修改器（Mutators / Setters）
    // ============================================================
    void insert(const string& val);      // 向袋中插入一个字符串
    bool erase_one(const string& val);   // 删除袋中第一个匹配字符串
    size_t erase(const string& val);     // 删除袋中所有匹配的字符串

    // ============================================================
    // ⑤ 运算符重载（Operator Overloading）
    // ============================================================
    StrBag& operator+=(const StrBag& rhs); // 实现 += ，把另一个袋子内容追加到当前对象

private:
    // ============================================================
    // ⑥ 数据成员（Data Members）
    // ============================================================
    string data_[CAPACITY];              // 存放字符串的数组
    size_t size_;                        // 当前袋子中已存字符串的数量
};

// ============================================================
// ⑦ 非成员函数（Non-Member Operators）
// ============================================================
// + 运算符：合并两个 StrBag 对象，生成一个新袋子
StrBag operator+(const StrBag& lhs, const StrBag& rhs);

// << 运算符：打印 StrBag 内容，用空格分隔
ostream& operator<<(ostream& o, const StrBag& b);

#endif
