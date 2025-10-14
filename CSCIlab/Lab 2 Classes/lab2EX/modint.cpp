// modint.cpp
#include "modint.h"
#include <iostream> // 如果你需要打印调试可以留着；纯库实现可去掉

// 0-arg 构造
ModInt::ModInt() : value(0), mod(1) {}

// 2-arg 构造：m<=0 设为错误态；否则把 v 归一化
ModInt::ModInt(int v, int m) {
    if (m <= 0) {
        value = -1;
        mod = -1;
    } else {
        mod = m;
        // 保证 value 落在 [0, m-1]
        value = ((v % m) + m) % m;
    }
}

// Getters
int ModInt::getValue() const { return value; }
int ModInt::getMod()   const { return mod;   }

// 题3：成员函数 plusEq（原地+=）
// 同 mod 则 (value = (value + rhs.value) % mod)；不同 mod → 置为错误态(-1,-1)
void ModInt::plusEq(ModInt rhs) {
    if (mod != rhs.getMod() || mod <= 0 || rhs.getMod() <= 0 ||
        value < 0 || rhs.getValue() < 0) {
        value = -1;
        mod = -1;
        return;
    }
    int sum = value + rhs.getValue();
    value = ((sum % mod) + mod) % mod;
}

// 题2：equals（非成员）
bool equals(ModInt lhs, ModInt rhs) {
    return lhs.getMod() == rhs.getMod() &&
           lhs.getValue() == rhs.getValue();
}

// 题4：plus（非成员）——最简单是复用 plusEq：对副本做原地加
ModInt plus(ModInt lhs, ModInt rhs) {
    if (lhs.getMod() != rhs.getMod() || lhs.getMod() <= 0) {
        return ModInt(-1, -1);
    }
    lhs.plusEq(rhs);   // 已处理不同 mod → 错误态
    return lhs;
}

// 题5：mult（非成员）——用 long long 做中间乘积，避免溢出
ModInt mult(ModInt lhs, ModInt rhs) {
    if (lhs.getMod() != rhs.getMod()) return ModInt(-1, -1);
    int m = lhs.getMod();
    if (m <= 0 || lhs.getValue() < 0 || rhs.getValue() < 0) return ModInt(-1, -1);

    long long a = lhs.getValue();
    long long b = rhs.getValue();
    long long prod = (a * b) % m;
    int v = static_cast<int>((prod % m + m) % m);
    return ModInt(v, m);
}

// 题6：比较（非成员）——不同 mod 直接 false
bool lessThan(ModInt lhs, ModInt rhs) {
    if (lhs.getMod() != rhs.getMod()) return false;
    if (lhs.getMod() <= 0 || rhs.getMod() <= 0) return false;
    return lhs.getValue() < rhs.getValue();
}

bool greaterThan(ModInt lhs, ModInt rhs) {
    if (lhs.getMod() != rhs.getMod()) return false;
    if (lhs.getMod() <= 0 || rhs.getMod() <= 0) return false;
    return lhs.getValue() > rhs.getValue();
}
