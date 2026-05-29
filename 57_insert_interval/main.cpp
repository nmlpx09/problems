/*

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

*/

#include <vector>
#include <iostream>
#include <utility>

std::vector<std::pair<uint, uint>> f(const std::vector<std::pair<uint, uint>>& v, const std::pair<uint, uint>& p) {
    std::vector<std::pair<uint, uint>> r;
    uint pl = v[0].first;
    uint pr = v[0].second;
    uint cl;
    uint cr;
    if ( v.size() == 1) {
        r.push_back({v[0].first, v[0].second});
    }
    auto i = 1;
    for (; i < v.size(); ++i) {
        cl = v[i].first;
        cr = v[i].second;

        if (cl > p.second) {
            r.push_back({pl, pr});
            break;
        }

        if (pr > p.first) {
            pr = cr;
        } else {
            r.push_back({pl, pr});
            pl = cl;
            pr = cr;
        }
    }
    for (; i < v.size(); ++i) {
        r.push_back({v[i].first, v[i].second});
    }
    return r;
}

int main() {
    std::vector<std::pair<uint, uint>> v = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    auto r = f(v, {4, 8});
    for (const auto e : r) {
        std::cout << e.first << " " << e.second << std::endl;
    }
}
