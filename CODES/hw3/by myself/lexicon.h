// Interface file for CSCI 60 Homework 3; due Friday 10/17/25

#ifndef LEXICON_H
#define LEXICON_H

#include <cstdlib>
#include <iostream>
#include <fstream>
using std::string;
using std::ostream;
using std::ifstream;

class Lexicon {
public:

  // STATIC CONSTANT

  static const size_t CAPACITY = 2000;


  // CONSTRUCTORS

  // Pre:  N/A
  // Post: An empty (size 0) lexicon is created
  Lexicon() : size_(0) {}//内联定义的默认构造器，初始化size_为0，所以不用在lexicon.cpp中再写一遍

  // Pre:  A text file called filename is in the current directory
  // Post: A lexicon w/ the file's first ≤CAPACITY distinct strings is created
  Lexicon(string filename);


  // CONSTANT ACCESSOR MEMBER FUNCTIONS

  // Pre:  N/A
  // Post: The number of elements stored is returned
  size_t size() const { return size_; }

  // Pre:  N/A
  // Post: The truth value of whether the word is in the lexicon is returned
  bool contains(string word) const;

  // Pre:  This object has at least pos+1 elements
  // Post: The element at index pos is returned
  string operator [](size_t pos) const { return data_[pos]; }


  // MUTATOR MEMBER FUNCTIONS

  // Pre:  N/A
  // Post: The word is added to the end of the lexicon and true is returned
  //       if word was distinct and there was space; false is returned otherwise
  bool insert(string word);

  // Pre:  N/A
  // Post: If the word was present, it is removed and true is returned;
  //       false is returned otherwise
  bool remove(string word);


  // SET OPERATOR OVERLOADS

  // Pre:  N/A
  // Post: A union lexicon is constructed, populated with the first ≤CAPACITY
  //       distinct elements of this object and rhs, and returned
  Lexicon operator |(const Lexicon& rhs) const;

  // Pre:  N/A
  // Post: An intersection lexicon is constructed, populated with the elements
  //       common to this object and rhs, and returned
  Lexicon operator &(const Lexicon& rhs) const;

  // Pre:  N/A
  // Post: A symmetric difference lexicon is constructed, populated with
  //       the first ≤CAPACITY elements of this object XOR rhs, and returned
  Lexicon operator ^(const Lexicon& rhs) const;

private:

  // INVARIANTS: data_[0],...,data_[size_-1] always contain the elements

  string data_[CAPACITY];// array of strings, with unused entries unspecified
  size_t size_;// number of strings currently in the lexicon

};

// INSERTION OPERATOR OVERLOAD

// Pre:  N/A
// Post: Space-separated in-order contents of lex are inserted in out
ostream& operator <<(ostream& out, const Lexicon & lex);


// COMPARISON OPERATOR OVERLOADS

// Pre:  N/A
// Post: True is returned iff the contents of lhs and rhs are identical
bool operator ==(const Lexicon& lhs, const Lexicon& rhs);

// Pre:  N/A
// Post: True is returned iff the contents of lhs and rhs are not identical
bool operator !=(const Lexicon& lhs, const Lexicon& rhs);

// Pre:  N/A
// Post: True is returned iff the every lhs element is in rhs
bool operator <=(const Lexicon& lhs, const Lexicon& rhs);

// Pre:  N/A
// Post: True is returned if every lhs element is in rhs which is not identical
bool operator <(const Lexicon& lhs, const Lexicon& rhs);

// Pre:  N/A
// Post: True is returned iff the every rhs element is in lhs
bool operator >=(const Lexicon& lhs, const Lexicon& rhs);

// Pre:  N/A
// Post: True is returned iff every rhs element is in lhs which is not identical
bool operator >(const Lexicon& lhs, const Lexicon& rhs);


#endif
