/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

*/

#include <iostream>
#include <vector>

std::vector<int> f(const std::vector<std::vector<int>>& m) {
    std::vector<int> r;

    int s = 0;
    int ii = 0;
    int jj = 0;
    while (s < m.size() * m.size()) {
        int i = ii;
        int j = jj;
        for (; i < m.size() - ii; ++i) {
            r.push_back(m[i][j]);
            ++s;
        }
        ++j;
        --i;
        for (; j < m.size() - jj; ++j) {
            r.push_back(m[i][j]);
            ++s;
        }
        --i;
        --j;
        for (; i >= ii; --i) {
            r.push_back(m[i][j]);
            ++s;
        }
        --j;
        ++i;
        for (; j >= jj + 1; --j) {
            r.push_back(m[i][j]);
            ++s;
        }
        ++ii;
        ++jj;
    }

    return r;
}

int main() {
    std::vector<std::vector<int>> m;
    for (auto i = 0, s = 1; i < 4; ++i) {
        m.push_back(std::vector<int>{});
        for (auto j = 0; j < 4; ++j) {
            m[i].push_back(s++);
        }
    }
    auto r = f(m);
    for (const auto& v: r) {
        std::cout << v << " ";
    }
    return 0;
}