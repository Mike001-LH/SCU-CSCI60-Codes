// Implementation starter file for CSCI 60 Homework 5; due Wednesday 10/29/25
// Milestone 1: Implement insert - FIXED VERSION

#include "parity.h"

// Milestone 1: insert() function - FIXED
// Handles nullptr case for first insertion
void Parity::insert(int val) {
    bool isEven = (val % 2 == 0);

    if (isEven) {
        // Check if we need to allocate or expand evens array
        if (nEven_ % CAP == 0) {
            // Calculate new size
            size_t newSize = nEven_ + CAP;
            int* tempEvens = new int[newSize];

            // Copy old elements to new array
            for (size_t i = 0; i < nEven_; i++) {
                tempEvens[i] = evens_[i];
            }

            // Delete old array (if it exists)
            if (evens_ != nullptr) {
                delete[] evens_;
            }

            evens_ = tempEvens;
        }

        // Append new element
        evens_[nEven_] = val;
        nEven_++;
    }
    else {
        // Check if we need to allocate or expand odds array
        if (nOdd_ % CAP == 0) {
            // Calculate new size
            size_t newSize = nOdd_ + CAP;
            int* tempOdds = new int[newSize];

            // Copy old elements to new array
            for (size_t i = 0; i < nOdd_; i++) {
                tempOdds[i] = odds_[i];
            }

            // Delete old array (if it exists)
            if (odds_ != nullptr) {
                delete[] odds_;
            }

            odds_ = tempOdds;
        }

        // Append new element
        odds_[nOdd_] = val;
        nOdd_++;
    }
}

// Milestone 3: Stub
Parity::Parity(int* a, size_t n) : Parity() {
    // TODO: Will implement in Milestone 3
}

// Milestone 4: Stubs
bool Parity::odd() const {
    return false;
}

int Parity::min() const {
    return INT_MAX;
}

int Parity::max() const {
    return INT_MIN;
}

// Milestone 2: Stub - Must output "E: " and "O: " even if empty
ostream& operator <<(ostream& out, const Parity& p) {
    out << "E: " << endl;
    out << "O: " << endl;
    return out;
}