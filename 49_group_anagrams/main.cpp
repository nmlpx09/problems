/*

49. Group Anagrams

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

std::unordered_map<std::string, std::vector<std::string>> f(const std::vector<std::string>& v) {
    std::unordered_map<std::string, std::vector<std::string>> r;
    for (auto i = 0; i < v.size(); ++i){
        auto k = v[i];
        std::sort(k.begin(), k.end());
        r[k].push_back(v[i]);
    }

    return r;
}

int main() {
    std::vector<std::string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto r = f(v);

    for (const auto& [_ , v]: r) {
        for (const auto& e : v) {
            std::cout << e << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
