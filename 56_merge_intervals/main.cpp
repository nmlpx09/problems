/*

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

#include <vector>
#include <iostream>
#include <utility>

std::vector<std::pair<uint, uint>> f(const std::vector<std::pair<uint, uint>>& v) {
    if (v.size() == 0) {
        return {};
    }
    std::vector<std::pair<uint, uint>> r;
    uint pl = v[0].first;
    uint pr = v[0].second;
    uint cl;
    uint cr;
    for (auto i = 1; i < v.size(); ++i) {
        cl = v[i].first;
        cr = v[i].second;
        if (pr < cl) {
            r.push_back({pl, pr});
            pl = v[i].first;
            pr = v[i].second;
        } else {
            pr = v[i].second;
        }
    }
    r.push_back({pl, pr});
    return r;
}

int main() {
    std::vector<std::pair<uint, uint>> v = {{1, 4}, {4, 5}};
    auto r = f(v);
    for (const auto e : r) {
        std::cout << e.first << ' ' << e.second << std::endl;
    }
    return 0;
}
