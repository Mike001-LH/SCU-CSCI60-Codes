// Driver program for our binary search tree class.
// Sara Krehbiel, 12/5/25

#include <iostream>
#include "bst.h"

using namespace std;

int main() {
  BST<string> words;
  words.insert("the");
  words.insert("quick");
  words.insert("brown");
  words.insert("fox");
  words.insert("jumped");
  words.insert("over");
  words.insert("the");
  words.insert("lazy");
  words.insert("dogs");

  cout << "Number of words: " << words.size() << endl;

  cout << "All words, with <<:\n" << words << endl;
  
  cout << "\"brown\" is " << (words.contains("brown")?"":"not ") << "there\n";
  cout << "\"red\" is " << (words.contains("red")?"":"not ") << "there\n";

  cout << "All words, with iterator:\n";
  for (auto word : words) cout << word << ", ";
  cout << endl;

  return 0;
}
