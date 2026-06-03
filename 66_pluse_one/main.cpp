/*

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/

#include <iostream>
#include <vector>

void f(std::vector<uint>& v) {
    uint d = 0;
    for (int i = v.size() - 1; i >= 0; --i) {
        auto nv = v[i] + d;
        if (i == v.size() - 1) {
            nv += 1;
        }
        v[i] = nv % 10;
        d = nv / 10;
        if (d == 0) {
            break;
        }
    };
    if (d != 0) {
        v.resize(v.size() + 1);
        for (int i = v.size() - 1; i > 0; --i) {
            v[i] = v[i - 1];
        }
        v[0] = d;
    }
}

int main() {
    std::vector<uint> v = {9, 9, 9};
    f(v);
    for (const auto& e : v) {
        std::cout << e << " ";
    }
    return 0;
}
