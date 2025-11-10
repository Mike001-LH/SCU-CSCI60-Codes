#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("input_samples/numbers.txt");
    if (!fin) { cerr << "File not found!"; return 1; }

    vector<int> nums;
    int n;
    while (fin >> n) nums.push_back(n);
    fin.close();

    // TODO: print the square of each number
}
