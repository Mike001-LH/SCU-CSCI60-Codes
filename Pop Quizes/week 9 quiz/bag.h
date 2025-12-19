/*
Week 9 Quiz

Wednesday, November 17, 2025
CSCI 60 — Krehbiel

Instructions.
Declare and give an inline definition for a Bag member function called count,
which takes a value as a parameter and returns how many times that value appears in the calling object’s list.

You do not have to use node functionality directly to do this, because you can assume that
list_count is already implemented in the node library with the function signature and pre- and post-conditions indicated.
*/
#include "node.h"

template <typename T>
class Bag {
public:
    //答案如下：
	size_t count(const T& val) const {//这里之所以用T，是因为val是Bag类的模板参数类型
		return list_count(head, tail, val);//调用node.h中已经实现的list_count函数，接下来我先完成node.h中的list_count函数的实现
    }
private:
    node<T>* head;
    node<T>* tail;
};
