/*

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3

Example 2:

Input: [3,4,-1,1]
Output: 2

Example 3:

Input: [7,8,9,11,12]
Output: 1

Note:

Your algorithm should run in O(n) time and uses constant extra space.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int f(const std::vector<int>& v) {
    std::unordered_map<int, uint> m;
    std::unordered_set<int> s;
    int max = -1;
    for (const auto& e : v) {
        s.insert(e);
        if (m.count(e) == 0) {
            m[e] = 1;
        } else {
            ++m[e];
        }
        if (m.count(e + 1) == 0) {
            m[e + 1] = 1;
        } else {
            ++m[e + 1];
        }
        max = e > max ? e : max;
    }
    if (s.count(1) == 0) {
        m[1] = 1;
    }
    int r = max + 1;
    for (const auto& [e, c]: m) {
        if (e <= 0) {
            continue;
        }
        if (c == 1 && s.count(e) == 0) {
           r = r < e ? r : e;
        }
    }
    return r;
}

int main() {
    std::vector<int>  v = {1,2,0};
    std::cout << f(v);
    return 0;
}
