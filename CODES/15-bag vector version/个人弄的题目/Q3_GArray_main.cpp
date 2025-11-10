#include "Q3_GArray.h"
int main() {
    GArray<int> arr;
    for (int i = 0; i < 10; i++) arr.push_back(i);
    for (size_t i = 0; i < arr.size(); i++) cout << arr[i] << " ";
}
