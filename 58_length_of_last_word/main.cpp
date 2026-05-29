/*

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5

*/

#include <string>
#include <iostream>

int f(const std::string& s) {
    int r = -1;
    for (auto i = s.size() - 1; i >= 0; --i) {
        if (s[i] == ' ') {
            return s.size() - i - 1;
        }
    }
    return r;
}

int main() {
    std::cout << f("Hello World ");
    return 0;
}
