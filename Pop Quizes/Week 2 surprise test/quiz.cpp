/*
1. Add a getter to BankAccount to allow a class client to access the name associated with an account.
2. Write code in main that outputs the state of both accounts: cout the name and balance associated with acct1 on one line,
and cout the name and balance associated with acct2 on the second line.
*/

#include <iostream>
using namespace std;

class BankAccount {
public:
    BankAccount(string acctName, double amt) : name(acctName), bal(amt) {}
    BankAccount() : name("Jenny"), bal(0) {}

    double getBalance() { return bal; }
    void deposit(double amt) { if (amt > 50000) bal += amt; }
    void withdraw(double amt) { if (bal >= amt) bal -= amt; }

private:
    string name;
    double bal;
};

int main() {
    BankAccount acct1;
    acct1.deposit(100000);
    acct1.deposit(100);
    BankAccount acct2("Jane", 50);
    acct2.withdraw(30);
    acct2.withdraw(1000);
    acct1.withdraw(20);
}
