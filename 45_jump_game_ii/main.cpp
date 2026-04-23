/*

Given an array of non-negative integers, you are initialy positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

Note:

You can assume that you can always reach the last index.

*/

#include <iostream>
#include <vector>



uint f(const std::vector<uint>& v, uint i, std::vector<int>& vmi) {
    if (i >= v.size() - 1) {
        return 0;
    }
    uint r = v.size();
    for (int j = v[i]; j > 0; --j) {
        auto rr = f(v, i + j, vmi);
        if (rr == 0) {
            vmi.push_back(i);
        }
        r = r < rr ? r : rr;
    }
    return r + 1;
}

int fmi(const std::vector<uint>& v) {
    std::vector<int> vmi;
    f(v, 0, vmi);
    auto mi = v.size();
    for (auto i = 0; i < vmi.size(); ++i) {
        mi = mi < vmi[i] ? mi : vmi[i];
    }
    return mi;
}

int main() {
    std::vector<uint> v = {1, 2, 3, 1, 1};
    std::cout << fmi(v);
    return 0;
}
