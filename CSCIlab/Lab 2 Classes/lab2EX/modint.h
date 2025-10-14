// modint.h
#ifndef MODINT_H
#define MODINT_H

class ModInt {
public:
    // 构造函数
    ModInt();                  // 0-arg：默认设为 value=0, mod=1
    ModInt(int v, int m);      // 2-arg：若 m<=0 → 错误态(-1,-1)；否则把 v 归一化到 [0, m-1]

    // Getters（头文件中写成内联/或只声明、到cpp里定义都可）
    int getValue() const;
    int getMod() const;

    // 题3：成员函数（原地+=），不同 mod → 把自身变成(-1,-1)
    void plusEq(ModInt rhs);

private:
    int value;
    int mod;
};

// 题2：相等性（非成员）
bool equals(ModInt lhs, ModInt rhs);

// 题4：非成员 plus（不同 mod 返回(-1,-1)）
ModInt plus(ModInt lhs, ModInt rhs);

// 题5：非成员 mult（不同 mod 返回(-1,-1)）
ModInt mult(ModInt lhs, ModInt rhs);

// 题6：非成员比较（不同 mod → 返回 false）
bool lessThan(ModInt lhs, ModInt rhs);
bool greaterThan(ModInt lhs, ModInt rhs);

#endif // MODINT_H
