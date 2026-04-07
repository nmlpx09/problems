/*

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.

*/

#include <vector>
#include <iostream>

void f(std::vector<int>& v) {
    if (v.size() <= 1) {
        return;
    }
    auto i = 1;
    for(auto j = 1; j < v.size(); ++j) {
        if (v[i - 1] != v[j]) {
            v[i] = v[j];
            ++i;
        }
    }
    v.resize(i);
}

int main() {
    std::vector<int> v = {0,1,2,2,3,3,4};
    f(v);
    for (const auto& e: v) {
        std::cout << e << ' ';
    }
    return 0;
}