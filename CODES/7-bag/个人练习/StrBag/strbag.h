#ifndef STRBAG_H
#define STRBAG_H

#include <cstdlib>   //for size_t
#include <string>    // for std::string
#include <iostream>  // for ostream
//using namespace std; // allows you to use std::string instead of string //NOTE: using namespace std in class defns results in namespace pollution
using std::size_t; //for size_t
using std::string; //for std::string
using std::ostream; //for ostream


class StrBag {
public:
    //
    static const size_t CAPACITY = 1000; //作用是：定义一个静态常量，用于限制StrBag的容量 //static的意思是：这个常量是类级别的，而不是对象级别的，可以被所有对象共享
    
    // constructors构造函数
    StrBag();//default constructor
    StrBag(string a[], size_t n);//constructor with array of strings and size

    // accessors访问器 (pre- and post-conditions are the same well-structured bags)
    size_t size() const {return size_;}; //return the size of the StrBag
    string operator [](size_t index) const {return data_[index];}; //(只读)//return the string at the given index//意思是：返回数组中索引为index的字符串 //operator[]是C++中的一个运算符重载，用于访问数组中的元素

    //mutators修改器
    void insert(const string& val);//若未满，在 data_[size_] 放入并 size_++ //const string& val的意思是：val是一个常量字符串引用，不能被修改。//相当于把val本体传进来，但不会改变val的值
    size_t count(const string& val) const; //统计匹配次数//这里两个const的意思分别是：1. const string& val的意思是：val是一个常量字符串引用，不能被修改。2. 最右边的const表示返回值是常量
    bool erase_one(const string& val);//删除全部匹配并返回删除数量//若data_中包含val，则将data_中所有val移除，并返回true；否则返回false
    size_t erase(const string& val);//删除全部匹配并返回删除数量//若data_中包含val，则将data_中所有val移除，并返回true；否则返回false

    StrBag& operator+=(const StrBag& rhs);
        
private:
    string data_[CAPACITY];//partially filled array of size CAPACITY //数组有 1000 个位置，但只有前 size_个位置是“有效的”，其他位置是“未定义的” 
    size_t size_;//size of the StrBag //PS:size_是类中的一个成员变量，用于存储StrBag的大小
};

//function declarations运算符重载 
//重载+运算符，用于合并两个StrBag//// Post: StrBag with lhs and rhs contents in order returned, lhs and rhs unchanged
StrBag operator+(const StrBag& lhs, const StrBag& rhs);
//ostream& operator的意思是：返回一个ostream类型的引用，表示输出流对象本身。//
ostream& operator<<(ostream& o, const StrBag& b);//ostream& o, const StrBag& b的意思分别是：1. ostream& o表示输出流对象的引用，可以是cout或者ofstream等。2. const StrBag& b表示一个常量StrBag对象的引用，不能被修改。


#endif