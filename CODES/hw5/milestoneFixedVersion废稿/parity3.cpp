// Implementation starter file for CSCI 60 Homework 5; due Wednesday 10/29/25
// Milestone 3: Implement 2-arg constructor - FIXED VERSION

#include "parity.h"

// Milestone 1: insert() function
void Parity::insert(int val) {
    bool isEven = (val % 2 == 0);

    if (isEven) {
        if (nEven_ % CAP == 0) {
            size_t newSize = nEven_ + CAP;
            int* tempEvens = new int[newSize];

            for (size_t i = 0; i < nEven_; i++) {
                tempEvens[i] = evens_[i];
            }

            if (evens_ != nullptr) {
                delete[] evens_;
            }

            evens_ = tempEvens;
        }

        evens_[nEven_] = val;
        nEven_++;
    }
    else {
        if (nOdd_ % CAP == 0) {
            size_t newSize = nOdd_ + CAP;
            int* tempOdds = new int[newSize];

            for (size_t i = 0; i < nOdd_; i++) {
                tempOdds[i] = odds_[i];
            }

            if (odds_ != nullptr) {
                delete[] odds_;
            }

            odds_ = tempOdds;
        }

        odds_[nOdd_] = val;
        nOdd_++;
    }
}

// Milestone 2: operator<< with sorted output
ostream& operator <<(ostream& out, const Parity& p) {
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

// Milestone 3: 2-argument constructor - FIXED
Parity::Parity(int* a, size_t n) : Parity() {
    for (size_t i = 0; i < n; i++) {
        insert(a[i]);
    }
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