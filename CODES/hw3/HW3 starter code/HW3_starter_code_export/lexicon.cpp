// Implementation starter file for CSCI 60 Homework 3; due Friday 10/17/25
// List any collaborators and write your name here

#include "lexicon.h"

/* TODO: reimplement this 1-arg constructor to ignore repeats */
Lexicon::Lexicon(string filename) : size_(0) {
  ifstream in(filename);
  string word;
  while (in >> word && size_<CAPACITY) {
    data_[size_++] = word;
  }
  in.close();
}

/* TODO: implement the other functions declared in lexicon.h here */

// Inserts contents of lex in out in order, separated by spaces
ostream& operator <<(ostream& out, const Lexicon & lex) {
  size_t n = lex.size();
  for (size_t i=0; i<n; i++) {
    out << lex[i] << " ";
  }
  return out;
}
