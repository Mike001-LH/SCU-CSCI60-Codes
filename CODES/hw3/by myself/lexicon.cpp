// Implementation starter file for CSCI 60 Homework 3; due Friday 10/17/25
// List any collaborators and write your name here

#include "lexicon.h"

//step 1: fix the 1-arg constructor
/* TODO: reimplement this 1-arg constructor to ignore repeats */ //这个1参构造器不正确//它没有忽略重复的单词//它只是简单地把文件中的前CAPACITY个单词读入data_数组中，没有检查重复
//修改建议：在插入每个单词之前，先检查它是否已经存在于data_数组中，如果不存在再插入
/*
Lexicon::Lexicon(string filename) : size_(0) {
  ifstream in(filename);// open the file
  string word;// to hold each word read in
  while (in >> word && size_ < CAPACITY) {// read each word until out of capacity
    data_[size_++] = word;
  }
  in.close();
}
*/
//fixed version of the 1-arg constructor//作用：从输入文件中读取不重复的单词，存储在data_数组中，直到达到CAPACITY为止
/*requirement:
1, Read up to CAPACITY non-repeating words from the input file.
2, The storage order is consistent with the order of appearance in the file.
3, Ignore repeated words.
4, Use == to determine whether words are the same (case sensitive! "Hello", "hello", "HELLO" are considered different words).
*/
Lexicon::Lexicon(string filename) : size_(0) {
	ifstream in(filename);// open the file
	string word;// to hold each word read in
	while (in >> word && size_ < CAPACITY) {// read each word until out of capacity//in >> word意思是从文件中读取一个单词，存储在word变量中//每读取一个单词，下面的代码就会执行一次
		//if (!contains(word)) {//contains() is a function in lexicon.h, if data_[] array does not already contain the word, contains() returns false
		//	data_[size_++] = word;// insert the word if it's not already in the lexicon
		//}
		//since I have not implemented contains() function yet, I will implement the logic of contains() function here
		bool found = false;
		for (size_t i = 0; i < size_; i++) {//reminder: size_ is the number of words already stored in data_[] array
			if (data_[i] == word) {
				found = true;
				break;//找到重复的单词后，跳出循环，因为已经确定单词是重复的了
			}
		}
		if (!found) {//if the word is not found in data_[] array, insert it
			data_[size_++] = word;//size_++ because after inserting the word, the number of words in data_[] array increases by 1
		}
	}
}

/* TODO: implement the other functions declared in lexicon.h here */
//step2: Implement three boolean member functions: contains, insert,and remove consistent with the pre- and post-conditions stipulated in the header file.
//member function 1: contains, checks if a word is in the data_[] array, returns true if found, false otherwise
bool Lexicon::contains(string word) const {//检查data_[]数组中是否包含指定单词word
	for (size_t i = 0; i < size_; i++) {//go through each word in data_[] array
		if (data_[i] == word) {
			return true;//return true if the word is found
		}
	}
	return false;//return false if the word is not found
}
//member function 2: insert, inserts a word into data_[] array if it's not in data_[] array and the array is not out of capacity, returns true if inserted, false otherwise
//作用：将一个单词插入到data_[]数组中，如果该单词不在数组中且数组未满，则插入并返回true；否则不插入并返回false
bool Lexicon::insert(string word) {
	if (contains(word)||size_ >= CAPACITY) {
		return false;//the word is already in the data_[] array or the array is out of capacity, do not insert and return false
	}
	data_[size_++] = word;//size_++ because after inserting the word, the number of words in data_[] array increases by 1
	return true;
}
//member function 3: remove, removes a word from data_[] array if it's in the array, returns true if removed, false if not found
bool Lexicon::remove(string word) {
	for (size_t i = 0; i < size_; i++) {
		if (data_[i] == word) {
			//found the word to be removed, now remove it by shifting all subsequent words back
			for (size_t j = i; j < size_ - 1; j++) {//j<size_-1 because last word does not need to be shifted, it will be ignored after size_--
				data_[j] = data_[j + 1];//shift all subsequent words back one by one
				//example: if remove 2 in "1 2 3 4", then "1 3 4 4", the last 4 is garbage value, but size_ will -1, so it won't be accessed
			}
			size_--;//size_ -1 after removing a word.
			return true;//return true because the word was found and removed
		}
	}
	return false;//the word was not found
}

