/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

*/

#include <iostream>
#include <vector>

bool f(const std::vector<uint>& v, uint t) {
    
    int b = 0;
    int e = v.size() - 1;
    while(b <= e) {
        auto s = (b + e) >> 1;
        if (v[s] == t) {
            return true;
        }
        if (t < v[s] && t >= v[e]) {
            e = s - 1;
        } else if (t < v[s] && t < v[e]) {
            b = s + 1;
        } else if (t > v[s] && t > v[e]) {
            e = s - 1;
        } else if (t > v[s] && t <= v[e]) {
            b = s + 1;
        }
    }
    return false;
}

int main() {
    std::vector<uint> v = {2,5,6,0,0,1,2};
    std::cout << f(v, 2);
    return 0;
}

