/*

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

#include <iostream>
#include <vector>

std::vector<std::vector<uint>> f(uint n, uint k) {
    if (k == 0 || k > n) {
        return {};
    }
    if (k == 1) {
        std::vector<std::vector<uint>> r;
        for (uint i = 1; i <= n; ++i) {
            r.push_back({i});
        }
        return r;
    }

    auto r1 = f(n, k - 1);
    std::vector<std::vector<uint>> r;

    for (auto i = 0; i < r1.size(); ++i) {
        for (uint j = k + i; j <= n; ++j) {
            auto cr = r1[i];
            cr.push_back(j);
            r.push_back(cr);
        }
    }
    return r;
}

int main() {
    auto r = f(4, 4);
    for (const auto& v: r) {
        for (const auto& e: v) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
