/*

binary search

*/

#include <iostream>
#include <vector>

int f(const std::vector<int>& v, int s) {
    int b = 0;
    int e = v.size() - 1;
    while(b <= e) {
        int m = (b + e) >> 1;
        if (v[m] == s) {
            return m;
        } else if (v[m] < s) {
            b = m + 1;
        } else {
            e = m - 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> v = {0, 2, 4, 5, 7, 11};
    std::cout << f(v, 11);
    return 0;
}