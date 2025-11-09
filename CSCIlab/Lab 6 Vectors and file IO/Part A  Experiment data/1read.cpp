/*
1.  Write code to read in all the scores from the file and store them into a vector.
Your code should work for a similarly formatted file of any length. 
You should then compute the average AND the number of scores, and print both values out to the terminal.
Run your code to be sure it's right, check your answer with one of the lab teachers and copy-paste your code into your lab report before moving on.
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
	ifstream infile("scores.txt");//open the file
	vector<double> scores; //vector to store scores	
	int num;

	//read scores from file
	while (infile >> num) {
		scores.push_back(num);//push_back means to add to the end of the vector
	}
	//compute average and sum
	double sum = 0.0;
	for (double score : scores) {//for (double score : scores) means for each score in scores
		sum += score;
	}
	double average = sum / scores.size();
	cout << "Number of scores: " << scores.size() << endl;
	cout << "Average score: " << average << endl;
}