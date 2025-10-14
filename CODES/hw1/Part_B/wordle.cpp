// TODO: When finished, write a file comment that describes the program.
// Write your name and date, and cite any outside resources.

//wordle game, c++ version
//By Mike(Rentian Dong)
//Date: 2025/9/27

/*
program description:
This is text-based a game that gives a Wordle with 5-letter words and 6 guesses.
*/

//C++ Reference: cppreference.com/isalpha
/*
int isalpha( int ch );
功能：判断一个字符是否是 字母（A–Z 或 a–z）。
如果是字母 → 返回非零（通常是 1）。
如果不是字母 → 返回 0。
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cctype> // toupper

using namespace std;

// program constants
const string FILENAME = "wordbank.txt";
const int NUM_LETTERS = 5;
const int NUM_GUESSES = 6;

// helper function declarations
string getWord();                 // pick a random word from file and UPPERCASE it

/* TODO: declare additional helper functions here */
void giveInstructions();          // print game instructions
string getGuess();                // read a guess, force uppercase, validate length
string processGuess(string guess, string secret); // "*", "!", "-"

/* TODO: when done, give an overview of how your program works */
int main() {
	/* TODO: modify this to give instructions and play the game */
	//step1: print game rules
	giveInstructions();

	//step2: choose a ramdom secret word from wordbank.txt
	string secret = getWord();
	//cout << "Secret: " << secret << endl; // for testing(debug); comment out for release

	//step3: gameplay loop, player can try at most 6 times
	for (int trial=1; trial <=NUM_GUESSES; trial++){
		//let user input a guess, then automatically convert it into uppercase
		string guess = getGuess();

		//compare guesses with secret and get feed back with "*", "!", "-"
		string feedback = processGuess(guess, secret); // report letter-by-letter similarity of a guess to a secret word
		cout << feedback << endl;

		//if all letters match ("*****""), player wins
		if (feedback == string(NUM_LETTERS, '*')){	//string(NUM_LETTERS, '*') means: feedback == "******"
			cout << "You guessed the word!" << endl;
			return 0;
			// game ends on win
		}
	}

	// Step 4: if ran out of guesses, reveal the secret word
    cout << "Sorry, you did not guess the word. The word was: " << secret << endl;
	return 0;
}

// helper function definitions 
void giveInstructions(){
	cout << "\nWelcome to wordle! Try to guess a 5-letter word." << endl;
	cout << "When you guess, the program will report whether each letter:" << endl;
	cout << "  * is in the correct spot" << endl;
	cout << "  ! is in the word in the wrong spot" << endl;
	cout << "  - is not in the word" << endl;
	cout << "E.g., if the secret were PLANE a guess and response might be:" << endl;
	cout << "  train" << endl;
	cout << "  --*-!" << endl;
}

// Prompts the user for a guess, validates input, and converts to uppercase 
string getGuess(){ //by the way, I found that the toupper in <cctype> can also be used to capitalize the letters
	string guess;
	while (true){
		cin >> guess;

		//check if the guess has exactly 5 letters, if not, restart the while loop and input guess again
		if((int)guess.size() != NUM_LETTERS){
			cout << "your guess must be 5 letters, please try again!" << endl;
			continue;//skip to the next turn of the while loop
		}

		//check if all characters are alphabetic(letters), if not, restart the while loop and input guess again
		bool allLetters = true;
		for (char c : guess){
			// use isalpha with unsigned char to avoid undefined behavior
			// unsigned char is a 1-byte integer type that can only store 0 - 255, and is often used to avoid errors in character functions (as required by isalpha/toupper).	“一个只能存储正整数的字节”		范围是 0 到 255
			if(!isalpha((unsigned char)c)){//use isalpha to check whether it is letter(return 1) or not(return 0)
				allLetters = false;
				break; //end and get out of the for loop
			}
		}

		if(!allLetters){
			cout << "your guess should only be letters, pleases try again!" << endl;
			continue;
		}

		// 如果通过所有检查，就跳出 while
		break;
	}

	// convert all letters to uppercase
	for (int i=0; i<guess.size(); ++i){
		char c = guess[i];
		if (c >= 'a' && c <= 'z'){//Determine whether it is a lowercase letter.
			guess[i] = char(c - 'a' + 'A'); //'A 'and'A' differ by 32 in the ASCII table. So convert to uppercase one by one
		}
	}
	return guess;
}

