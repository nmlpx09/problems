/*

Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.

*/


#include <iostream>
#include <vector>

std::size_t f(std::vector<uint>& v) {
    if (v.size() < 2) {
        return v.size();
    }

    uint k = 0;
    auto c = v[k];
    uint cc = 1;
    std::size_t s = v.size();

    for (int i = 1; i < v.size(); ++i) {
        if (v[i] != v[k]) {
            v[++k] = v[i];
            cc = 1;
        } else if (v[i] == v[k] && cc == 1) {
            v[++k] = v[i];
            cc = 2;
        } else {
            --s;
        }
    }
    v.resize(s);
    return s;
}

int main() {
    std::vector<uint> v = {0,0,1,1,1,1,2,3,3};
    std::cout << f(v) << std::endl;
    for (const auto& e: v) {
        std::cout << e << std::endl;
    }
    return 0;
}
