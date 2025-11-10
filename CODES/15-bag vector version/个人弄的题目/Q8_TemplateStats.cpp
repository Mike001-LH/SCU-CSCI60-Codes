#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void readAndAnalyze(const string& filename) {
    ifstream fin(filename);
    if (!fin) { cerr << "Cannot open file.\n"; return; }

    vector<T> data;
    T val;
    while (fin >> val) data.push_back(val);
    fin.close();

    // TODO 1: compute count / min / max / avg and print
}

int main() {
    readAndAnalyze<int>("input_samples/numbers.txt");
    readAndAnalyze<double>("input_samples/scores.txt");
}
