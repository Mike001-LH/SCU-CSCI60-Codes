// 本文件演示了一个可用的 C++ 类，用来存储并管理
// 简单的银行账户信息。注意以下要点：
// - 通常成员函数（包括构造函数）是 public，
//   而成员变量是 private（以实现“信息隐藏”原则）。
// - 与其他函数相比，构造函数在“声明、定义与调用”上都有特殊语法。
// - 一旦你自定义了任意构造函数，通常也应该提供一个“无参（0-arg）构造函数”。
// - 访问器（getter）函数用于返回与成员变量相关的值。
// - 简单函数可以内联定义（写在类定义内部），
//   其他函数则可以使用作用域解析符在类外定义。
// Sara Krehbiel, CSCI 60, 2025/9/29

#include <iostream> 
using namespace std; 

/* 类的定义 */ 

class BankAccount {
public:
	// 声明：带两个参数的构造函数
	BankAccount(string acctHolder, double initialAmt); 

	// 定义：无参构造函数，使用“成员初始化列表”进行初始化
	BankAccount() : name("Jenny"), bal(0) { } 

	// getter：返回余额
	double getBalance() { return bal; }	// 内联函数定义

	// 修改器（mutator）：给余额增加存款
	void deposit(double amtToDeposit);

	// 修改器：在允许的情况下减少余额，并返回修改后的余额
	double withdraw(double amtToWithdraw); 

private:
	string name;
	double bal; // 说明：也可以写成 double bal=0，但这不是常用的初始化方式
};

/* 对所有未内联定义的成员函数进行类外定义 */

// 使用提供的姓名与初始金额初始化新账户；初始金额上限为 50000
BankAccount::BankAccount(string acctHolder, double initialAmt) { //::作用域解析符号, 意思是BankAccount函数隶属于BankAccount这个类
	name = acctHolder;
	if (initialAmt<=50000) bal = initialAmt;
	else bal=50000;
	// TODO: 讨论 this->bal 的用法，以及“成员初始化列表的部分使用”
}

// 只有当存入金额不超过 50000 时才增加余额
void BankAccount::deposit(double amtToDeposit) { //::作用域解析符号, 意思是deposit函数隶属于BankAccount这个类
	if (amtToDeposit<=50000) bal += amtToDeposit; // 等价于 bal = bal + amtToDeposit
}

// 当且仅当当前余额 >= 取款额时才扣减余额，并返回余额
double BankAccount::withdraw(double amtToWithdraw) { //::作用域解析符号, 意思是withdraw函数隶属于BankAccount这个类
	if (bal>=amtToWithdraw) bal-=amtToWithdraw;
	return bal;
}

/* 一个使用该类实例的驱动程序（示例主程序） */

int main() {
	// 通过调用无参构造函数来声明一个 BankAccount 对象
	BankAccount acct1; // 声明并创建一个 BankAccount 类型的对象，名字叫 acct1。可与 int n; 这样的声明对比
	//BankAccount acct1(); // 警告：这不是构造函数调用（“最具迷惑性的解析”问题）。这在 C++ 里不是调用构造函数，而是被解析成 函数声明：声明了一个叫 acct1 的函数，返回类型是 BankAccount，参数是空。



	// 通过 public 接口访问与修改成员
	//cout << "Default balance: " << acct1.bal << endl; // bal 是 private，无法直接访问
	cout << "Balance for default account: " << acct1.getBalance() << endl;
	//acct1.bal = 1000000; // 非法：bal 是 private
	//acct1.getBalance() = 1000000; // 语法上无效
	acct1.deposit(1000000); // 按类中的业务规则，不会改变对象（因超限）
	cout << "Balance after $1M deposit: " << acct1.getBalance() << endl;
	acct1.deposit(100); // 合法修改余额
	cout << "Balance after $100 deposit: " << acct1.getBalance() << endl;
	//acct1.withdraw(20); // 可以把 withdraw 当作“返回值不使用的 void 风格调用”
	// 或者像下面这样，在一行里“取款 + 打印返回的新余额”
	cout << "Balance after $20 withdrawal: " << acct1.withdraw(20) << endl;
	cout << "Balance after $100 withdrawal: " << acct1.withdraw(100) << endl;

	// 通过调用带两个参数的构造函数再声明一个 BankAccount 对象
	BankAccount acct2("sk", 100);	
	// 练习：自己再定义一个 getter，然后分别输出每个对象的姓名与余额
	return 0;
}


