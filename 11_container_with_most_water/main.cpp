/*

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

*/

#include <iostream>
#include <vector>

uint f(const std::vector<uint>& v) {
    uint r = 0;

    for(std::size_t i = 0, j = v.size() - 1; i < j; ) {
        auto rr = (v[i] < v[j] ? v[i] : v[j]) * (j - i);
        r = r > rr ? r : rr;
        if (v[i] < v[j]) {
            ++i;
        } else {
            --j;
        }
    }
    return r;
}

int main() {
    std::vector<uint> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << f(v);
    return 0;
}
