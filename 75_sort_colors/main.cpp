/*

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

*/


#include <iostream>
#include <vector>

void f(std::vector<uint>& v) {
    int i = -1, j = v.size();

    for (int k = 0; k < j;) {
        if (v[k] == 2) {
            --j;
            std::swap(v[k], v[j]);
        } else if (v[k] == 0) {
            ++i;
            std::swap(v[k], v[i]);
            ++k;
        } else {
            ++k;
        }
    }
}

int main() {
    std::vector<uint> v = {2,0,2,1,1,0};
    f(v);
    for (const auto& e: v) {
        std::cout << e << " ";
    }
    return 0;
}