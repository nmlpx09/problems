/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

*/

#include <iostream>
#include <vector>

uint f(const std::vector<uint>& v, std::size_t b, std::size_t e) {
    std::vector<std::pair<std::size_t, std::size_t>> s;
    if (e - b <= 1) {
        return 0;
    }
    uint m = 0;
    uint mi = 0;
    uint r = 0;
    
    for (auto i = b + 1; i < e; ++i) {
        if (v[i] >= m) {
            m = v[i];
            mi = i;
        }
    }
    auto mb = v[e] < v[b] ? v[e] : v[b];
    if (m <= v[e] && m <= v[b]) {
        for (auto i = b + 1; i < e; ++i) {
            r += mb - v[i];
        }
    } else if (m <= v[e]) {
        for (auto i = mi + 1; i < e; ++i) {
            r += m - v[i];
        }
    } else if (m <= v[b]) {
        for (auto i = b + 1; i < mi; ++i) {
            r += m - v[i];
        }
    }
    if (m > v[b]) {
        r += f(v, b, mi);
    }
    if (m > v[e]) {
        r += f(v, mi, e);
    }
    return r;
}

int main() {
    std::vector<uint> v = {2, 1, 2};
    std::cout << f(v, 0, v.size() - 1);
    return 0;
}