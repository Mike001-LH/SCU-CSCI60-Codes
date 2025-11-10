#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("input_samples/scores.txt");
    if (!fin) return 1;

    vector<double> v;
    double x;
    while (fin >> x) v.push_back(x);
    fin.close();

    // TODO 1: calculate average
    // TODO 2: sort the vector
    // TODO 3: print results
}
