// Implementation starter file for CSCI 60 Homework 2; due due Wednesday 10/8/25
// Comment functions below; list any collaborators and write your name here

#include "histogram.h"

//0-argument constructor to initialize all the values of the counts array to zero.
Histogram::Histogram() {
	// Initialize all counts to zero
	for (size_t i = 0; i <= MAX; i++) {
		counts[i] = 0;
	}
}

//1-argument constructor to read in a stream of whitespace-separated integers between 0 and MAX, keeping track of the number of occurrences of each value.
Histogram::Histogram(string filename) {
	// TODO: implement this stub function here!
	// Initialize all counts to zero at first //prevent garbage values
	for (size_t i = 0; i <= MAX; i++) {
		counts[i] = 0;
	}
	
	ifstream fin(filename); // open the file with the given filename //filename is a string variable that contains the name of the file to be opened
	int val;// initialize a variable, used to store one int value at a time
	while (fin >> val) {//read all the numbers in data.txt one by one //fin >> val的意思是从输入流fin中读取一个整数，并将其存储在变量val中。这个操作会自动跳过空白字符（如空格、换行符等），直到遇到一个有效的整数为止。
		//make sure value is between 0 and MAX, if not, skip!(value out of range)
		if (val <= (int)MAX && val >= 0) {//这里要把MAX强制转换成int类型，因为val是int类型，防止比较时出现警告
			counts[val]++;// val is the value from data.txt, while counts[val] is the number of times that val appears //val能取到0到MAX之间的值
		}
	}
}

//size()的作用是一个一个数遍历数组counts，把每个位置上的值（即每个数出现的次数）加起来，得到总的数的个数。
size_t Histogram::size() const {//size_t should be placed before the function name because it indicates the return type of the function.
	size_t total = 0;
	for (size_t i = 0; i <= MAX; i++) {//loop though all possible values
		total += counts[i];//add all values together to get the sum
	}
	return total;
}

//bug function, do not use
//size_t Histogram::min() const {
//	//size_t minimum = counts[0]; //this is wrong, because counts[0] means "the number of times value 0 appears", we need to find the smallest value that appears at least once
//	for (size_t i = 0; i <= MAX; i++) {
//		if (counts[i] > minimum) {//有错误
//			//minimum = i; //there is a bug here, minimum should be size_t type, not int type
//		}
//	}
//	return minimum;
//}

size_t Histogram::min() const {
	for (size_t i = 0; i <= MAX; ++i) {
		if (counts[i] > 0) return i;
	}
	return MAX + 1;              // 空直方图
}

//bug function, do not use
//size_t Histogram::max() const {	//problem： when i=MAX, i-- will cause i to be a very large number because size_t is unsigned
//	size_t maximum = 0;
//	for (size_t i = MAX; i >= 0; i--) {
//		if (counts[i] > maximum) {
//			maximum = i;
//		}
//	}
//	return maximum;
//}
size_t Histogram::max() const {
	for (int i = (int)MAX; i >= 0; --i) {//Traverse from large to small (e.g:9-0)//temporary use int to prevent the situation of negative number
		if (counts[i] > 0) {
			return i;//return the first value found(the biggist value)
		}
	}
	return MAX + 1;//If none of them appear (the array is all 0), the histogram is empty, and MAX + 1 is returned as an "error flag".
}

size_t Histogram::mode() const {
	size_t modeValue = 0;
	size_t maxCount = 0;
	for (size_t i = 0; i <= MAX; i++) {
		if (counts[i] > maxCount) {//counts[i] here means "the number of times value i appears", we need to find the value that appears the most times // The reason why it can be used is that all values have been read in the one-arg constructor
			maxCount = counts[i];
			modeValue = i;
		}
	}
	return modeValue;
}

