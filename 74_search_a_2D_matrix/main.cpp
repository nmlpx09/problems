/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

*/

#include <iostream>
#include <vector>

bool f(const std::vector<std::vector<uint>>& mtr, uint t) {
    if (mtr.size() == 0) {
        return false;
    }

    std::size_t ti = 0;
    std::size_t i = 0;
    for (; i < mtr.size() - 1; ++i) {
        if (t >= mtr[i][0] && t < mtr[i + 1][0]) {
            ti = i;
            break;
        }
    }
    if (i == mtr.size() - 1) {
        ti =  mtr.size() - 1;
    }

    int s = 0;
    int e = mtr[ti].size() - 1;

    while(s <= e) {
        int c = (s + e) >> 1;
        if (mtr[ti][c] == t) {
            return true;
        } else if (mtr[ti][c] > t) {
            e = c - 1;
        } else {
            s = c + 1;
        }
    }
    return false;
}

int main() {
    std::vector<std::vector<uint>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    std::cout << f(mat, 50) << std::endl;
    return 0;
}