/*
程序的最终输出：
Balance for default account: 0
Balance after $1M deposit: 0
Balance after $100 deposit: 100
Balance after $20 withdrawal: 80
Balance after $100 withdrawal: 80



分段分析
1. 创建默认账户
BankAccount acct1;
cout << "Balance for default account: " << acct1.getBalance() << endl;

调用无参构造函数：name="Jenny", bal=0
打印：
Balance for default account: 0


2. 尝试存入 $1,000,000
acct1.deposit(1000000);
cout << "Balance after $1M deposit: " << acct1.getBalance() << endl;

deposit 限制：单次最多存 50,000。
1,000,000 超过限制 → 存款被拒。
余额仍是 0。
打印：
Balance after $1M deposit: 0


3. 存入 $100
acct1.deposit(100);
cout << "Balance after $100 deposit: " << acct1.getBalance() << endl;

100 ≤ 50,000 → 存款有效。
余额更新为 0 + 100 = 100。
打印：
Balance after $100 deposit: 100


4. 取出 $20
cout << "Balance after $20 withdrawal: " << acct1.withdraw(20) << endl;

当前余额 100 ≥ 20 → 可以取。
新余额 = 100 - 20 = 80。
withdraw 返回新余额 80。
打印：
Balance after $20 withdrawal: 80


5. 尝试取出 $100
cout << "Balance after $100 withdrawal: " << acct1.withdraw(100) << endl;

当前余额 = 80，小于 100 → 取款失败。
余额保持 80。
函数返回当前余额 80。
打印：
Balance after $100 withdrawal: 80

*/







/*
================================================================================
                         Using BankAccounts  —— class client
================================================================================
 main()
 └─ 声明对象与调用接口

  BankAccount acct1;                BankAccount acct2("sk", 100);
  // ↑无参构造（默认值）            // ↑有参构造（自定义初值）

  [defaultAcct : BankAccount]       [myAcct : BankAccount]
  +---------------------------+     +---------------------------+
  | name : "Jenny"            |     | name : "sk"               |
  | bal  : 0                  |     | bal  : 100                |
  +---------------------------+     +---------------------------+

  调用轨迹（acct1）：
   1) acct1.getBalance()  → 0
   2) acct1.deposit(1_000_000)  → 忽略（单次存款上限 50000）
   3) acct1.deposit(100)  → bal=100
   4) acct1.withdraw(20)  → bal=80（返回 80）
   5) acct1.withdraw(100) → 余额不足，bal 仍为 80（返回 80）

  重要提示：
   - BankAccount acct1;     ✅ 创建对象，调用无参构造
   - BankAccount acct1();   ❌ “最具迷惑性的解析”：这是函数声明，不是对象
================================================================================


================================================================================
                      Designing a BankAccount  —— class designer
================================================================================
 接口 interface（public）
 ┌─────────────────────────────────────────────────────────────────────────────┐
 │ // 构造函数                                                                 │
 │ BankAccount();                         // 无参：成员初始化列表               │
 │   → : name("Jenny"), bal(0)            //   在函数体执行前完成初始化         │
 │ BankAccount(string acctHolder, double initialAmt);                          │
 │                                                                             │
 │ // 访问器（getter）                                                         │
 │ double getBalance();                 // 内联；读取私有成员 bal               │
 │                                                                             │
 │ // 修改器（mutator）                                                        │
 │ void   deposit(double amtToDeposit); // 存款：单次 ≤ 50000 才生效           │
 │ double withdraw(double amtToWithdraw);// 取款：余额 ≥ 取款额才扣，并返回     │
 └─────────────────────────────────────────────────────────────────────────────┘

 实现 implementation（类外定义，使用作用域解析符 ::）
 ┌─────────────────────────────────────────────────────────────────────────────┐
 │ BankAccount::BankAccount(string acctHolder, double initialAmt) {            │
 │   this->name = acctHolder;              // 左：成员；右：参数                │
 │   if (initialAmt <= 50000) bal = initialAmt; else bal = 50000;              │
 │ }                                                                           │
 │ void BankAccount::deposit(double amt) { if (amt <= 50000) bal += amt; }     │
 │ double BankAccount::withdraw(double amt){ if (bal >= amt) bal -= amt; return│
 │   bal; }                                                                    │
 └─────────────────────────────────────────────────────────────────────────────┘

 数据 data（private）
 ┌─────────────────────────────────────────────────────────────────────────────┐
 │ string name;                                                                │
 │ double bal;                                                                 │
 └─────────────────────────────────────────────────────────────────────────────┘

 关键语法速记：
  - ::   作用域解析符：类外定义成员，如 BankAccount::deposit(...)
  - :    成员初始化列表：构造时“先于函数体”初始化（const/引用成员必须用）
  - this 当前对象指针；this->name = name 中“左成员 / 右参数”避免同名混淆
  - ->   指针访问成员：p->f() 等价于 (*p).f()
================================================================================

*/