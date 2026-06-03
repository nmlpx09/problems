/*

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

*/

#include <string>
#include <iostream>

std::string f(const std::string a, const std::string& b) {
    if (a.empty()) {
        return b;
    }
    if (b.empty()) {
        return a;
    }
    const std::string& mins = b.size() < a.size() ? b : a;
    const std::string& maxs = b.size() < a.size() ? a : b;
    int i = mins.size() - 1;
    int j = maxs.size() - 1;
    int d = 0;
    std::string r;
    for (; i >= 0; --i, --j) {
        uint s1 = mins[i] - '0';
        uint s2 = maxs[j] - '0';
        uint s = s1 + s2 + d;
        r = char(s % 2 + '0') + r;
        d = s / 2;
    }
    for (; j >= 0; --j) {
        uint s = maxs[j] - '0' + d;
        r = char(s % 2 + '0') + r;
        d = s / 2;
    }
    if (d != 0) {
        r = char(d + '0') + r;
    }
    return r;
}

int main() {
    std::cout << f("1010", "1011");
    return 0;
}