// Compares guess and secret, returns feedback string
// '*' = correct spot, '!' = letter exists but wrong index, '-' = not in word
string processGuess(string guess, string secret){
	string response = "";
	for(int i = 0; i < NUM_LETTERS;++i){
		char letter = guess[i];
		// check whether the ith letter is in the correct spot
		if(secret[i] == letter){
			response += "*";
		}
		else{
			// check whether the ith letter is (elsewhere) in the secret
			bool in_word = false;
			for (int j = 0; j < NUM_LETTERS; ++j){
				if(secret[j] == letter){
					in_word = true;
					break;
				}
			}
			//add symbol to response depending on presence
			if(in_word){
				response += "!";
			}
			else{
				response += "-";
			}
		}
	}
	return response;
}

// Reads all words from wordbank.txt into a vector, picks a random word from word.txt at random, converts to uppercase, and returns it
string getWord() {
	// open the file
	ifstream f(FILENAME);
	// read words line-by-line into a vector (array-like data structure)
	vector<string> allWords;
	string word;

	// read line by line, each line should contain a word
	while (getline(f,word)) {
		allWords.push_back(word);
	}
	// close the file
	f.close();

	// pick a random word from the vector and capitalize its letters
	srand(time(nullptr));
	word = allWords[rand()%allWords.size()];

	// convert to uppercase
	for (int i=0; i<word.length(); i++) {
		word[i] = toupper(word[i]);
	}
	return word;
}





/*
code logic graph:(generated by AI)
┌────────────────────┐
│       main()       │
└───────┬────────────┘
        │
        ▼
┌────────────────────┐
│ giveInstructions() │  print game rules
└───────┬────────────┘
        │
        ▼
┌────────────────────┐
│    getWord()       │  pick random word & uppercase
└───────┬────────────┘
        │
        ▼
┌─────────────────────────┐
│ Loop trial = 1 → 6      │
└───────────┬─────────────┘
            │
     ┌──────▼───────┐
     │ getGuess()   │  input + validate
     └──────┬───────┘
            │
            ▼
     ┌────────────────────┐
     │ processGuess()     │  generate feedback (*,!, -)
     └──────┬─────────────┘
            │
   ┌────────▼─────────┐
   │ Print feedback   │
   └────────┬─────────┘
            │
    ┌───────▼─────────┐
    │ All '*' ?       │
    └───────┬─────────┘
        YES │  NO
            │
    ┌───────▼───────┐       ┌──────────────────────────┐
    │ Print victory │       │ If trial=6 and not solved│
    │ End program   │       │ Print secret word & exit │
    └───────────────┘       └──────────────────────────┘
*/















	//abondaned codes

	//cin >> guess;
	// while((int)guess.size() != NUM_LETTERS){
	// 	cout << "your guess must be 5 letters, please try again!" << endl;
	// 	cin >> guess; // enter guess again once it is not 5 letters
	// }

	// for (char c : guess) { //loop through the range for to access each character in "guess" in turn 用范围 for 循环依次访问 guess 里的每个字符
	// 	if (!isalpha((unsigned char)c)) { //C++ Reference: cppreference.com/isalpha   // 如果某个字符不是字母（用 isalpha 判断）//说明：int isalpha( int ch ); 参数必须是 unsigned char 范围内的值，或 EOF，否则结果未定义。
	// 	// 这里强制转成 unsigned char 是因为：
    //     // C++ 标准规定 isalpha 等 <cctype> 函数要求传入 unsigned char 或 EOF。
    //     // 如果直接传 char（在部分实现中 char 是 signed），遇到 ASCII >127 的字符
    //     // （比如中文或特殊符号），会变负数，导致未定义行为。
	// 	cout << "your guess should only be letters, pleases try again!" << endl;
	// 	cin >> guess; // enter guess again once it is not letters
	// 	}
	// }