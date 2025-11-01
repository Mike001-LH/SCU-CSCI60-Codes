// Implementation starter file for CSCI 60 Homework 5; due Wednesday 10/29/25
// Milestone 4: Implement all accessor functions - COMPLETE VERSION

#include "parity.h"

// Milestone 1: insert() function
void Parity::insert(int val) {
    bool isEven = (val % 2 == 0);

    if (isEven) {
        if (nEven_ % CAP == 0) {
            int* tempEvens = new int[nEven_ + CAP];
            for (size_t i = 0; i < nEven_; i++) {
                tempEvens[i] = evens_[i];
            }
            delete[] evens_;
            evens_ = tempEvens;
        }
        evens_[nEven_] = val;
        nEven_++;
    }
    else {
        if (nOdd_ % CAP == 0) {
            int* tempOdds = new int[nOdd_ + CAP];
            for (size_t i = 0; i < nOdd_; i++) {
                tempOdds[i] = odds_[i];
            }
            delete[] odds_;
            odds_ = tempOdds;
        }
        odds_[nOdd_] = val;
        nOdd_++;
    }
}

// Milestone 2: operator<< with sorted output
ostream& operator <<(ostream& out, const Parity& p) {
    // Output even numbers in sorted order
    out << "E: ";
    if (p.nEven_ > 0) {
        bool* visited = new bool[p.nEven_];
        for (size_t i = 0; i < p.nEven_; i++) {
            visited[i] = false;
        }

        for (size_t i = 0; i < p.nEven_; i++) {
            int minIdx = -1;
            int minVal = INT_MAX;

            for (size_t j = 0; j < p.nEven_; j++) {
                if (!visited[j] && p.evens_[j] < minVal) {
                    minVal = p.evens_[j];
                    minIdx = j;
                }
            }

            if (minIdx != -1) {
                visited[minIdx] = true;
                out << p.evens_[minIdx];
                if (i < p.nEven_ - 1) out << " ";
            }
        }
        delete[] visited;
    }
    out << endl;

    // Output odd numbers in sorted order
    out << "O: ";
    if (p.nOdd_ > 0) {
        bool* visited = new bool[p.nOdd_];
        for (size_t i = 0; i < p.nOdd_; i++) {
            visited[i] = false;
        }

        for (size_t i = 0; i < p.nOdd_; i++) {
            int minIdx = -1;
            int minVal = INT_MAX;

            for (size_t j = 0; j < p.nOdd_; j++) {
                if (!visited[j] && p.odds_[j] < minVal) {
                    minVal = p.odds_[j];
                    minIdx = j;
                }
            }

            if (minIdx != -1) {
                visited[minIdx] = true;
                out << p.odds_[minIdx];
                if (i < p.nOdd_ - 1) out << " ";
            }
        }
        delete[] visited;
    }
    out << endl;

    return out;
}

// Milestone 3: 2-argument constructor
Parity::Parity(int* a, size_t n) : Parity() {
    for (size_t i = 0; i < n; i++) {
        insert(a[i]);
    }
}

// Milestone 4: Accessor functions

// min() - returns the smallest value across both arrays
// Returns INT_MAX if both arrays are empty
int Parity::min() const {
    if (nEven_ == 0 && nOdd_ == 0) {
        return INT_MAX;
    }
    int minVal = INT_MAX;
    for (size_t i = 0; i < nEven_; i++) {
        if (evens_[i] < minVal) {
            minVal = evens_[i];
        }
    }
    for (size_t i = 0; i < nOdd_; i++) {
        if (odds_[i] < minVal) {
            minVal = odds_[i];
        }
    }
    return minVal;
}

// max() - returns the largest value across both arrays
// Returns INT_MIN if both arrays are empty
int Parity::max() const {
    if (nEven_ == 0 && nOdd_ == 0) {
        return INT_MIN;
    }
    int maxVal = INT_MIN;
    for (size_t i = 0; i < nEven_; i++) {
        if (evens_[i] > maxVal) {
            maxVal = evens_[i];
        }
    }
    for (size_t i = 0; i < nOdd_; i++) {
        if (odds_[i] > maxVal) {
            maxVal = odds_[i];
        }
    }
    return maxVal;
}

// odd() - returns true if sum of all values is odd, false if even
// Key insight: sum of evens is always even, so check if nOdd_ is odd
bool Parity::odd() const {
    return (nOdd_ % 2 == 1);
}