#include <iostream>
using namespace std;

class BankAccount {
public:
    BankAccount(string acctName, double amt) : name(acctName), bal(amt) {}
    BankAccount() : name("Jenny"), bal(0) {}

    double getBalance() { return bal; }
    void deposit(double amt) { if (amt > 50000) bal += amt; }
    void withdraw(double amt) { if (bal >= amt) bal -= amt; }
	//首先，我们写一个getter函数来获取账户名称
    string getName() { return name; }

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
    //Write code in main that outputs the state of both accounts: cout the name and balance associated with acct1 on one line,
    //and cout the name and balance associated with acct2 on the second line.
	//注意，这里一定要用cout来输出账户信息，不能用return，否则终端不会显示任何信息
	//注意，这里一定要用getName()和getBalance()来获取账户名称和余额，如果直接写acct1.name和acct1.bal是无法访问的，因为它们是私有成员
    cout << acct1.getName() << " " << acct1.getBalance() << endl;
    cout << acct2.getName() << " " << acct2.getBalance() << endl;
}