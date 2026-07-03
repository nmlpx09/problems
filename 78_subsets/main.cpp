/*

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

#include <iostream>
#include <vector>

std::vector<std::vector<uint>> ff(uint m, uint k, std::vector<std::vector<uint>>& fr) {
    if (m == 0 || k == 0) {
        return {};
    }

    if (k > m) {
        k = m;
    }

    std::vector<std::vector<uint>> r;

    if (k == 1) {
        for (uint i = 1; i <= m; ++i) {
            r.push_back({i});
            fr.push_back({i});
        }
    } else {
        auto m_1 = ff(m, k - 1, fr);
        for (uint i = 0; i < m_1.size(); ++i) {
            for (uint j = k + i; j <= k; ++j) {
                auto c = m_1[i];
                c.push_back(j);
                r.push_back(c);
                fr.push_back(c);
            }
        }
    }
    return r;
}

std::vector<std::vector<uint>> f(uint m) {
    std::vector<std::vector<uint>> r;
    ff(m, m, r);
    r.push_back({0});
    return r;
}

int main() {
    auto r = f(3);
    for (const auto& v: r) {
        for (const auto& e: v) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
