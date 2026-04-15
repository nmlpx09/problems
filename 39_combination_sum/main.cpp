/*

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

*/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

std::set<std::multiset<int>> rs(const std::unordered_set<int>& s, int t) {
    std::set<std::multiset<int>> r;
    for (const auto& e: s) {
        if (e == t) {
            r.insert({e});
        } else if (t - e > 0 ) {
            auto rr = rs(s, t - e);
            for (auto& ee : rr) {
                auto eee = ee;
                eee.insert(e);
                r.insert(eee);
            }
        } else {
            break;
        }
    }
    return r;
}

std::set<std::multiset<int>> f(const std::vector<int>& v, int t) {
    std::unordered_set<int> s;
    for (const auto& e: v) {
        s.insert(e);
    }
    return rs(s, t);
}

int main() {
    std::vector<int> v = {2, 3, 5};
    auto r = f(v, 8);
    for (const auto& v1: r) {
        for (const auto& v2: v1) {
            std::cout << v2 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
