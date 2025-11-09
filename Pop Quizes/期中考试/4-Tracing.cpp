/*
4 Tracing (10 points)

This question has you trace memory to determine output for the code on the following page.
Additionally, add any code needed to avoid orphaning memory.
Write the output below and add your code directly to the provided code in the appropriate place.

Part 1: 
Part 2: 
Part 3: 
*/

#include <iostream>
using namespace std;

void part1() {
    int x = 5;
    int y = 10;
    int* p = &x;      // p -> &x
    int* q = &y;      // q -> &y
    x = y + 1;        // x = 11
    y = *p + 4;       // y = x+4 = 11+4 = 15
    q = &x;           // q -> &x
	*q = x + 2;       // *q = 11+2 = 13 = x, 
    p = q;            // p -> &x
	cout << "Part 1: " << x << " " << y << " " << *p << " " << *q << endl;//Part 1: 13 15 13 13
}

void part2() {
    int n = 4;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
		arr[i] = i + 2;// arr = {2,3,4,5}
	int* p = arr;// p -> arr
	*(p + 2) = *p + *(p + 1);// p[2] = p[0] + p[1] = 2 + 3 = 5, arr = {2,3,5,5}
	*(arr + 3) = *(p + 2) * 2;// arr[3] = p[2] * 2 = 5 * 2 = 10, arr = {2,3,5,10}
    cout << "Part 2: ";
    for (int i = 0; i < n; i++) {
		cout << arr[i] << " " << p[i] << " ";//Part 2: 2 2 3 3 5 5 10 10
    }
    cout << endl;
	delete[] arr; ///这里这行是需要加上的代码 Free allocated memory to avoid memory leak，因为arr是new出来的动态数组，临时的，所以用完要delete掉
}

int* fn(int a, int* b, int c) {
    a += 2;
    *b = 2;
    c += 2;
    return b;
}

void part3() {
    int nums[4] = { 1, 2, 3, 4 };
    int bonus = 10;
	int* p = nums;// p -> nums
	int* result = fn(p[0], p + 1, bonus);// a=1+2=3, *(p+1)=2->nums[2]=2, c=10+2=12, return p+1也就是 &nums[1]
	*result += bonus;// *result = nums[1] = 2 + 10 = 12，因此nums = {1,12,2,4}
	nums[2] = 6;// nums = {1,12,6,4}
    cout << "Part 3: ";
    for (int i = 0; i < 4; i++) {
		cout << *(p + i) << " ";//Part 3: 1 12 6 4
    }
    cout << endl;
}

int main() {
    part1();
    part2();
    part3();
    return 0;
}
/*
Part 1: 13 15 13 13
Part 2: 2 2 3 3 5 5 10 10
Part 3: 1 12 6 4
*/