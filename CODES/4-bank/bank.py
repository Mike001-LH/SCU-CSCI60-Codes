# This Python program defines a class analogous to the one in bank.cpp.
# Sara Krehbiel, CSCI 60, 9/26/25

class BankAccount:
	# constructor
	def __init__(self):
		# two attributes (member names in C++) maintained by an object
		self.name = 'Jenny Smith'
		self.balance = 0

	# instance methods (member functions in C++)
	def deposit(self,amt):
		self.balance += amt

	def withdraw(self,amt):
		if self.balance >= amt:
			self.balance -= amt


my_acct = BankAccount() # instantiation
print('Initial balance:',my_acct.balance) # attribute access uses dot operator
my_acct.deposit(2000) # calling an instance method also uses dot operator
print('Balance after deposit:',my_acct.balance)
my_acct.withdraw(150)
print('Balance after withdrawal:',my_acct.balance)