size_t Histogram::median() const {
	size_t total = size();//use size again to obtain total number
	size_t medianNumber = 0;
	//solve special situation when there is no number in the histogram or only one number
	if (total == 0) return MAX + 1;//if there is no number, //return MAX + 1 as an error sign
	if (total == 1) return min();//if there is only one number, return that number//reuse min() function to get that number for convenience
	//now solve the normal situation when there are more than one number
	//first situation: when total is odd
	if (total % 2 == 1) {
		// Case 1: Odd number of data points (奇数个数据)
		// Example: {1, 2, 3, 4, 5} → middle one is index 2 → value 3
		size_t mid = total / 2; // mid is the rank (0-based)
		size_t cum = 0; // cumulative counter (前缀和) //用来记录当前已经数到第几个数了
		for(size_t i=0; i<=MAX; i++){
			cum += counts[i];//add the number of times value i appears to cum
			if(cum > mid) return i;//once cumulative count > mid, we have reached the median value.
		}
	}
	//second situation: when total is even
	else {
		// Case 2: Even number of data points (偶数个数据)
		// Example: {1, 2, 3, 4} → middle two are 2 and 3 → (2+3)/2 = 2 //index for calculating middle number is right=4/2=2, left=4/2-1=1. thus we are looking for: 
		//When the accumulation exceeds the second (i.e., cum > 2), the current position i is the value of the left median.
		//When the accumulation exceeds the third (i.e., cum > 3), the current position i is the value of the right median.
		size_t midLeft = total / 2 - 1;
		size_t midRight = total / 2;//mid1Left and mid2Right are parts of the median, we need to find both of them and then average them
		size_t cum = 0; // cumulative counter (前缀和) //用来记录当前已经数到第几个数了
		size_t left = 0, right = 0;// placeholders for left and right median values
		for (size_t i = 0; i <= MAX; i++) {
			cum += counts[i];
			// When cumulative count exceeds 'midLeft' for the first time, record left
			if (cum > midLeft && left == 0) left = i;//once left is recorded, it will never change
			// When cumulative count exceeds 'midRight', record right and stop
			if (cum > midRight) { right = i; break; }
		}
		return (left + right) / 2;//there is a bug, this can't return a double number like(7+6)/2=6.5 because the return type is size_t
	}
	return MAX + 1; //error sign, just in case, prevent situation when nothing happens above
}

double Histogram::mean() const {
	double sum = 0;
	size_t total = size();
	if (total == 0) return MAX + 1;

	for (size_t i = 0; i <= MAX; i++) {
		sum += i * counts[i];
	}
	return sum / total;
}

//variance = Σ [count(v) * (v - mean)^2] / total
/*example:
  data = {1, 2, 2, 2, 2, 3, 3, 9}
  mean = 3.0
  variance = [1*(1-3)² + 4*(2-3)² + 2*(3-3)² + 1*(9-3)²] / 8 = 5.5
*/
double Histogram::variance() const {
	size_t total = size();//use size again to obtain total number
	if (total == 0) return 0;
	double meanNumber = mean();
	double sumSequence = 0; //initialize sumSq Σ (xᵢ - μ)²
	for (size_t i = 0; i <= MAX; i++) { //
		sumSequence += counts[i] * (i - meanNumber) * (i - meanNumber);
	}
	return sumSequence / total;
}
/* TODO: implement the functions declared in histogram.h here */
//overload the operators
//member function
//Overload the += operator as a member function. The command hist1 += hist2;
void Histogram::operator +=(const Histogram& rhs) {// add each rhs count to these counts//rhs是
	for (size_t i = 0; i <= MAX; i++) {
		counts[i] += rhs.counts[i];//counts[i] is hist1, rhs.counts[i] is hist2
	}
} 

//Overload the [] operator as a member function. The command hist[val] returns how many times the value val occurs in the histogram.
size_t Histogram::operator [](size_t val) const {// # times value occurs
	// Out-of-range guard: valid values are 0..MAX (inclusive).
	if (val > MAX) return 0;

	// counts[val] stores how many times 'val' occurs.
	return counts[val];
}

