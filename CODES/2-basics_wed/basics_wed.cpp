// This file illustrates several basic C++ concepts and associated syntax,
// emphasizing the differences between C++ and Python.
// Sara Krehbiel, CSCI 60, 9/24/25

#include <iostream> 
#include <fstream>
using namespace std; 

void hooray(); // a declaration for a 0-parameter function with no return value

int main() { 
    // 0 CONSOLE OUTPUT

    cout << "Hello\n"; // note new lines and tabs
    cout << "It was the best of times, it was the worst of times, "
            << "it was the age of wisdom, it was the age of foolishness, ";
    cout << "it was the epoch belief, it was the epoch of incredulity...\n";
    cout << "\n\tHere's a new paragraph that is indented." << endl;

    // using numbers without variables
    cout << (5+3) << endl; // 5+3 is not in "" so it's not interpreted as text
    cout << (5%3) << endl; // modular arithmetic
    cout << (5/3) << endl; // note the truncation that happens with ints
    cout << (5.0/3) << endl; // the .0 treats the values as floading points

    // 1 VARIABLES (numbers, strings, arrays)

    // declarations and initialization of two variables with different types
    double n = 5; // TRY: change this to 5.5, then declare it as an int
    int d = 3;

    // output quantities to console using previously-declared variables
    cout << "The numerator is " << n << endl;
    n = 17;
    cout << "The numerator is now " << n << endl;
    cout << "The fraction is " << n << "/" << d << endl;
    cout << "The fraction evaluates to " << (n/d) << endl;

    // get input from user through console
    int userVal; // you can declare a variable without initializing
    cout << "Enter an integer: "; // prompt user for input
    cin >> userVal; // collect input from user and store in variable
    cout << "You entered " << userVal << endl; // report stored value

    // declare, populate, and access array contents
    int threeInts[3] = {4, 6, 7}; // make space for three ints and initial vals
    int size = 3; // good practice to store the size of your arrays
    cout << "First value: " << threeInts[0] << endl; // read from first cell
    cout << "Last value: " << threeInts[2] << endl; // read from last cell
    threeInts[size-1] = 12; // overwrite value in last cell (note last index)
    cout << "The last value in my array is " << threeInts[size-1] << endl;
    
    // 2 BOOLEANS AND CONDITIONALS

    bool eligible = false;
    cout << eligible << endl; // note this outputs as 0 if false and 1 if true

    if (eligible) cout << "You're eligible.\n";
    else cout << "You're not eligible.\n";
    
    // a ternary conditional operator to determine which of two strings to cout
    //cout << "You're " << (eligible ? "" : "not ") << "eligible." << endl;

    int age = 18;
    // note age>=21 is a boolean value even though neither age nor 21 is a bool
    if (age>=21) cout << "Welcome to the bar!\n";
    else cout << "Come back when you're older.\n";

    // 3 LOOPS

    // a standard C++ for loop that iterates 3 times
    for (int i=0; i<3; i++) {
        cout << i << " Hip hip hooray!\n";
    }
    //cout << i << endl; // COMPILE ERROR: i only lives in the scope of the loop

    // an equivalent while loop that initializes before, checks condition 
    // before each iteration, and increments at the end
    int j=0;
    while (j<3) {
        cout << j << "Hop hop hiray!\n";
        j++; // TRY: what happens if you forget this line?
    }
    cout << j << endl; // compiles because j was declared outside the loop

    // 4 FUNCTIONS

    hooray(); // a function call; note it's declared above and defined below

    // WEDNESDAY TODO: define hoorayN with an int parameter, define isPrime

    // 5 FILE I/O

	return 0; 
}

// best practice to define helper functions below main (after declaring above)
void hooray() {
    for (int i=3; i>0; i--) { // note the effect of these loop header changes
        cout << i << " Hooray hip hip!\n";
    }
}