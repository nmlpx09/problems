/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

*/

#include <iostream>
#include <vector>

bool f(const std::vector<char>& v) {
    std::vector<char> s;

    for (const auto& c: v) {
        if (c == '(' || c == '[' || c == '{') {
            s.push_back(c);
        } else if (c == ')') {
            if (s.back() == '(') {
                s.pop_back();
            } else {
                return false;
            }
        } else if (c == ']') {
            if (s.back() == '[') {
                s.pop_back();
            } else {
                return false;
            }
        } else {
            if (s.back() == '{') {
                s.pop_back();
            } else {
                return false;
            }
        }
    }
    if (s.size() == 0) {
        return true;
    }
    return false;
}

int main() {
    std::vector<char> v = {'{', '[', ']', '}'};
    std::cout << f(v);
    return 1;
}