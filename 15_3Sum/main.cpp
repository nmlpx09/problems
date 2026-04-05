/*

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>

std::vector<std::vector<int>> f(std::vector<int>& v) {
    if (v.size() < 3) {
        return {};
    }
    std::sort(v.begin(), v.end());

    std::vector<std::vector<int>> r;

    for (std::size_t i = 0; i < v.size() - 2; ++i) {
        std::size_t j = i + 1;
        std::size_t k = v.size() - 1;
        while (j < k) {
            while (i > 0 && v[i] == v[i - 1]) {
                ++i;
            }
            auto n = v[i] + v[j] + v[k];
            if (n < 0){
                ++j;
            } else if (n > 0) {
                --k;
            } else {
                r.push_back({});
                r.back().push_back(v[i]);
                r.back().push_back(v[j++]);
                r.back().push_back(v[k--]);
                while (j < k && v[j] == v[j - 1]) {
                    ++j;
                }
                while (j < k && v[k] == v[k + 1]) {
                    --k;
                }
            }
        }
    }

    return r;
}

int main() {
    std::vector<int> v = {-1, 0, 1, 2, -1, -4};
    auto r = f(v);
    for (const auto& v1: r) {
        for (const auto& v2: v1) {
            std::cout << v2 << " ";
        }
        std::cout << '\n';
    }
    return 1;
}
