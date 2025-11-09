/*1:
In a new file, create a class StudentInfo to hold the student¡¯s first and last name, their class level (First, Sophomore, Junior, Senior), and their GPA.
It should include a default constructor and a constructor that takes 4 parameters, as well as getters for your private fields.
Check your answer with one of the lab teachers before moving on.  You can wait until step 2 to copy-paste your code into your lab report
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class StudentInfo {
private:
	string firstName;
	string lastName;
	string classLevel;
	double gpa;
public:
	//default constructor
	StudentInfo() : firstName(""), lastName(""), classLevel(""), gpa(0) {}
	//4-arg constructor
	StudentInfo(string first, string last, string level, double GPA) : firstName(first), lastName(last), classLevel(level), gpa(GPA) {}
	//getter method
	string getFirstName() {
		return firstName;
	}
	string getLastName() {
		return lastName;
	}
	string getClassLevel() {
		return classLevel;
	}
	double getGPA() {
		return gpa;
	}
};

/*2:
Write code to read the data from the file into a vector of Students. Your code should work for a similarly formatted file of any length.
Run your code to be sure it's right, check your answer with one of the lab teachers and copy-paste your code into your lab report before moving on.
*/

int main() {
	ifstream infile("lab7studentlist.txt");
	vector<StudentInfo> student;
	string first, last, level;
	double GPA;
	while (infile >> first >> last >> level >> GPA) {
		student.push_back(StudentInfo(first, last, level, GPA));
	}
	infile.close();
	/*3.  
	Change your code so that it sends the average gpa to an output file. 
	After that, you should also output the first and last names of all students whose gpas were above the average to the file. 
	Run your code to be sure it's right, check your answer with one of the lab teachers and copy-paste your code into your lab report before moving on.
	*/
	double sum = 0.0;
	for (StudentInfo score : student) {
		sum += score.getGPA();
	}
	double average = sum / student.size();
	ofstream outfile("studentOutput.txt");
	outfile << "Average GPA: " << average << endl;
	outfile << "Students with GPA above average: " << endl;
	for (StudentInfo s : student) {
		if (s.getGPA() > average) {
			outfile << s.getFirstName() << " " << s.getLastName() << endl;
		}
	}
	outfile.close();
}

