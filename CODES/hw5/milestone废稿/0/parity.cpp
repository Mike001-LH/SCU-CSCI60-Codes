// Implementation starter file for CSCI 60 Homework 5; due Wednesday 10/29/25
// List any collaborators and write your name here

#include "parity.h"

// Milestone 0: Stub functions for insert, odd, and 2-arg constructor
// This version just has empty implementations to test compilation

void Parity::insert(int val) {
    // TODO: Will implement in Milestone 1
}

Parity::Parity(int* a, size_t n) : Parity() {
    // TODO: Will implement in Milestone 3
}

bool Parity::odd() const {
    // TODO: Will implement in Milestone 4
    return false;
}

int Parity::min() const {
    return INT_MAX;
}

int Parity::max() const {
    return INT_MIN;
}

ostream& operator <<(ostream& out, const Parity& p) {
    return out;
}