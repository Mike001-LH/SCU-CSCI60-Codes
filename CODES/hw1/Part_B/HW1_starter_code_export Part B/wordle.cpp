// TODO: When finished, write a file comment that describes the program.
// Write your name and date, and cite any outside resources.

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

// program constants
const string FILENAME = "wordbank.txt";
const int NUM_LETTERS = 5;
const int NUM_GUESSES = 6;

// helper function declarations
string getWord();

/* TODO: declare additional helper functions here */

/* TODO: when done, give an overview of how your program works */
int main() {
	/* TODO: modify this to give instructions and play the game */

	string secret = getWord();
	cout << "Secret: " << secret << endl; // for testing; remove later!

	return 0;
}

// helper function definitions 

// picks a random word from the specified file
string getWord() {
	// open the file
	ifstream f(FILENAME);
	// read words line-by-line into a vector (array-like data structure)
	vector<string> allWords;
	string word;
	while (getline(f,word)) {
		allWords.push_back(word);
	}
	// close the file
	f.close();
	// pick a random word from the vector and capitalize its letters
	srand(time(nullptr));
	word = allWords[rand()%allWords.size()];
	for (int i=0; i<word.length(); i++) {
		word[i] = toupper(word[i]);
	}
	return word;
}

/* TODO: define your additional helper functions here */
