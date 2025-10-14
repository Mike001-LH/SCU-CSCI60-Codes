//CSCI 60 hw2 Implementation File - Member Function Implementation of Histogram Class
//function: implements all interface functions
//by Rentian Dong(Mike) Date: 2025/10/8

// Implementation starter file for CSCI 60 Homework 2; due due Wednesday 10/8/25
// Comment functions below; list any collaborators and write your name here

#include "histogram.h"
//#include <fstream> //interface histogram.h already contains #include <fstream>, so this is unnecessary

//step1: write a 0-argument constructor to initialize all the values of the counts array to zero. //check histogram.h: line 14; line27
Histogram::Histogram(){
	for(size_t i=0; i<=MAX; i++){//size_t is an integer type of C++. It is unsigned (cannot be negative).//MAX is largest value that can be stored
		counts[i]=0;
	}
}

//step2: write a 1-argument constructor to read in a stream of whitespace-separated integers between 0 and MAX, keeping count the number of occurrences of each integer.
/*Hint: You must manually initialize the array to 0 before reading.
When testing, you can temporarily add cout print debugging information to the constructor.*/
Histogram::Histogram(string filename) {
	// TODO: implement this stub function here!
	for(size_t i=0; i<=MAX; i++){
		counts[i]=0;//initialize the value
	}

	ifstream fin("data.txt");//open file data.txt   //ifstream fin(filename); 使用变量 filename 里的字符串。动态决定要读哪个文件
	int val;

	while(fin >> val){ //read all the numbers in data.txt one by one
		//val is a signed integer (int). MAX is an unsigned integer (size_t).
		//In comparison, if one variable is unsigned, the other variable will be forcibly changed to unsigned. if negative int value is turned into size_t, it cause error!
		//When compared in this way, both val and MAX are of type int, which does not trigger dangerous type promotion.
		if(val>=0 && val<=(int)MAX){//make sure value is between 0 and MAX, if not, skip the out-of-range value //Since MAX is a size_t value, we have to turn it back to int
			counts[val]++;//histogram.h: line 27 //When I read an integer val from the file, I increase its corresponding count by one
		}
		/*↓for testing only, it will output integers in data.txt one by one
		-------------------------------------------------------------------------------------
		//cout << val << endl;
		-------------------------------------------------------------------------------------
		Objective 1: Make sure the file path is correct (the program does open and reads data.txt).
		Objective 2: Verify that the loop logic is correct (no overreads or missed reads)
		Objective 3: Verify type safety (negative or out-of-bounds values do not enter judgment statements)
		*/
		 
	}
	fin.close();//close the file data.txt after use(important)!
}

/* step3: TODO: implement the functions declared in histogram.h here */
//step3.1: time to write basic functions, write size() function to return the sum of the counts across all values.
//The size of the histogram is the sum of the counts across all values
size_t Histogram::size() const{ //Counts can never be negative, so use size_t instead of int //const is used to prevent changes in value
	size_t total = 0;
	for(size_t i=0; i<=MAX; i++){
		total += counts[i]; //add all values together to get the sum
	}
	return total;
}

//step3.2: write function min and max to return the smallest and largest number with positive count.//note that it is the value of number, not the value of frequency!
size_t Histogram::min() const{
	for(size_t i=0; i<=MAX; i++){//Traverse from small to large (e.g:0-9)
		if(counts[i] > 0){
			return i;//retrun the first value found(the smallest value)
		}
	}
	return MAX + 1;//If none of them appear (the array is all 0), the histogram is empty, and MAX + 1 is returned as an "error flag".
}

size_t Histogram::max() const{
	for(int i=(int)MAX; i>=0; --i){//Traverse from large to small (e.g:9-0)//temporary use int to prevent the situation of negative number
		if(counts[i] > 0){
			return i;//return the first value found(the biggist value)
		}
	}
	return MAX + 1;//If none of them appear (the array is all 0), the histogram is empty, and MAX + 1 is returned as an "error flag".
}

//step4: write a mode function to return the mode. mode(众数) is the value that occurred with highest frequency;
size_t Histogram::mode() const{
	size_t maxCount=0, modValue=0;
	for(size_t i=0; i<=MAX; i++){
		if(counts[i] > maxCount){
			maxCount=counts[i];
			modValue=i;
		}
	}
	return modValue;
}

