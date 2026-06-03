/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

*/

#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <climits>

uint f(const std::vector<std::vector<uint>>& m) {
    if (m.empty() || m[0].empty()) {
        return 0;
    }
    std::list<std::tuple<uint, uint, uint>> st;
    st.push_back({0, 0, 0});
    uint r = UINT_MAX;
    uint si = m.size() - 1;
    uint sj = m[0].size() - 1;
    while (!st.empty()) {
        auto [ci, cj, cr] = st.back();
        st.pop_back();

        for (auto j = cj; j <= sj; ++j) {
            cr += m[ci][j];
            if (ci < si) {
                st.push_back({ci + 1, j, cr});
            }
        }

        if (ci == si) {
            r = r > cr ? cr : r;
        }
    }
    return r;
}

int main() {
    std::vector<std::vector<uint>> m = {{1, 3, 1}, {1,5,1}, {4,2,1}};
    std::cout << f(m);
    return 0;
}
