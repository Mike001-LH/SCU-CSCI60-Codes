/*
Change your code (AFTER copy-pasting the old version into your lab report!)
so that instead of printing the average to cout, it sends it to an output file.
After the average, you should also output all scores that were above the average to the file.
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
	infile.close();

	double sum = 0.0;
	for (double score : scores) {//for (double score : scores) means for each score in scores
		sum += score;
	}
	double average = sum / scores.size();

	ofstream outfile("output.txt");
	outfile << "Average: " << average << endl;
	outfile << "all scores that were above the average: " << endl;

	for (double score : scores) {
		if (score > average) {
			outfile << score << endl;
		}
	}
	outfile.close();
}