#include <iostream>
using namespace std;
/*class definition*/
//1, mod class, two constructors
class ModInt{
	public:
		ModInt(int v, int m); 
		ModInt();
		//Getter function
		int getValue() const {//const is used for self-protection, to prevent getters functions from accidentally changing value.
			return value;
		}
		int getMod() const {//const is used for self-protection, to prevent getters functions from accidentally changing mod.
			return mod;
		}
		void plusEq(ModInt rhs);//Add another ModInt to itself (i.e. the effect of +=).
	private:
		int value;
		int mod;
};
/*
成员变量
value：存储数值（经过取模之后保证落在 [0, mod-1]）。
mod：存储模数。

构造函数
ModInt(int v, int m)：带参数的构造函数。
ModInt()：默认构造函数（初始化 value=0, mod=1）。

Getter 函数
getValue() 和 getMod()，带 const 保护，保证调用时不会修改对象。

成员函数
plusEq()：把另一个 ModInt 加到自己身上（即 += 的效果）。
*/

/*constructor function*/
ModInt::ModInt(int v, int m){ //2-arg constructor //v is value, m is mod
	if(m <= 0){ // if mod is less than 0, then it is an impossible situation, turn both v & m into -1
		value = -1;
		mod = -1;
		return;//End early at here to avoid executing the normal branch below
	}
	else{ // if there is no extreme situation
		mod = m;
		value = ((v % m) + m) % m;//if value is negative, mod it to get a negative number, add mod then mod it again, make sure the value is between [0, mod-1]
	}
}; 
/*
逻辑：
如果模数 m <= 0，就直接把 value 和 mod 设成 -1 表示非法状态。
否则，对 v 做“规范化取模”：
v % m 可能是负数，所以加上 m 再取模，保证结果在 [0, m-1]。
*/

ModInt::ModInt() : value(0), mod(1){}; //0-arg constructor //: is used to initialize value and mod //Remember!

//2, non-member function equals()
bool equals(ModInt lhs, ModInt rhs){
	if(lhs.getMod()==rhs.getMod()&&rhs.getValue()==lhs.getValue()){
		return true;
	}
	else{
		return false;
	}
};
/*
用来比较两个 ModInt 是否“相等”（包括模数相同、数值相同）。
注意这是 非成员函数，只能通过 public Getter 访问数据。
*/

//3, member function plusEq()
void ModInt::plusEq(ModInt rhs){
	//check if there is attempts to add ModInts with different mods, then update the ModInt it’s called on with -1 as both a mod and a value
	if(mod != rhs.getMod()){//member function can access private variable in the function
		value = -1;
		mod = -1;
		return;
	}
	//int sum = value + rhs.getValue();
	//add numbers with the same mod: do (a + b) modulo and normalize
	value = ((value + rhs.getValue())%mod + mod)% mod;//prevent negative number 
};
/*
功能：执行 模加法。
逻辑：
如果模数不同 → 设为非法状态 (-1,-1)。
否则：value = (value + rhs.value) % mod，同样用 ( + mod ) % mod 防止负数结果。
*/
//↑↑↑↑↑Why must this be a member function?
//My answer: because a member function can help me access the private variable value and mod in the ModInt class and change them directly

//4, non-member function plus() //Function: Returns the sum of lhs and rhs
ModInt plus(ModInt lhs, ModInt rhs){
	if (lhs.getMod() != rhs.getMod()) return ModInt(-1, -1);
    ModInt res = lhs;   // make a copy and doesn't change the original one
    res.plusEq(rhs);    // reuse member function plusEq()
    return res;
}
/*
功能：返回 lhs + rhs 的结果，而不修改原来的两个对象。
逻辑：
如果模数不同 → 返回非法 (-1,-1)。
否则：复制 lhs，然后调用 plusEq() 得到结果。

好处：和 plusEq 区分，plusEq 改对象，plus 只返回新对象。
*/

int main(){
	//testing constructor and Getter function
	ModInt currentSong(175, 180);
	cout << currentSong.getValue() << endl;
	cout << currentSong.getMod() << endl;

	//testing equals() function
	ModInt skipSong(6, 180);
	cout << (equals(currentSong, skipSong) ? "true" : "false") << endl;

	//testing member function plusEq
	currentSong.plusEq(skipSong);  // (175+6)%180 = 1
    cout << currentSong.getValue() << " (expect 1)" << endl;

    //testing non-member function plus 
    ModInt s = plus(ModInt(10,12), ModInt(5,12)); // (10+5)%12 = 3
    cout << s.getValue() << " (expect 3)" << endl;

    return 0; 
}