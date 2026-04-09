/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

*/

#include <iostream>
#include <vector>
#include <string>

uint f(const std::string& v) {
    uint l = 0;
    uint r = 0;
    std::vector<int> s;
    for (auto i = 0; i < v.size(); ++i) {
        if (v[i] == '(') {
            s.push_back(i);
        } else {
            if (s.empty()) {
                l = i + 1;
            } else {
                s.pop_back();
                auto m = s.empty() ? i - l + 1: i - s.back();
                r = r > m ? r : m;
            }
        }
    }
    return r;
}

int main() {
    std::string s = ")()((((()";
    std::cout << f(s);
    return 0;
}