//// method 1: buggy version(do not use) will print some unnecessary lines like "0:" or "10:"
////this function is used to print the whole Histogram, but it doesn't match the format in hw2.pdf
////non-member function
//ostream& operator <<(ostream& out, const Histogram& h){//out means
//// Loop through all possible values (0 to MAX).
//// Histogram::MAX is a static constant shared by all Histogram objects.
//// Note: This is defined *outside* the class, since the left operand (cout) is an ostream, not a Histogram.
//	for (size_t i = 0; i <= Histogram::MAX; i++) {//this is a non-member function, so we need to use :: to get MAX. MAX represent the maximum measurable value of this Histogram object.
//		// Only output rows for values that actually appear in the data.
//		// h[i] calls Histogram::operator[], which returns how many times value i occurred.
//			//In C++, the base type ostream represents any kind of output stream:So by writing: ostream& out, we make the function flexible — it can print to the screen, a file, or even a string.
//			//We use out instead of cout because out is a general output stream parameter. 
//			//It can represent cout, a file stream, or any other ostream, making the operator<< function flexible and reusable for all kinds of output.
//			out << i << ": ";
//			// Print one '*' for each occurrence of the value i.
//			for (size_t j = 0; j < h[i]; j++) {//h[i] is the "number of occurrences of the value i".
//				out << "*";
//			}
//			out << endl; // End the line after printing all stars for this value.
//	}
//	return out;
//}

// method 1 (improved):
// This function prints only the meaningful part of the histogram,
// from the first non-zero value to the last non-zero value (inclusive).
// That means no "0:" or "10:" lines will appear.
ostream& operator<<(ostream& out, const Histogram& h) {//out means output stream //h means the Histogram object to be printed
	/*当你在主函数写：
	Histogram hist("data.txt");
	cout << hist;
	*/
	// ------------------------------------------------------------
	// Step 1: Find the first non-zero count index
	// ------------------------------------------------------------
	size_t first = Histogram::MAX + 1; // Initialize to invalid index
	for (size_t i = 0; i <= Histogram::MAX; ++i) {
		if (h[i] > 0) {                // Found the first non-zero value
			first = i;
			break;//exit the loop once the first non-zero value is found
		}
	}

	// ------------------------------------------------------------
	// Step 2: Find the last non-zero count index
	// ------------------------------------------------------------
	size_t last = 0;                   // Initialize to 0 by default
	for (int i = (int)Histogram::MAX; i >= 0; --i) {
		if (h[i] > 0) {                // Found the last non-zero value
			last = i;
			break;//exit the loop once the last non-zero value is found
		}
	}

	// ------------------------------------------------------------
	// Step 3: Handle the empty histogram case
	// ------------------------------------------------------------
	if (first == Histogram::MAX + 1)   // No non-zero elements found
		return out;                    // Return stream directly (no output)

	// ------------------------------------------------------------
	// Step 4: Print only values between [first, last]
	// ------------------------------------------------------------
	for (size_t i = first; i <= last; ++i) {
		out << i << ": ";              // Output the value label and colon
		for (size_t j = 0; j < h[i]; ++j)//h[i] is the "number of occurrences of the value i".// h[i] calls Histogram::operator[], which returns how many times value i occurred.//h[i]之所以可以calls Histogram::operator[] is because h is a Histogram object
			out << '*';                // Print one '*' for each occurrence

		// Only print newline if not the last line
		if (i < last)
			out << '\n';
	}

	// ------------------------------------------------------------
	// Step 5: Return the output stream to allow chained calls
	// Example: cout << hist1 << hist2 << endl;
	// ------------------------------------------------------------
	return out;//return out  is able to return the same output stream so that multiple < < can be used continuously (chain calls)
}


////method2: using chain calls :buggy version(do not use) will print some unnecessary lines like "0:" or "10:"
////non-member function
//ostream& operator <<(ostream& out, const Histogram& h) {
//	//Find the beginning and end (if empty, return directly)
//	size_t low = h.min();//smallest value with positive count
//	size_t high = h.max();//largest value with positive count
//	if (low == Histogram::MAX + 1) return out; // empty histogram, no output
//
//	// output from low to high（only print value that appears）
//	for (size_t i = low; i <= high; ++i) {
//		size_t c = h[i];           // number of occurrences of value i
//		out << i << ": ";          // output number and ": "
//		for (size_t j = 0; j < c; ++j) out << '*'; 
//		if (i < high) out << '\n';   // 行尾换行；最后一行可不强制多打一行
//	}
//	return out;//return out  is able to return the same output stream so that multiple < < can be used continuously (chain calls)
//	//out is the output stream object //We return a reference to it, making this function support "chained output".
//	//For example: cout << hist1 << hist2 << endl;		Actual execution order:((cout << hist1) << hist2) << endl;
//	//Returns out after each execution of operator < <, This way, the cout object can continue to be used by the next < <.//If don't return out, this link will compile incorrectly.
//}