//step 3: Implement the three set operator overloads: union (|), intersection (&), and symmetric difference (^).
//member function 4: union (|), returns a new lexicon that is the union（A | B）//中文：返回一个新的lexicon，它是两个lexicon的并集（A | B）//出现在任意一个集合中的单词
Lexicon Lexicon::operator |(const Lexicon& rhs) const {//这里第一个Lexicon是返回类型，第二个Lexicon是类名，operator |是重载|运算符，const Lexicon& rhs是右操作数
	Lexicon result;
	for (size_t i = 0; i < size() && result.size() < CAPACITY; i++) {//这一步插入的是函数调用者（左操作数）的单词
		result.insert(data_[i]);// 等价于 this->data_[i]
	}
	for (size_t i = 0; i < rhs.size() && result.size() < CAPACITY; i++) {
		if (!result.contains(rhs[i])) {//use result.contains() to check if result has this word, if not, insert it
			result.insert(rhs[i]);//rhs是一个 Lexicon 对象//这里的rhs[i]是通过重载[]运算符访问rhs的单词//rhs[i]是通过重载 [] 访问其中的字符串。
		}
	}
	return result;
}
//member function 5: intersection (&), returns a new lexicon that is the intersection（A & B）//中文：返回一个新的lexicon，它是两个lexicon的交集（A & B）//出现在两个集合中的单词
Lexicon Lexicon::operator &(const Lexicon& rhs) const {
	Lexicon first;
	Lexicon result;
	for (size_t i = 0; i < size(); i++) {//这一步检查的是函数调用者（左操作数）的单词
		first.insert(data_[i]);
	}
	for (size_t i = 0; i < rhs.size(); i++) {
		if (first.contains(rhs[i])) {//use first.contains() to check if first has this word, if yes, insert it into result
			result.insert(rhs[i]);
		}
	}
	return result;
}
//member function 6: symmetric difference (^), returns a new lexicon that is the symmetric difference（A ^ B）//中文：返回一个新的lexicon，它是两个lexicon的对称差（A ^ B）//出现在其中一个集合但不同时出现在两个集合中的单词
//symmetric difference = (A - B) U (B - A),即在A中但不在B中，或在B中但不在A中的元素,例如A={1,2,3},B={3,4,5},则A^B={1,2,4,5}
Lexicon Lexicon::operator ^(const Lexicon& rhs) const {
	Lexicon left;
	Lexicon right;
	Lexicon result;
	//first get the left difference (A - B)
	for (size_t i = 0; i < size() && result.size() < CAPACITY; i++) {//这一步检查的是函数调用者（左操作数）的单词
		left.insert(data_[i]);
	}
	for (size_t i = 0; i < rhs.size() && result.size() < CAPACITY; i++) {
		if (left.contains(rhs[i])) {//use left.contains() to check if left has this word, if yes, remove it from left
			left.remove(rhs[i]);
		}
	}
	//then get the right difference (B - A)
	for (size_t i = 0; i < rhs.size() && result.size() < CAPACITY; i++) {
		right.insert(rhs[i]);
	}
	for (size_t i = 0; i < size() && result.size() < CAPACITY; i++) {
		if (right.contains(data_[i])) {//use right.contains() to check if right has this word, if yes, remove it from right
			right.remove(data_[i]);
		}
	}
	//now combine left and right into result, which is the symmetric difference
	for (size_t i = 0; i < left.size(); i++) {
		result.insert(left[i]);
	}
	for (size_t i = 0; i < right.size(); i++) {
		result.insert(right[i]);
	}
	return result;
}


// Inserts contents of lex in out in order, separated by spaces//重载<<运算符，打印lexicon的内容
ostream& operator <<(ostream& out, const Lexicon & lex) {
  size_t n = lex.size();
  for (size_t i=0; i<n; i++) {
    out << lex[i] << " ";
  }
  return out;
}

//step 4: Overload six comparison operators as nonmember functions: <=, <, >=, >, ==, and !=
//lex1 == lex2 is true if and only if every string in one of the lexicons is also in the other
//相等（两个集合包含的单词完全相同；顺序无关）//Two lexicons are equal if they contain exactly the same words, regardless of order.
bool operator ==(const Lexicon& lhs, const Lexicon& rhs) {
	if (lhs.size() != rhs.size()) {
		return false;//if sizes are different, they cannot be equal
	}
	for (size_t i = 0; i < lhs.size(); i++) {//compare each word in lhs with rhs
		if (!rhs.contains(lhs[i])) {
			return false;
		}
	}
	return true;//same size and all words in lhs and rhs match
}

//不相等（只要有任意一个单词不同）//not equal (if there is any word that is different)
bool operator !=(const Lexicon& lhs, const Lexicon& rhs) {
	return !(lhs == rhs);//use == operator we wrote above
}

//子集（lhs 的每个元素都在 rhs 中）//subset (every element of lhs is in rhs)
bool operator <=(const Lexicon& lhs, const Lexicon& rhs) {
	if (lhs.size() > rhs.size()) {
		return false;//lhs cannot be a subset of rhs if its size is larger
	}
	for (size_t i = 0; i < lhs.size(); i++) {//check each word in lhs
		if (!rhs.contains(lhs[i])) {
			return false;//if any word in lhs is not in rhs, lhs is not a subset of rhs
		}
	}
	return true;//if all words in lhs are in rhs, lhs is a subset of rhs
}

//中文：真子集（lhs 是 rhs 的子集，且两者不相等）//strict subset (lhs is a subset of rhs and they are not equal)
bool operator <(const Lexicon& lhs, const Lexicon& rhs) {
	return (lhs <= rhs) && (lhs != rhs);//use <= and != operators we wrote above
}

//超集（rhs 的每个元素都在 lhs 中）//superset (every element of rhs is in lhs)
bool operator >=(const Lexicon& lhs, const Lexicon& rhs) {
	return rhs <= lhs;//把<=反过来用
}

//真超集（lhs 是 rhs 的超集，且两者不相等）//strict superset (lhs is a superset of rhs and they are not equal)
bool operator >(const Lexicon& lhs, const Lexicon& rhs) {
	return (lhs >= rhs) && (lhs != rhs);//use >= and != operators we wrote above
}