#include "rarr.h"
//1, define insert, if size_ == cap_, allocate new array with larger capacity, copy old data, delete old array, update data_ and cap_, then insert val
void RArr::insert(int val) {
	if (size_ == cap_) {
		// Need to allocate a new array with larger capacity
		size_t newCap = (cap_ == 0) ? 1 : cap_ * 2;
		int* newData = new int[newCap];
		for (size_t i = 0; i < size_; ++i) {
			newData[i] = data_[i];
		}
		delete[] data_;
		data_ = newData;
		cap_ = newCap;
	}
	data_[size_] = val;
	size_++;
}

//2, define resize, if new cap < size_, do nothing, else allocate new array with new cap, copy old data, delete old array, update data_ and cap_
void RArr::resize(size_t newCap) {
	if (newCap < size_) {
		// If new capacity is less than current size, do nothing
		return;
	}
	int* newData = new int[newCap];
	for (size_t i = 0; i < size_; ++i) {
		newData[i] = data_[i];
	}
	delete[] data_;
	data_ = newData;
	cap_ = newCap;
}