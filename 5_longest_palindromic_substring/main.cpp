/*

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"

*/

#include <iostream>
#include <string>

std::string dp(const std::string& s, int i, int j) {
    std::string r;
    for(; i >= 0 && j < s.size(); --i, ++j) {
        if (s[i] != s[j]) {
            return r;
        }
        r = s[i] + r + s[j];

    }
    return r;
}

std::string p(const std::string& s, int i) {
    std::string r = std::string{s[i]};
    for(auto j = i - 1, k = i + 1; j >= 0 && k < s.size(); --j, ++k) {
        if (s[j] != s[k]) {
            return r;
        }
        r = s[j] + r + s[k];

    }
    return r;
}

std::string f(const std::string& s) {
    if (s.size() <= 1 || s.size() == 2 && s[0] == s[1]) {
        return s;
    }

    std::string r;

    for (auto i = 1; i < s.size() - 1; ++i) {
        auto pr = p(s, i);
        r = r.size() < pr.size() ? pr : r;
        if (s[i] == s[i + 1]) {
            auto dr = dp(s, i, i + 1);
            r = r.size() < dr.size() ? dr : r;
        }
    }
    return r;
}

int main() {
    std::cout << f("babab") << std::endl;
	return 0;
}
