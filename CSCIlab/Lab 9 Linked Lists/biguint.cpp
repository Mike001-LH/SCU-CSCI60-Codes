/*
Part A.  We¡¯ll be working with the biguint class again.
You¡¯ll be given a biguint class that uses a static array of fixed size,
and you¡¯ll be changing it so that it uses a linked list. 
You¡¯ll be given the class definition of the linked list biguint class.  Write the following member functions
*/
#include "biguint.h"

#include <cassert>
#include <sstream>
using namespace std;

 biguint::biguint(){

     for(int i = 0; i<CAPACITY; i++){

             _data[i] = 0;
     }
 }
 biguint::biguint (const string & s)
 {
     for (int i = 0; i < CAPACITY; ++i)
         _data[i] = 0;

     if (s.size() == 0)
         return;

     char c = s[0];
     int j(0);
     for (int i = s.size()-1; j < CAPACITY && i >= 0; --i)
     {
         assert(isdigit(s[i]));
         _data[j] = s[i] - '0';
         ++j;
     }
 }


 unsigned short biguint::operator [](int pos) const
 {
     assert(pos < CAPACITY);
     return _data[pos];
 }



 int biguint::compare(const biguint & b) const{
     for(int i =CAPACITY-1; i>=0; --i){
         if(_data[i]>b._data[i])
             return 1;
         else if (_data[i]<b._data[i])
             return -1;

     }
     return 0;
 }



 void biguint::operator += (const biguint & b){
     int carry = 0;
     int next = 0;
     for(int i=0; i<CAPACITY; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
 }
string biguint::toStdString() const
 {
     stringstream ss;
     ss << *this;
     return ss.str();
 }//We haven't talked about stringstreams; just ignore this, I was being lazy.
ostream & operator << (ostream & os, const biguint & b)
 {

     for (int i = biguint::CAPACITY - 1; i >= 0; --i)
         os << b[i];
     return os;
 }

istream & operator >> (istream & is, biguint & b)
 {
     string s;
     is >> s;
     b = biguint(s);
     return is;


 }

 bool operator <(const biguint& a, const biguint& b){
     return (a.compare(b)==-1);
 }

 bool operator <= (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) <= 0);
 }

 bool operator == (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) == 0);
 }

 bool operator != (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) != 0);
 }

//You do > and >=
