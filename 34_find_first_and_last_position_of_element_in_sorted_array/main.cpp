/*

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/

#include <iostream>
#include <vector>

int l(const std::vector<int>& v, int d) {
    int b = 0;
    int e = v.size() - 1;

    while(b < e) {
        int m = (b + e) >> 1;
        if (d <= v[m]) {
            e = m;
        } else {
            b = m + 1;
        }
    }

    if (v[e] == d) {
        return e;
    }
    return -1;
}

int u(const std::vector<int>& v, int d) {
    int b = 0;
    int e = v.size() - 1;

    while(b < e) {
        int m = (b + e + 1) >> 1;
        if (d >= v[m]) {
            b = m;
        } else {
            e = m - 1;
        }
    }

    if (v[e] == d) {
        return e;
    }
    return -1;
}

int main() {
    std::vector<int> v = {5,7,7,8,8,10};
    std::cout << l(v, 5);
    std::cout << u(v, 5);
    return 0;
}