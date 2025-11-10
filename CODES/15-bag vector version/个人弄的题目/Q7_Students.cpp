#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int score;
};

bool compare(const Student& a, const Student& b) {
    return a.score > b.score;
}

int main() {
    ifstream fin("input_samples/students.txt");
    if (!fin) return 1;
    vector<Student> v;
    Student s;
    while (fin >> s.name >> s.score) v.push_back(s);
    fin.close();

    // TODO 1: find top student
    // TODO 2: calculate average score
    // TODO 3: sort and write to "sorted.txt"
}
