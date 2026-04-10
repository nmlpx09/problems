/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/

#include <iostream>
#include <vector>

int f(const std::vector<int>& v, int n) {
    int b = 0;
    int e = v.size();
    while (b <= e) {
        int m = (b + e) >> 1;
        if (v[m] <= v[e] && n <= v[e]) {
            if (v[m] == n) {
                return m;
            } else {
                b = m + 1;
            }
        } else if (v[b] <= v[m] && n >= v[b]) {
            if (v[m] == n) {
                return m;
            } else {
                e = m - 1;
            }
        } else if (v[m] <= v[e]) {
            e = m - 1;
        } else {
            b = m + 1;
        }
    }
    return -1;
}

int main() {
    const std::vector<int> v = {4,5,6,7,0,1,2};
    std::cout << f(v, 7);
    return 0;
}
