/*

Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

in [1, 2, 3, 2, 4, 2]

out [1, 3, 4]

*/

#include <iostream>
#include <vector>

void f(std::vector<int>& v, int e) {
    std::size_t k = 0;
    for (auto i = 0; i < v.size(); ++i) {
        if (v[i] != e) {
            v[k] = v[i];
            ++k;
        }
    }
    v.resize(k);
}

int main() {
    std::vector<int> v = {1, 2, 3, 2, 4, 2};
    f(v, 2);
    for (const auto& e : v) std::cout << e << " ";
    return 0;
}
