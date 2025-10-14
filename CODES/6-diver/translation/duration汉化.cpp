// Duration 类的实现文件。
// （专门写出在 duration.h 中声明过的函数的定义）
// 新知识点包括 to_string 的使用，以及运算符重载的语法。
// Sara Krehbiel, 2025/10/1-2025/10/3

#include "duration.h" // 包含接口文件

// 使用 to_string 与字符串拼接，格式化为 "x hrs, y mins"
string Duration::toString() const {
	//mins=1000; // 若 toString 被声明为 const 成员函数，则此处修改非法
	return to_string(mins/60) + " hrs, " + to_string(mins%60) + " mins"; 
}

// 1 把 sumDuration 实现为成员函数
Duration Duration::sumDuration(Duration rhs) { // 注意：需要作用域解析符
	//int total = mins + rhs.mins; // 注意：mins 来自调用对象（左操作数）
	//Duration thirdObj(total);
	//return thirdObj;
	return Duration(mins + rhs.mins); 
}

// 2 把 sumDuration 实现为非成员非友元函数
/*Duration sumDuration(Duration lhs, Duration rhs) { // 注意：非成员函数不需要作用域解析符
	return Duration(lhs.getMins()+rhs.getMins()); // 因为不是友元，必须通过 getter
}*/

// 3 把 sumDuration 实现为（非成员）友元函数
Duration sumDuration(Duration lhs, Duration rhs) {
	return Duration(lhs.mins + rhs.mins); // 友元可直接访问私有成员
}

// 4 把 + 实现为成员函数
Duration Duration::operator +(Duration rhs) { 
	return Duration(mins + rhs.mins);
}

// 5 把 + 实现为非成员非友元函数
/*Duration operator +(Duration lhs, Duration rhs) {
	return Duration(lhs.getMins() + rhs.getMins());
}*/

// 6 把 + 实现为友元函数
/*Duration operator +(Duration lhs, Duration rhs) {
	return Duration(lhs.mins + rhs.mins);
}*/
