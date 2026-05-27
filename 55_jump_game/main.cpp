/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

*/

#include <iostream>
#include <vector>

bool r(const std::vector<std::size_t>& v, std::size_t i) {
    if (i >= v.size()) {
        return true;
    }

    for (auto ii = 1; ii <= v[i]; ++ii) {
        if (r(v, ii + i)) {
            return true;
        }
    }
    return false;
}

bool f(const std::vector<std::size_t>& v) {
    return r(v, 0);
}

int main() {
    std::vector<std::size_t> v = {3,2,1,0,4};
    std::cout << f(v);
    return 0;
}
