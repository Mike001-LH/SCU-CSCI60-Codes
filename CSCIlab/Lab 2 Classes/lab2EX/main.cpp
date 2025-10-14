// main.cpp
#include <iostream>
#include "modint.h"
using namespace std;

int main() {
    // 基本构造与 getters
    ModInt a(175, 180), b(6, 180);
    cout << "a=" << a.getValue() << " mod " << a.getMod() << "\n";
    cout << "b=" << b.getValue() << " mod " << b.getMod() << "\n";

    // equals
    cout << boolalpha;
    cout << "equals(a, b) = " << equals(a, b) << "\n";

    // plusEq（原地 +=）
    a.plusEq(b); // (175+6)%180 = 1
    cout << "after a.plusEq(b): a=" << a.getValue() << " (expect 1)\n";

    // plus（返回新对象）
    ModInt c = plus(ModInt(7,13), ModInt(9,13)); // (7+9)%13 = 3
    cout << "plus(7 mod 13, 9 mod 13) = "
         << c.getValue() << " mod " << c.getMod() << " (expect 3 mod 13)\n";

    // mult
    ModInt p1 = mult(ModInt(7,13), ModInt(9,13)); // 63%13=11
    cout << "mult(7 mod 13, 9 mod 13) = "
         << p1.getValue() << " mod " << p1.getMod() << " (expect 11 mod 13)\n";

    // 比较
    cout << "lessThan(7 mod 13, 9 mod 13) = "
         << lessThan(ModInt(7,13), ModInt(9,13)) << " (expect true)\n";
    cout << "greaterThan(7 mod 13, 9 mod 13) = "
         << greaterThan(ModInt(7,13), ModInt(9,13)) << " (expect false)\n";

    // 不同 mod 的行为
    ModInt bad = mult(ModInt(175,180), ModInt(7,13));
    cout << "mult(175 mod 180, 7 mod 13) -> "
         << bad.getValue() << "," << bad.getMod() << " (expect -1,-1)\n";
    cout << "lessThan(175 mod 180, 7 mod 13) = "
         << lessThan(ModInt(175,180), ModInt(7,13)) << " (expect false)\n";

    return 0;
}
