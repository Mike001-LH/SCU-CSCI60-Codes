#include <iostream>
using namespace std;

class ModInt {
private:
    int num;
    int mod;
public:
    ModInt(int a, int b);
    ModInt();
    int getNum() {
        return num;
    }
    int getMod() {
        return mod;
    }
    void plusEq(ModInt rhs);
};

// Constructor implementations
ModInt::ModInt(int a, int b) {//2-arg constructor //作用：初始化对象的 num 和 mod 成员变量。//a和b是传递给构造函数的参数。
    num = a;
    mod = b;
}

ModInt::ModInt() {//0-arg constructor //作用：初始化对象的 num 和 mod 成员变量。//没有传递参数。//作用：将 num 和 mod 成员变量初始化为 0 和 1。
    num = 0;
    mod = 1;
}

// equals function
bool equals(ModInt lhs, ModInt rhs) {
    if (lhs.getNum() == rhs.getNum() && lhs.getMod() == rhs.getMod()) {//作用：判断对象 lhs 和对象 rhs 的模数是否相等。
        return true;
    } else {
        return false;
    }
}

// plusEq (member function)
void ModInt::plusEq(ModInt rhs) {//如果调用者对象（a）的模数 == 参数对象（b）的模数，就允许进行模加法运算。
    // if (getMod() == rhs.getMod()) 其实就是 this->getMod() == rhs.getMod() //this 指向调用对象 a //当调用是 a.plusEq(b) 时，this 就是 a，rhs 就是 b。）
    if (getMod() == rhs.getMod()) {//左边的 getMod() 获取的是对象 a 的模数，右边的 getMod() 获取的是对象 b 的模数。
        num = (getNum() + rhs.getNum()) % getMod();//作用：将对象 a 和对象 b 相加，然后对结果取模，getMod（）获取对象 a 的模数，并返回相加后的结果。
    } else {
        num = -1;
        mod = -1;
    }
}

// plus1 (non-member helper function)
ModInt plus1(ModInt lhs, ModInt rhs) {//这相当于把 plusEq 封装成一个“普通函数版”，把 plusEq 作为参数传递给 plus1 函数。//lhs 是对象 a，rhs 是对象 b。
    lhs.plusEq(rhs);//它接收两个对象，返回它们相加后的结果。
    return lhs;
}

// main test driver
int main() {
    ModInt a;//ModInt a; 是创建一个 ModInt 类型的对象 a，并调用 ModInt 类的构造函数。
    ModInt b(175, 180);//ModInt b(175, 180); 是创建一个 ModInt 类型的对象 b，并调用 ModInt 类的构造函数，传递参数 175 和 180。
    cout << a.getNum() << endl; // 0    
    cout << a.getMod() << endl; // 1
    cout << b.getNum() << endl; // 175
    cout << b.getMod() << endl; // 180

    ModInt c(175, 180);//ModInt c(175, 180); 是创建一个 ModInt 类型的对象 c，并调用 ModInt 类的构造函数，传递参数 175 和 180。
    cout << equals(a, c) << endl; // 0
    cout << equals(b, c) << endl; // 1

    ModInt d(6, 180);//ModInt d(6, 180); 是创建一个 ModInt 类型的对象 d，并调用 ModInt 类的构造函数，传递参数 6 和 180。
    c.plusEq(d);//c.plusEq(d); 是调用对象 c 的 plusEq 成员函数，并传递参数 d。//作用：将对象 c 和对象 d 相加，并返回相加后的结果。
    cout << c.getNum() << endl; // 1
    cout << c.getMod() << endl; // 180

    ModInt e(175, 180);
    ModInt f = plus1(e, d);//ModInt f = plus1(e, d); 是创建一个 ModInt 类型的对象 f，并调用 plus1 函数，传递参数 e 和 d。//作用：将对象 e 和对象 d 相加，并返回相加后的结果。
    cout << f.getNum() << endl; // 1
    cout << f.getMod() << endl; // 180

    return 0;
}
// main程序逻辑是：
// 1️⃣ 创建多个 ModInt 对象（a, b, c, d, e, f），分别使用默认构造函数和带参构造函数进行初始化；       //初始化对象的 num 和 mod 成员变量。
// 2️⃣ 通过 getNum() 与 getMod() 打印每个对象的数值和模数，验证构造是否正确；                      //作用：获取对象的 num 和 mod 成员变量。
// 3️⃣ 使用 equals(a, c)、equals(b, c) 检查两个对象是否相等（数值和模数都一致才返回 true）；         //作用：判断对象 lhs 和对象 rhs 的模数是否相等。
// 4️⃣ 调用成员函数 c.plusEq(d)，执行模加法（c = (c + d) % mod）；                                //作用：将对象 c 和对象 d 相加，然后对结果取模，getMod（）获取对象 c 的模数，并返回相加后的结果。
// 5️⃣ 调用非成员函数 plus1(e, d)，测试函数形式的模加法（返回一个新的 ModInt 对象 f）；           //作用：将对象 e 和对象 d 相加，然后对结果取模，getMod（）获取对象 e 的模数，并返回相加后的结果。
// 6️⃣ 最后打印所有结果，验证每个函数的输出与逻辑是否符合预期。                                      //验证每个函数的输出与逻辑是否符合预期。