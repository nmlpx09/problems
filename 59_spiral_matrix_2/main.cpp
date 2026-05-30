/*

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

#include <vector>
#include <iostream>

std::vector<std::vector<uint>> f(uint s) {
    std::vector<std::vector<uint>> r;

    for (auto i = 0; i < s; ++i) {
        r.push_back({});
        for (auto j = 0; j < s; ++j) {
            r[i].push_back(0);
        }
    }

    int p = 1;
    int ii = 0;
    int jj = 0;
    int i = 0;
    int j = 0;
    while(p <= s * s) {
        i = ii;
        j = jj;
        for (; j < s - jj; ++j) {
            r[i][j] = p++;
        }
        --j;
        ++i;
        for (; i < s - ii; ++i) {
            r[i][j] = p++;
        }
        --i;
        --j;
        for (; j >= jj; --j) {
            r[i][j] = p++;
        }
        ++j;
        --i;
        for (; i >= ii + 1; --i) {
            r[i][j] = p++;
        }
        ++ii;
        ++jj;
    }

    return r;
}

int main() {
    auto r = f(3);
    for (const auto& row: r ) {
        for (const auto& e: row ) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
