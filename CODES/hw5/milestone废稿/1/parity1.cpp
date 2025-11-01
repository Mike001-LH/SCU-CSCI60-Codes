// Implementation starter file for CSCI 60 Homework 5; due Wednesday 10/29/25
// Milestone 1: Implement insert function

#include "parity.h"

// Milestone 1: insert() function
// Simple append - no sorting! Just add to the end and expand if needed
void Parity::insert(int val) {
    bool isEven = (val % 2 == 0);

    if (isEven) {
        // Check if we need to expand evens array
        if (nEven_ % CAP == 0) {
            // Allocate new array with CAP more elements
            int* tempEvens = new int[nEven_ + CAP];

            // Copy old elements to new array
            for (size_t i = 0; i < nEven_; i++) {
                tempEvens[i] = evens_[i];
            }

            // Delete old array and update pointer
            delete[] evens_;
            evens_ = tempEvens;
        }

        // Simply append to the end
        evens_[nEven_] = val;
        nEven_++;
    }
    else {
        // Check if we need to expand odds array
        if (nOdd_ % CAP == 0) {
            // Allocate new array with CAP more elements
            int* tempOdds = new int[nOdd_ + CAP];

            // Copy old elements to new array
            for (size_t i = 0; i < nOdd_; i++) {
                tempOdds[i] = odds_[i];
            }

            // Delete old array and update pointer
            delete[] odds_;
            odds_ = tempOdds;
        }

        // Simply append to the end
        odds_[nOdd_] = val;
        nOdd_++;
    }
}

// Milestone 3: Stub
Parity::Parity(int* a, size_t n) : Parity() {
    // TODO: Will implement in Milestone 3
}

// Milestone 4: Stub
bool Parity::odd() const {
    // TODO: Will implement in Milestone 4
    return false;
}

// Milestone 4: Stub
int Parity::min() const {
    return INT_MAX;
}

// Milestone 4: Stub
int Parity::max() const {
    return INT_MIN;
}

// Milestone 2: Stub
ostream& operator <<(ostream& out, const Parity& p) {
    return out;
}