/*
// method 2 imporved version(using chained stream insertion):
// This version also prints the histogram only from the first non-zero value
// to the last non-zero value (inclusive), but keeps cleaner formatting.
// It supports chained output, e.g. cout << hist1 << hist2 << endl;
ostream& operator<<(ostream& out, const Histogram& h) {
	// ------------------------------------------------------------
	// Step 1: Find the first and last indices with non-zero counts
	// ------------------------------------------------------------
	size_t first = Histogram::MAX + 1; // first non-zero index (invalid by default)
	size_t last = 0;                   // last non-zero index

	// Find first non-zero
	for (size_t i = 0; i <= Histogram::MAX; ++i) {
		if (h[i] > 0) {
			first = i;
			break;
		}
	}

	// Find last non-zero
	for (int i = (int)Histogram::MAX; i >= 0; --i) {
		if (h[i] > 0) {
			last = i;
			break;
		}
	}

	// ------------------------------------------------------------
	// Step 2: Handle empty histogram (no output at all)
	// ------------------------------------------------------------
	if (first == Histogram::MAX + 1)
		return out;

	// ------------------------------------------------------------
	// Step 3: Output histogram lines from [first .. last]
	// ------------------------------------------------------------
	for (size_t i = first; i <= last; ++i) {
		out << i << ": ";              // Label and colon
		size_t count = h[i];           // How many times the value appears
		for (size_t j = 0; j < count; ++j)
			out << '*';                // Print one '*' per occurrence

		if (i < last)
			out << '\n';               // Newline except on the last line
	}

	// ------------------------------------------------------------
	// Step 4: Return the same output stream
	// This allows chained output such as:
	//   cout << hist1 << hist2 << endl;
	// which is internally evaluated as:
	//   ((cout << hist1) << hist2) << endl;
	// ------------------------------------------------------------
	return out;
}
*/


