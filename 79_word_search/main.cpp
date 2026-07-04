/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

*/

#include <iostream>
#include <vector>
#include <string>

bool ff(int m, int n, int k, const std::string& s, std::vector<std::vector<char>>& mtr) {
    if (k >= s.size()) {
        return true;
    }
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (j == 1 && i == 1 || j == -1 && i == 1 || j == 1 && i == -1 || j == -1 && i == -1) {
                continue;
            }
            if (m + i < mtr.size() &&  n + j < mtr[m + i].size() && mtr[m + i][n + j] == s[k]) {
                auto c = mtr[m + i][n + j];
                mtr[m + i][n + j] = '\0';
                if (ff(m + i, n + j, k + 1, s, mtr)) {
                    return true;
                }
                mtr[m + i][n + j] = c;
            }
        }
    }
    return false;
}

bool f(const std::string& s, std::vector<std::vector<char>>& mtr) {
    for (int i = 0; i < mtr.size(); ++i) {
        for (int j = 0; j < mtr[i].size(); ++j) {
            if (mtr[i][j] == s[0]) {
                auto c = mtr[i][j];
                mtr[i][j] = '\0';
                if (ff(i, j, 1, s, mtr)) {
                    return true;
                }
                mtr[i][j] = c;
            }
        }
    }
    return false;
}

int main() {
    std::vector<std::vector<char>> mtr = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    std::cout << f("ABCCED", mtr);
    return 0;
}
