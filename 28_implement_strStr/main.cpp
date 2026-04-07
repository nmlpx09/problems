/*

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

*/
#include <iostream>
#include <string>

int f(const std::string& a, const std::string& b) {
    for (auto i = 0; i < a.size();) {
        if (a[i] == b[0]) {
            auto j = 1;
            for (; j < b.size(); ++j) {
                if (a[i + j] != b[j]) {
                    break;
                }
            }
            if (j == b.size()) {
                return i;
            } else {
                i += j;
            }
        } else {
            ++i;
        }
    }
    return -1;
}

int main() {
    std::cout << f("aaaaa", "a");
    return 0;
}