/*MY debugging notes & result:
lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/7-bag/个人练习/StrBag
$ cd "D:\Sublime Text\CODES\hw2\HW2 by myself"

lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw2/HW2 by myself
$ g++ histogram.cpp main.cpp -std=c++11 -o histogram
histogram.cpp: In constructor ‘Histogram::Histogram(std::string)’:
histogram.cpp:18:33: error: ‘Max’ was not declared in this scope; did you mean ‘max’?
   18 |         for (size_t i = 0; i <= Max; i++) {
	  |                                 ^~~
	  |                                 max
histogram.cpp: In member function ‘size_t Histogram::min() const’:
histogram.cpp:44:25: error: ‘mimimum’ was not declared in this scope; did you mean ‘minimum’?
   44 |                         mimimum = i;
	  |                         ^~~~~~~
	  |                         minimum
histogram.cpp: In member function ‘size_t Histogram::max() const’:
histogram.cpp:53:33: error: ‘minimum’ was not declared in this scope; did you mean ‘maximum’?
   53 |                 if (counts[i] > minimum) {
	  |                                 ^~~~~~~
	  |                                 maximum
histogram.cpp:54:25: error: ‘mimimum’ was not declared in this scope; did you mean ‘maximum’?
   54 |                         mimimum = i;
	  |                         ^~~~~~~
	  |                         maximum
histogram.cpp: In member function ‘size_t Histogram::mode() const’:
histogram.cpp:69:25: error: expected ‘;’ before ‘}’ token
   69 |         return modeValue
	  |                         ^
	  |                         ;
   70 | }
	  | ~
histogram.cpp: In member function ‘size_t Histogram::median() const’:
histogram.cpp:103:43: error: ‘a’ was not declared in this scope
  103 |                         if (cum > left && a == 0) a = i;//once a is recorded, it will never change
	  |                                           ^
histogram.cpp:105:44: error: ‘b’ was not declared in this scope
  105 |                         if (cum > right) { b = i; break; }
	  |                                            ^
histogram.cpp:107:25: error: ‘a’ was not declared in this scope
  107 |                 return (a + b) / 2;//there is a bug, this can't return a double number like(7+6)/2=6.5 because the return type is size_t
	  |                         ^
histogram.cpp:107:29: error: ‘b’ was not declared in this scope
  107 |                 return (a + b) / 2;//there is a bug, this can't return a double number like(7+6)/2=6.5 because the return type is size_t
	  |                             ^
histogram.cpp: In member function ‘double Histogram::variance() const’:
histogram.cpp:126:16: error: ‘sum’ was not declared in this scope
  126 |         return sum / total;
	  |                ^~~

lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw2/HW2 by myself
$  g++ histogram.cpp main.cpp -std=c++11 -o histogram
histogram.cpp: In member function ‘size_t Histogram::median() const’:
histogram.cpp:120:43: error: ‘a’ was not declared in this scope
  120 |                         if (cum > left && a == 0) a = i;//once a is recorded, it will never change
	  |                                           ^
histogram.cpp:122:44: error: ‘b’ was not declared in this scope
  122 |                         if (cum > right) { b = i; break; }
	  |                                            ^
histogram.cpp:124:25: error: ‘a’ was not declared in this scope
  124 |                 return (a + b) / 2;//there is a bug, this can't return a double number like(7+6)/2=6.5 because the return type is size_t
	  |                         ^
histogram.cpp:124:29: error: ‘b’ was not declared in this scope
  124 |                 return (a + b) / 2;//there is a bug, this can't return a double number like(7+6)/2=6.5 because the return type is size_t
	  |                             ^
histogram.cpp: In member function ‘double Histogram::variance() const’:
histogram.cpp:154:16: error: ‘sum’ was not declared in this scope
  154 |         return sum / total;
	  |                ^~~

lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw2/HW2 by myself
$ g++ histogram.cpp main.cpp -std=c++11 -o histogram

lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw2/HW2 by myself
$ histogram.exe
-bash: histogram.exe: command not found

lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw2/HW2 by myself
$ ./histogram.exe
testing start!
Total count = 8
Min = 1
Max = 9
Mode = 2
Median = 2
Mean = 3
Variance = 5.5

Histogram:
1: *
2: ****
3: **
9: *

lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw2/HW2 by myself
$ ./histogram.exe
testing start!
Total count = 8
Min = 1
Max = 9
Mode = 2
Median = 2
Mean = 3
Variance = 5.5

Histogram:
0:
1: *
2: ****
3: **
4:
5:
6:
7:
8:
9: *
10:
11:
12:
13:
14:
15:
16:
17:
18:
19:
20:
21:
22:
23:
24:
25:
26:
27:
28:
29:
30:
31:
32:
33:
34:
35:
36:
37:
38:
39:
40:
41:
42:
43:
44:
45:
46:
47:
48:
49:
50:
51:
52:
53:
54:
55:
56:
57:
58:
59:
60:
61:
62:
63:
64:
65:
66:
67:
68:
69:
70:
71:
72:
73:
74:
75:
76:
77:
78:
79:
80:
81:
82:
83:
84:
85:
86:
87:
88:
89:
90:
91:
92:
93:
94:
95:
96:
97:
98:
99:
100:

lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw2/HW2 by myself
$ g++ histogram.cpp main.cpp -std=c++11 -o histogram

lenovo@LAPTOP-5TV5FB1B /cygdrive/d/Sublime Text/CODES/hw2/HW2 by myself
$ ./histogram
testing start!
Total count = 8
Min = 1
Max = 9
Mode = 2
Median = 2
Mean = 3
Variance = 5.5

Histogram:
1: *
2: ****
3: **
4:
5:
6:
7:
8:
9: *


*/