/*
Given a string, find the length of the longest substring without repeating characters.

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: "pwwkew"
Output: 3

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

uint f(const std::string& s) {
    std::unordered_set<char> sc;
    uint ms = 0;
    for (auto i = 0, j = 0; i < s.size(); ++i) {
        while(sc.count(s[i]) > 0) {
            sc.erase(s[j++]);
        }
        ms = ms > (i - j + 1) ? ms : (i - j + 1);
        sc.insert(s[i]);
    }
    return ms;
}

int main() {
    std::string s = "bbbbbb";
    std::cout << f(s);
    return 0;
}