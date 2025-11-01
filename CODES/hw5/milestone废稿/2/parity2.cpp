// Implementation starter file for CSCI 60 Homework 5; due Wednesday 10/29/25
// Milestone 2: Implement operator<< with sorting output

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
        // Create visited array to track which elements have been output
        bool* visited = new bool[p.nEven_];
        for (size_t i = 0; i < p.nEven_; i++) {
            visited[i] = false;
        }

        // For each position, find and output the minimum unvisited element
        for (size_t i = 0; i < p.nEven_; i++) {
            int minIdx = -1;
            int minVal = INT_MAX;

            // Find the minimum unvisited element
            for (size_t j = 0; j < p.nEven_; j++) {
                if (!visited[j] && p.evens_[j] < minVal) {
                    minVal = p.evens_[j];
                    minIdx = j;
                }
            }

            // Output the minimum element
            if (minIdx != -1) {
                visited[minIdx] = true;
                out << p.evens_[minIdx];
                if (i < p.nEven_ - 1) out << " ";
            }
        }
        delete[] visited;
    }
    out << endl;

    // Output odd numbers in sorted order (same logic as evens)
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