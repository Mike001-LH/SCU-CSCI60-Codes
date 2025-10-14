// This file illustrates a working C++ class that stores and manages
// simple bank account information. Note the following:
// - Typically member functions (including constructors) are public, and
//   member variables are private (enforcing the information hiding principle).
// - Compared to other functions, constructors have special syntax for 
//   declaring, defining, and calling them.
// - If you define any constructor, you should define a 0-arg constructor also.
// - Accessor (getter) functions return values associated with member variables.
// - Simple functions can be defined inline (within the class definition), 
//   and others can be defined outside the class using scope resolution.
// Sara Krehbiel, CSCI 60, 9/29/25

#include <iostream> 
using namespace std; 

/* class definition */ 

class BankAccount {
public:
	// declaration for a 2-arg constructor
	BankAccount(string acctHolder, double initialAmt); 

	// definition of a 0-arg constructor using an initialization section
	BankAccount() : name("Jenny"), bal(0) { } 

	// a getter to return the balance
	double getBalance() { return bal; }	// an inline function definition

	// a mutator to increment the balance
	void deposit(double amtToDeposit);

	// a mutator to decrement balance (if allowed) and return modified balance
	double withdraw(double amtToWithdraw); 

private:
	string name;
	double bal; // note: double bal=0 is allowed but not the normal way to initialize
};

/* definitions for all member functions not defined inline */

// initialize new account with provided name and initialAmt up to 50000
BankAccount::BankAccount(string acctHolder, double initialAmt) {
	name = acctHolder;
	if (initialAmt<=50000) bal = initialAmt;
	else bal=50000;
	// TODO: discuss this->bal and partial use of initialization section
}

// increments bal only if specified amtToDeposit is at most 50000
void BankAccount::deposit(double amtToDeposit) {
	if (amtToDeposit<=50000) bal += amtToDeposit; // or bal=bal+amtToDeposit
}

// decrements bal by specified amt only if bal>=amtToWithdraw and returns bal
double BankAccount::withdraw(double amtToWithdraw) {
	if (bal>=amtToWithdraw) bal-=amtToWithdraw;
	return bal;
}

/* a driver program using instances of the class */

int main() {
	// declare a BankAccount object by first invoking a 0-arg constructor
	BankAccount acct1; // compare to a declaration like int n;
	//BankAccount acct1(); // WARNING: this is not a constructor call

	// access and modify member variables using public interface
	//cout << "Default balance: " << acct1.bal << endl; // bal is private
	cout << "Balance for default account: " << acct1.getBalance() << endl;
	//acct1.bal = 1000000; // illegal because bal is private
	//acct1.getBalance() = 1000000; // not syntactically valid
	acct1.deposit(1000000); // class logic leaves object unchanged
	cout << "Balance after $1M deposit: " << acct1.getBalance() << endl;
	acct1.deposit(100); // modifies the balance as desired
	cout << "Balance after $100 deposit: " << acct1.getBalance() << endl;
	//acct1.withdraw(20); // can call withdraw as void function
	// or do both in one step if withdraw return modified balance as below
	cout << "Balance after $20 withdrawal: " << acct1.withdraw(20) << endl;
	cout << "Balance after $100 withdrawal: " << acct1.withdraw(100) << endl;

	// declare another BankAccount object by invoking a 2-arg constructor
	BankAccount acct2("sk", 100);	
	// TRY: define a new getter and cout the name and balance for each object
	return 0;
}

