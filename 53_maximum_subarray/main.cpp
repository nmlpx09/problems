/*

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/

#include <iostream>
#include <vector>
#include <limits.h>

int f(const std::vector<int>& v) {
    int m = INT_MIN;
    int s = 0;

    for (auto i = 0; i < v.size(); ++i) {
        s = (s < 0 ? 0 : s) + v[i];
        m = m < s ? s : m;
    }
    return m;
}

int main() {
    std::vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto r = f(v);
    std::cout << r << std::endl;
    return 0;
}
