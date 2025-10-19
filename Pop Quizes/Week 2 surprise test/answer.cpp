#include <iostream>
using namespace std;

class BankAccount {
public:
    BankAccount(string acctName, double amt) : name(acctName), bal(amt) {}
    BankAccount() : name("Jenny"), bal(0) {}

    double getBalance() { return bal; }
    void deposit(double amt) { if (amt > 50000) bal += amt; }
    void withdraw(double amt) { if (bal >= amt) bal -= amt; }
	//���ȣ�����дһ��getter��������ȡ�˻�����
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
	//ע�⣬����һ��Ҫ��cout������˻���Ϣ��������return�������ն˲�����ʾ�κ���Ϣ
	//ע�⣬����һ��Ҫ��getName()��getBalance()����ȡ�˻����ƺ������ֱ��дacct1.name��acct1.bal���޷����ʵģ���Ϊ������˽�г�Ա
    cout << acct1.getName() << " " << acct1.getBalance() << endl;
    cout << acct2.getName() << " " << acct2.getBalance() << endl;
}