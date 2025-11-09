/*
1 Phone (15 points)

On the next page, define a class that represents a phone. 
Your class should keep track of the name of the phone¡¯s owner, whether it is on, and its remaining battery life.
It should include the following member functions, which may be defined inline:

Write a 1-argument constructor that specifies the owner according to the parameter and initializes the phone to be fully charged and off.

Write a 1-argument function usePhone that does nothing if the phone is off. 
If it¡¯s on, it depletes the battery by an amount specified by the parameter;
if this amount is greater than the battery life left, the battery life goes to zero and the phone turns off.

Write a function recharge that returns the phone (on or off) to full battery life.

Write a function togglePower that turns the phone off if it is on and on if it is off.

Write a one-sentence comment about of why your class should or should not have a destructor.

Extra credit: Overload the insertion operator for your class; only declare it for partial extra credit.
*/
#include <iostream>
#include <string>
using namespace std;

class Phone {
private:
	string owner;
	bool isOn;
	int batteryLife;
public:
	//1-arg construtor
	Phone(string name) : owner(name), isOn(false), batteryLife(100) {}
	//1-arg function usePhone
	void usePhone(int amount) {
		if (isOn) {
			if (amount >= batteryLife) {
				batteryLife = 0;
				isOn = false;
			} else {
				batteryLife -= amount;
			}
		}
	}
	//function recharge
	void recharge() {
		batteryLife = 100;
	}
	//function togglePower
	void togglePower() {
		isOn = !isOn;
	}
	//comment about destructor:
	// This class does not need a destructor because it does not allocate any dynamic memory.

	//Extra credit: Overload the insertion operator
	friend ostream& operator<<(ostream& os, const Phone& p) {
		os << "Phone owner: " << p.owner << " | power: " << (p.isOn ? "On" : "Off") << " | battery life: " << p.batteryLife << "%";
		return os;
	}
};

int main() {
	Phone myPhone("John");

	cout << myPhone << endl;  // Phone Owner: John | Power: OFF | Battery: 100%

	myPhone.togglePower();
	cout << myPhone << endl;  // Phone Owner: John | Power: ON | Battery: 100%

	myPhone.usePhone(30);
	cout << myPhone << endl;  // Phone Owner: John | Power: ON | Battery: 70%

	myPhone.usePhone(80);
	cout << myPhone << endl;  // Phone Owner: John | Power: OFF | Battery: 0%

	myPhone.togglePower();
	cout << myPhone << endl;  // Phone Owner: John | Power: ON | Battery: 0%

	myPhone.recharge();
	cout << myPhone << endl;  // Phone Owner: John | Power: ON | Battery: 100%

	return 0;
}