//step5: write a median function to return the median. The median(中位数) is the 50th percentile value.
size_t Histogram::median() const{
	size_t total = size(); //reuse size() function to get the number of all values.
	if(total == 0) return MAX + 1;//if there is no number, return MAX + 1 as an error sign
	if (total % 2 == 1) {
		// Case 1: Odd number of data points (奇数个数据)
        // Example: {1, 2, 3, 4, 5} → middle one is index 2 → value 3
	    size_t mid = total / 2; // mid is the rank (0-based) of the middle value.
	    size_t cum = 0; // cumulative counter (前缀和)
	    for (size_t i = 0; i <= MAX; i++) {
	        cum += counts[i];
	        // As we accumulate frequencies, once cumulative count > mid,
            // we have reached the median value.
	        if (cum > mid) return i;
	    }
	} else {
		// Case 2: Even number of data points (偶数个数据)
        // Example: {1, 2, 3, 4} → middle two are 2 and 3 → (2+3)/2 = 2 //index for calculating middle number is right=4/2=2, left=4/2-1=1. thus we are looking for: 
		//When the accumulation exceeds the second (i.e., cum > 2), the current position i is the value of the left median.
		//When the accumulation exceeds the third (i.e., cum > 3), the current position i is the value of the right median.
        size_t left = total / 2 - 1;  // index (0-based) of the left middle element
        size_t right = total / 2;     // index (0-based) of the right middle element
        size_t cum = 0;               // cumulative count
        size_t a = 0, b = 0;          // placeholders for left and right median values
	    for (size_t i = 0; i <= MAX; i++) {
	        cum += counts[i];
	        // When cumulative count exceeds 'left' for the first time, record a
	        if (cum > left && a == 0) a = i;//once a is recorded, it will never change
	        // When cumulative count exceeds 'right', record b and stop
	        if (cum > right) { b = i; break; }
	    }
	    // Return the integer average of the two middle values, which is the median
	    return (a + b) / 2;
	}
	return MAX + 1;//Supplementary safety cover (theoretically it won't trigger, but the compiler will feel at ease)
}

//step6: write a mean function to return mean. The mean is the sum of all the values (with repetition) divided by the total number of values
double Histogram::mean() const{
	double sum = 0;
	size_t total = size();
	if(total == 0) return MAX + 1;

	for(size_t i=0; i<=MAX; i++){
		sum += i*counts[i];
	}
	return sum/total;
}

//step7: write a variance function to return variance. The variance is the mean squared difference between the values and their mean.
// Formula: σ² = ( Σ (xᵢ - μ)² ) / N
// where:
//   σ² = variance
//   xᵢ = each data value
//   μ  = mean (average value)
//   N  = total number of values
// In this histogram, counts[i] represents how many times value i occurs. // example：(1 · (1 − 3.0)^2 + 4 · (2 − 3.0)^2 + 2 · (3 −3.0)^2 +1·(9−3.0)^2)/8 = 5.5
double Histogram::variance() const{
	double m = mean();
	size_t total = size();
	double sumSq = 0.0;//initialize sumSq Σ (xᵢ - μ)²
	if (total == 0) return 0;

    for (size_t i = 0; i <= MAX; i++) {
        sumSq += (i - m) * (i - m) * counts[i];// Σ (xᵢ - μ)² 
    }
    return sumSq / total;//σ² = ( Σ (xᵢ - μ)² ) / N
}

//step8: overload the operators
//step8.1: Overload the += operator as a member function.(Let the two histograms add, item by item by index. (hist1 += hist2;))
/*For example: When you write h1 += h2; in main, the compiler will call the above function to add each counts [i] of h2 to counts [i] of h1.
 An example of creating a Histogram object is in main.cpp*/
void Histogram::operator +=(const Histogram& rhs){
	for(size_t i=0; i<=MAX; i++){
		counts[i]+=rhs.counts[i];//histogram.h line 27
	}
}

//step8.2: Overload the [] operator as a member function. This command hist[val] should return the count of the value val.
//(Supports array access.(cout << hist[4]; // cout number of times that 4 appears)
size_t Histogram::operator [](size_t val) const{
	// Out-of-range guard: valid values are 0..MAX (inclusive).
    if (val > MAX) return 0;

    // counts[val] stores how many times 'val' occurs.
    return counts[val];
}

//step8.3: Overload the << operator as a non-member function. (For printing histograms)
/*
Only output rows with more than 0 occurrences.
The colons are not required to be perfectly aligned.
Rows with values less than 1 or greater than 9 are not output.
& (after ostream) means Return by reference. So we can chain outputs like cout << h1 << h2;
(ostream& out, const Histogram& h): 
out comes from The output stream object on the left side of <<. Where the text will be printed (for example, cout)
h is the Histogram object on the right side of <<. It is the histogram we want to display
*/
/*Notes:
ostream is Output stream type (from <iostream>) Represents any output stream such as cout, ofstream, etc.
*/
// Example usage: cout << h1 << h2;   // works because the function returns ostream&
ostream& operator <<(ostream& out, const Histogram& h){//& means getting the address //Here h is a Histogram object (e.g. Histogram h ("data.txt");),
	// Loop through all possible values (0 to MAX).
    // Histogram::MAX is a static constant shared by all Histogram objects.
    // Note: This is defined *outside* the class, since the left operand (cout) is an ostream, not a Histogram.
	for(size_t i = 0; i <= Histogram::MAX; ++i){////this is a non-member function, so we need to use :: to get MAX. MAX represent the maximum measurable value of this Histogram object.
		// Only output rows for values that actually appear in the data.
        // h[i] calls Histogram::operator[], which returns how many times value i occurred.
		if(h[i] > 0){
			//In C++, the base type ostream represents any kind of output stream:So by writing: ostream& out, we make the function flexible — it can print to the screen, a file, or even a string.
			//We use out instead of cout because out is a general output stream parameter. 
			//It can represent cout, a file stream, or any other ostream, making the operator<< function flexible and reusable for all kinds of output.
			out << i << ": ";
			// Print one '*' for each occurrence of the value i.
			for (size_t j = 0; j < h[i]; j++) {//h[i] is the "number of occurrences of the value i".
				out << "*";
			}
            out << endl; // End the line after printing all stars for this value.
		}
	}
	return out;
}


