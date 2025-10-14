#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Change lowercase letters to uppercase
void toUpperInPlace(string& s){ //引用传递 //To modify s [i] is to modify str [i].
// written as string & s: This is passed by reference, that is, s becomes an alias for the string passed in from outside. 
// String & s can directly modify the external original string, rather than a copy.
	for (int i=0; i<s.size(); ++i){
		char c = s[i];
		if (c >= 'a' && c <= 'z'){//Determine whether it is a lowercase letter.
			s[i] = char(c - 'a' + 'A'); //'A 'and'A' differ by 32 in the ASCII table. So convert to uppercase one by one
		}
	}
}
 
bool isItLetter(char c){ //return true if it is a letter, return false if it is not a letter
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isFiveLetter(string s){
	if (s.size()!=5) return false; //make sure there are five letters in it
	for (int i = 0; i < 5; i++){
		if(!isItLetter(s[i])){
			return false;
		}
	}
	return true;
}

// Read a guess: getGuess
// Function: Prompt input, capitalize, check legitimacy (must be 5 letters).
string getGuess() {
	string guess;
	while(true){ //the while loop is repeated until it is legal, and every path is guaranteed to return
		cout << "Enter your guess: " << endl;
		cin >> guess;
		toUpperInPlace(guess);
		if (isFiveLetter(guess)) {
			cout << "you typed: " << guess << endl;
			return guess;
		}
		cout << "Please enter exactly 5 letters (A-Z)." << endl;
	}
	
}






// Determine if a letter is in the answer: charInWord
// Function: Find whether the character ch appears in the 5 positions of the secret.
bool charInWord(char ch, const string& secret){ //char ch--> Single character ch, value passing //const string& secret--> Secret is "a reference (&) to a string that is read-only (const) here." 只读引用，不能改
    for (int j = 0; j < 5; ++j){
        if (ch == secret[j]) return true;
    }
    return false;
}

// Rating: Same position = '*'; appears in other positions = '!'; not at all = '-'
// Rating function: scoreGuess
string scoreGuess(const string& guess, const string& secret){
    string res = "-----";				//treated as not in the word默认都当作不在单词中
    for (int i = 0; i < 5; ++i){		//check location by location
        if (guess[i] == secret[i]) 		//Same letter in the same index → '*'
        	res[i] = '*';
        else                       
        	res[i] = charInWord(guess[i], secret) ? '!' : '-';
        	//appears elsewhere → '!'； not at all → '-'
    }
    return res;							//Returns 5 strings of the form "--*-!"
}






int main(){
	//1) Print Welcome and Rules + Examples
	cout << "Welcome to wordle! Try to guess a 5-letter word." << endl;
	cout << "When you guess, the program will report whether each letter:" << endl;
	cout << "\t* is in the correct spot" << endl;
	cout << "\t! is in the word in the wrong spot" << endl;
	cout << "\t- is not in the word" << endl;
	cout << "E.g.,if the secret were PLANE a guess and response might be:\n";
	cout << "\ttrain\n" << "\t--*-!\n";
	cout << "The secret word has been selected. Start guessing!" << endl;

	//2) Set the answer and the maximum number of times
	const string secret = "PLANE"; //Temporarily use fixed answers
    const int MAX_TRY = 6; // number of trials




    //3) Main cycle: each read, score, print
    for (int t = 0; t < MAX_TRY; t++){
    	//Get and validate input
		string guess = getGuess();              // 获取并校验输入（已转大写）
        string fb    = scoreGuess(guess, secret);
        cout << guess << endl;
        cout << fb    << endl << endl;

        if (fb == "*****") {
            cout << "You guessed the word!" << endl;
            return 0;
        }
    }

    //4) Unable to guess 6 times: Failed and revealed the answer
	cout << "Out of guesses. The word was: " << secret << endl;
    return 0;
}

