/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

*/

#include <iostream>
#include <string>
#include <vector>

std::string f(std::string s, uint num) {
    if (num < 2) {
        return s;
    }
    std::vector<std::vector<char>> rr;
    for (auto i = 0; i < num; ++i) {
        rr.push_back({});
    }
    bool c = false;
    std::size_t j = 0;
    while(true) {
       // if (!c) {
            for (auto i = 0; i < num; ++i) {
                rr[i].push_back(s[j++]);
                if (j >= s.size()) {
                    break;
                }
            }
            c = true;
      //  } else {
        //    for (auto i = num - 1 ; i >= 0; --i) {
         //       rr[i].push_back(s[j++]);
         //       if (j >= s.size()) {
          //          break;
          //      }
         //   }
         //   c = false;
        //}
        /*for (auto i = num - 2; i >= 1; --i) {
            for(auto k = 0; k < num; ++k) {
                if (i == k) {
                    rr[k].push_back(' ');
                } else {
                    rr[k].push_back(s[j++]);
                    if (j >= s.size()) {
                        break;
                    }
                }
            }
        }*/
    }
    /*std::string r;
    while(true) {
        std::size_t j = 0;
        for (auto i = 0; i < num; ++i) {
            if (j < rr[i].size()) {
                r += rr[i][j];
            } else {
                return r;
            }
        }
        ++j;
    }*/

    return "";
}

int main() {
    std::string s = "PAHNAPLSIIGYIR";
    std::cout << f(s, 4);
    return 0;
}