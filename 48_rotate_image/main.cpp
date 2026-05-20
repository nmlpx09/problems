/*


48. Rotate Image

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

*/
#include <iostream>
#include <vector>

void f(std::vector<std::vector<uint>>& m) {
    auto s = m.size();

    for (int i = 0; i < s; ++i) {
        for (int j = i; j < s; ++j) {
            std::swap(m[i][j], m[j][i]);
        }
    }

    for (int i = 0; i < s; ++i) {
        for (int j = 0, k = s - 1; j <= k; ++j, --k) {
            std::swap(m[i][j], m[i][k]);
        }
    }
}

int main() {
    std::vector<std::vector<uint>> m;
    uint s = 3;

    for (int i = 0, v = 1; i < s; ++i) {
        m.emplace_back(std::vector<uint>{});
        for (int j = 0; j < s; ++j, ++v) {
            m[i].emplace_back(v);
        }
    }

    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }

    f(m);

    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
