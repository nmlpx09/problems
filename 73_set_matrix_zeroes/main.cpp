/*

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

*/

#include <iostream>
#include <vector>

void f(std::vector<std::vector<int>>& mat) {
    auto m = mat.size();
    if (m == 0) {
        return;
    }
    auto n = mat[0].size();

    if (n == 0) {
        return;
    }

    for (auto i = 0; i < m; ++i) {
        for (auto j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                for (auto jj = 0; jj < n; ++jj) {
                    if (jj == j || mat[i][jj] == 0) {
                        continue;
                    }
                    mat[i][jj] = -1;
                }
                for (auto ii = 0; ii < m; ++ii) {
                    if (ii == i || mat[ii][j] == 0) {
                        continue;
                    }
                    mat[ii][j] = -1;
                }
            }
        }
    }

    for (auto i = 0; i < m; ++i) {
        for (auto j = 0; j < n; ++j) {
            if (mat[i][j] == -1) {
                mat[i][j] = 0;
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> mat = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    f(mat);
    for (auto i = 0; i < mat.size(); ++i) {
        for (auto j = 0; j < mat[i].size(); ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
