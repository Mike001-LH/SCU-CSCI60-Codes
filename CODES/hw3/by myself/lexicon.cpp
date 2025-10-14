// Implementation starter file for CSCI 60 Homework 3; due Friday 10/17/25
// List any collaborators and write your name here

#include "lexicon.h"

//step 1: fix the 1-arg constructor
/* TODO: reimplement this 1-arg constructor to ignore repeats */ //���1�ι���������ȷ//��û�к����ظ��ĵ���//��ֻ�Ǽ򵥵ذ��ļ��е�ǰCAPACITY�����ʶ���data_�����У�û�м���ظ�
//�޸Ľ��飺�ڲ���ÿ������֮ǰ���ȼ�����Ƿ��Ѿ�������data_�����У�����������ٲ���
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
//fixed version of the 1-arg constructor//���ã��������ļ��ж�ȡ���ظ��ĵ��ʣ��洢��data_�����У�ֱ���ﵽCAPACITYΪֹ
/*requirement:
1, Read up to CAPACITY non-repeating words from the input file.
2, The storage order is consistent with the order of appearance in the file.
3, Ignore repeated words.
4, Use == to determine whether words are the same (case sensitive! "Hello", "hello", "HELLO" are considered different words).
*/
Lexicon::Lexicon(string filename) : size_(0) {
	ifstream in(filename);// open the file
	string word;// to hold each word read in
	while (in >> word && size_ < CAPACITY) {// read each word until out of capacity//in >> word��˼�Ǵ��ļ��ж�ȡһ�����ʣ��洢��word������//ÿ��ȡһ�����ʣ�����Ĵ���ͻ�ִ��һ��
		//if (!contains(word)) {//contains() is a function in lexicon.h, if data_[] array does not already contain the word, contains() returns false
		//	data_[size_++] = word;// insert the word if it's not already in the lexicon
		//}
		//since I have not implemented contains() function yet, I will implement the logic of contains() function here
		bool found = false;
		for (size_t i = 0; i < size_; i++) {//reminder: size_ is the number of words already stored in data_[] array
			if (data_[i] == word) {
				found = true;
				break;//�ҵ��ظ��ĵ��ʺ�����ѭ������Ϊ�Ѿ�ȷ���������ظ�����
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
bool Lexicon::contains(string word) const {//���data_[]�������Ƿ����ָ������word
	for (size_t i = 0; i < size_; i++) {//go through each word in data_[] array
		if (data_[i] == word) {
			return true;//return true if the word is found
		}
	}
	return false;//return false if the word is not found
}
//member function 2: insert, inserts a word into data_[] array if it's not in data_[] array and the array is not out of capacity, returns true if inserted, false otherwise
//���ã���һ�����ʲ��뵽data_[]�����У�����õ��ʲ���������������δ��������벢����true�����򲻲��벢����false
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
//member function 4: union (|), returns a new lexicon that is the union��A | B��//���ģ�����һ���µ�lexicon����������lexicon�Ĳ�����A | B��//����������һ�������еĵ���
Lexicon Lexicon::operator |(const Lexicon& rhs) const {//�����һ��Lexicon�Ƿ������ͣ��ڶ���Lexicon��������operator |������|�������const Lexicon& rhs���Ҳ�����
	Lexicon result;
	for (size_t i = 0; i < size() && result.size() < CAPACITY; i++) {//��һ��������Ǻ��������ߣ�����������ĵ���
		result.insert(data_[i]);// �ȼ��� this->data_[i]
	}
	for (size_t i = 0; i < rhs.size() && result.size() < CAPACITY; i++) {
		if (!result.contains(rhs[i])) {//use result.contains() to check if result has this word, if not, insert it
			result.insert(rhs[i]);//rhs��һ�� Lexicon ����//�����rhs[i]��ͨ������[]���������rhs�ĵ���//rhs[i]��ͨ������ [] �������е��ַ�����
		}
	}
	return result;
}
//member function 5: intersection (&), returns a new lexicon that is the intersection��A & B��//���ģ�����һ���µ�lexicon����������lexicon�Ľ�����A & B��//���������������еĵ���
Lexicon Lexicon::operator &(const Lexicon& rhs) const {
	Lexicon first;
	Lexicon result;
	for (size_t i = 0; i < size(); i++) {//��һ�������Ǻ��������ߣ�����������ĵ���
		first.insert(data_[i]);
	}
	for (size_t i = 0; i < rhs.size(); i++) {
		if (first.contains(rhs[i])) {//use first.contains() to check if first has this word, if yes, insert it into result
			result.insert(rhs[i]);
		}
	}
	return result;
}
//member function 6: symmetric difference (^), returns a new lexicon that is the symmetric difference��A ^ B��//���ģ�����һ���µ�lexicon����������lexicon�ĶԳƲA ^ B��//����������һ�����ϵ���ͬʱ���������������еĵ���
//symmetric difference = (A - B) U (B - A),����A�е�����B�У�����B�е�����A�е�Ԫ��,����A={1,2,3},B={3,4,5},��A^B={1,2,4,5}
Lexicon Lexicon::operator ^(const Lexicon& rhs) const {
	Lexicon left;
	Lexicon right;
	Lexicon result;
	//first get the left difference (A - B)
	for (size_t i = 0; i < size() && result.size() < CAPACITY; i++) {//��һ�������Ǻ��������ߣ�����������ĵ���
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


// Inserts contents of lex in out in order, separated by spaces//����<<���������ӡlexicon������
ostream& operator <<(ostream& out, const Lexicon & lex) {
  size_t n = lex.size();
  for (size_t i=0; i<n; i++) {
    out << lex[i] << " ";
  }
  return out;
}

//step 4: Overload six comparison operators as nonmember functions: <=, <, >=, >, ==, and !=
//lex1 == lex2 is true if and only if every string in one of the lexicons is also in the other
//��ȣ��������ϰ����ĵ�����ȫ��ͬ��˳���޹أ�//Two lexicons are equal if they contain exactly the same words, regardless of order.
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

//����ȣ�ֻҪ������һ�����ʲ�ͬ��//not equal (if there is any word that is different)
bool operator !=(const Lexicon& lhs, const Lexicon& rhs) {
	return !(lhs == rhs);//use == operator we wrote above
}

//�Ӽ���lhs ��ÿ��Ԫ�ض��� rhs �У�//subset (every element of lhs is in rhs)
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

//���ģ����Ӽ���lhs �� rhs ���Ӽ��������߲���ȣ�//strict subset (lhs is a subset of rhs and they are not equal)
bool operator <(const Lexicon& lhs, const Lexicon& rhs) {
	return (lhs <= rhs) && (lhs != rhs);//use <= and != operators we wrote above
}

//������rhs ��ÿ��Ԫ�ض��� lhs �У�//superset (every element of rhs is in lhs)
bool operator >=(const Lexicon& lhs, const Lexicon& rhs) {
	return rhs <= lhs;//��<=��������
}

//�泬����lhs �� rhs �ĳ����������߲���ȣ�//strict superset (lhs is a superset of rhs and they are not equal)
bool operator >(const Lexicon& lhs, const Lexicon& rhs) {
	return (lhs >= rhs) && (lhs != rhs);//use >= and != operators we wrote above
}