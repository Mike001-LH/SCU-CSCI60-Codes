#include <iostream>
using namespace std;

int main() {
	void max_avg(int a[], int size, int* max, int* avg);
	void shuffle(int* a, int* b, int* c);
	int* max_addr(int a[], int size);
}

//write a function void max_avg(int a[], int size, int *max, int *avg) that stores the maximum of the values in a into the memory max points to,
// and stores the average of the values into the memory avg points to.
void max_avg(int a[], int size, int* max, int* avg) {
	int average = 0;
	int total = 0;
	int maximum = 0;
	for (int i = size; i >= 0; --i) {
		total += a[i];
		if (a[i] > maximum) {
			maximum = a[i];
		}
	}
	average = total / size;
	//max=&maximum  //error, max 是按值传递的指针副本，改它的地址不会影响原指针，应改为 *max = maximum;而且出了这个循环 maximum 就没用了，所以直接赋值给 *max 就行，我们要的是值，不是地址
	*max = maximum;
	*avg = average;
}

//write a function void shuffle (int* a, int* b, int* c) that will ensure that of the three original values stored at addresses a, b, and c,
// the smallest value is stored at address a, the largest is stored at address c, and the middle value is stored at address b. 
void shuffle(int* a, int* b, int* c) {
	int max, mid, min;
	//method 1: bubble sort
	/*for (int i = 0; i < (*a + *b + *c); i++) {
		int end = 0;//0:min,1:mid,2:max
		if (i == *a && end ==0) {//find min
			min = *a;
			end++;
		}
		if (i == *b && end == 0) {//find min
			min = *b;
			end++;
		}
		if (i == *c && end == 0) {//find min
			min = *c;
			end++;
		}
		if (i == *a && end == 1) {//find mid
			mid = *a;
			end++;
		}
		if (i == *b && end == 1) {//find mid
			mid = *b;
			end++;
		}
		if (i == *c && end == 1) {//find mid
			mid = *c;
			end++;
		}
		if (i == *a && end == 2) {//find max
			max = *a;
			end++;
		}
		if (i == *b && end == 2) {//find max
			max = *b;
			end++;
		}
		if (i == *c && end == 2) {//find max
			max = *c;
			end++;
		}
	}
	*a = max;
	*b = mid;
	*c = min;
	*/

	//method 2: compare
	/*if (*a > *b) {
		if (*a > *c) {
			{
				max = *a;
				if (*b > *c) {
					mid = *b;
					min = *c;
				}
				else {
					mid = *c;
					min = *b;
				}
			}
		}
		else {
			max = *c;
			mid = *a;
			min = *b;
		}
	}
	else {
		if(*b>*c){
			max = *b;
			if (*a > *c) {
				mid = *a;
				min = *c;
			}
			else {
				mid = *c;
				min = *a;
			}
		}
		else {
			max = *c;
			mid = *b;
			min = *a;
		}
	}
	*a = max;
	*b = mid;
	*c = min;
	
	//this is the tree structure of the above code, this shows how the comparisons are made
 //                     (*a > *b) ?
 //                    /           \
 //                 √ /             \ ×
 //                  /               \
 //           (*a > *c) ?           (*b > *c) ?
 //              /   \                /      \
 //           √ /     \ ×           √/        \×
 //            /       \            /          \
 //  [max=*a, mid=*b,  [max=*c,    [max=*b,    [max=*c,
 //   min=*c]           mid=*a,     mid=*a,     min=*b,
 //                     min=*b]     min=*c]    min=*a]
	
	*/
	//method 3: simple swap(most convenient)
	//is b biggest?
	if (*b > *a&& *b > *c) {
		//swap a and b
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	//is c biggest?
	if (*c > *a && *c > *b) {
		//swap a and c
		int temp = *a;
		*a = *c;
		*c = temp;
	}
	//is c > b?
	if (*c > *b) {
		//swap b and c
		int temp = *b;
		*b = *c;
		*c = temp;
	}
	//now a is max, b is mid, c is min
}

//write a function int* max_addr(int a[], int size) that returns the address where the maximum value in the array occurs. 
int* max_addr(int a[], int size) {
	int* maxAddress = &a[0];//we need to get the address of the max value, so we use a pointer to store it
	for (int i = 1; i < size; i++) {//loop through the address in the array one by one
		if (a[i] > *maxAddress) {
			maxAddress = &a[i];//if we find a bigger value, update the maxAddress
		}
	}
	return maxAddress;//return the address of the max value
}