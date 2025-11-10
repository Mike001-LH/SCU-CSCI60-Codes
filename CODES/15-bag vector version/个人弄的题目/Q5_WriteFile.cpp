#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    vector<string> words;
    string s;
    cout << "Input words (type END to stop):\n";
    while (cin >> s && s != "END")
        words.push_back(s);

    ofstream fout("output.txt");
    // TODO 1: loop through words and write each on a new line
    // TODO 2: close the file and print "Done!"
}
