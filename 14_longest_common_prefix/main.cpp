/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>


std::string f(const std::vector<std::string>& v) {
    std::unordered_map<uint, std::unordered_set<char>> p;
    for (const auto& s: v) {
        for(auto i = 0; i < s.size(); ++i) {
            p[i].insert(s[i]);
        }
    }
    std::string r;
    for (auto i = 0; ; ++i) {
        if (p.count(i) == 0 || p[i].size() > 1) {
            return r;
        }
        r = r + *p[i].begin();
    }
}

int main() {
    std::vector<std::string> v = {};
    std::cout << f(v);
    return 0;
}
