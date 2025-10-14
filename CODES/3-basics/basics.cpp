// This file illustrates several basic C++ concepts and associated syntax,
// emphasizing the differences between C++ and Python/other languages.
// Sara Krehbiel, CSCI 60, 9/26/25

#include <iostream> // same library as monday
#include <fstream> // new library for file i/o
using namespace std; 


/* FUNCTION DECLARATIONS */

void wednesday(); // console i/o, arrays, conditionals, loops
void friday(); // functions, file i/o
void functions(); // sample code calling various helper functions
void hooray(); // a declaration for a 0-parameter function with no return value
void hoorayN(int n); // a parameterized version of hooray
bool isPrime(int n); // determines whether n is prime
void fileIO(); // sample code for reading from/writing to files
void fileIOBonus(); // more file i/o based on (great!) in-class questions


/* MAIN: the starting point for your program */

// calls a number of helper functions demonstrating basic C++ syntax
int main() { 
    wednesday(); // console i/o, arrays, conditionals, and loops
    friday(); // functions, file i/o
    return 0;
}

/* FUNCTION DEFINITIONS */ 

// sample code to output strings/numbers, use variables, conditionals, and loops
void wednesday() {
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
        cout << j << " Hop hop hiray!\n";
        j++; // TRY: what happens if you forget this line?
    }
    cout << j << endl; // compiles because j was declared outside the loop
}

// sample code using user-defined functions and file i/o
void friday() {
    // 4 FUNCTIONS

    functions();

    // 5 FILE I/O

    fileIO();
    fileIOBonus();
}

void functions() {
    // calls to functions without and with parameters
    hooray();
    hoorayN(4);
    hoorayN(2);

    // calls to a boolean function
    int n=5;
    if (isPrime(n)) cout << n << " is prime\n";
    else cout << n << " is not prime\n";
    n=15;
    if (isPrime(n)) cout << n << " is prime\n";
    else cout << n << " is not prime\n";
}


// outputs three lines of text and returns nothing
void hooray() {
    for (int i=3; i>0; i--) { // note the effect of these loop header changes
        cout << i << " Hooray hip hip!\n";
    }
}

// outputs n lines of text, where n is the parameter
void hoorayN(int n) {
    for (int i=0; i<n; i++) {
        cout << "Hooray\n";
    }
}

// returns whether n has no factors
bool isPrime(int n) {
    // check all possible nontrivial factors
    for (int i=2; i<=n-1; i++) {
        // if one is found, return false (not prime) immediately
        if (n%i==0) return false;
    }
    return true;
}

// read ints from a file and write only the primes to another file
void fileIO() {
    int nextInt; // for storing the contents of ints.txt token-by-token
    ifstream fin("ints.txt"); // an existing file I want to read from
    ofstream fout("primes.txt"); // a file (existing or new) I want to write to
    while (fin >> nextInt) { // as long as there's another token, store it
        if (isPrime(nextInt)) { // check whether it's prime
            fout << nextInt << endl; // write to file
            //cout << nextInt << " is prime\n"; // compare to writing to console
        } 
    }
    // close all file streams when you're done with them
    fin.close();
    fout.close();
}

// based on questions from the 1030 section
void fileIOBonus() {
    // you can have multiple input and/or output files open at a time
    int nextInt; 
    ifstream fin("ints.txt"); 
    ofstream fout("primes.txt"); 
    ofstream fout2("notprimes.txt"); 
    // if you want to store an unknown number of contents in an array...
    int primes[10]; // declare an array bigger than you think you need it to be
    int nextIndex = 0; // and keep track of the next unused index
    while (fin >> nextInt) { // read token-by-token
        if (isPrime(nextInt)) { 
            fout << nextInt << endl; // put primes in the primes file
            primes[nextIndex] = nextInt; // write to partially-filled array
            nextIndex++; // advance to index of next unused cell in array
        } else {
            fout2 << nextInt << endl; // put non-primes in non-primes file
        }
    }
    // close all file streams
    fin.close();
    fout.close();
    fout2.close();
}
