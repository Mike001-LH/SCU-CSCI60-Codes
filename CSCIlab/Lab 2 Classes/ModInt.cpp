#include <iostream>
using namespace std;

class ModInt{

	public:
		ModInt(int a, int b);
		ModInt();
		int getNum(){
			return num;
		}
		int getMod(){
			return mod;
		}
		void plusEq(ModInt rhs);
	private:
		int mum;
		int mod;
}

ModInt::ModInt(int a, int b) {
	num=a;
	mod=b;
}

ModInt::ModInt(){
	num=0;
	mod=1;
}

bool equals(ModInt lhs, ModInt rhs){
	if(lhs.getNum() == rhs.getNum() && lhs.getMod() == rhs.getMod()){
		return true;
	}
	else{
		return false;
	}
}

void ModInt::plusEq(ModInt rhs){
	if(getMod() == rhs.getMod()){
		num=(getNum()+rhs.getNum())%rhs.getMod();
	}
	else{
		num=-1;
		mod=-1;
	}
}




int main(){
	ModInt currentSong(175, 180);
	cout << currentSong.getNum() << endl;
	cout << currentSong.getMod() << endl;
	return 0;
	ModInt skipSong(6, 180);
	cout << equals(currentSong, skipSong) << endl;
}

ModInt plus(ModInt lhs, ModInt rhs){
	int newNum = lhs.plusEq(rhs)
}