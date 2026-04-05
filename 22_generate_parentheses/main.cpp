/*

 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

#include <iostream>
#include <string>
#include <unordered_set>

std::unordered_set<std::string> f(uint n) {
    std::unordered_set<std::string> s;
    if (n == 0) {
        return s;
    }
    if (n == 1) {
        s.insert("()");
        return s;
    }
    auto r = f(n - 1);
    for (const auto& v: r) {
        s.insert("()" + v);
        s.insert(v + "()");
        s.insert("(" + v + ")");
    }
    return s;
}

int main() {
    auto r = f(2);
    for (const auto& s: r) {
        std::cout << s << std::endl;
    }
    return 1;
}