/*

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note:

    Given n will be between 1 and 9 inclusive.
    Given k will be between 1 and n! inclusive.

Example 1:

Input: n = 3, k = 3
Output: "213"

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

uint fact(uint n) {
    if (n <= 1) {
        return 1;
    }
    return n * fact(n - 1);
} 

std::string f(uint n, int k) {
    if (n == 0) {
        return "";
    }
    if (k > fact(n)) {
        return "";
    }
    std::vector<uint> v;
    for (int i = 1; i <= n; ++i) {
        v.push_back(i);
    }
    std::string s;
    while (n != 1) {
        uint nn = fact(n - 1);
        auto cn = k / nn;
        if (k <= nn) {
            cn -= 1;
        }
        s += std::to_string(v[cn]);
        std::remove(v.begin(), v.end(), v[cn]);
        n = n - 1;
        k = k - nn;
    }
    s += std::to_string(v[0]);
    return s;
}

int main() {
    std::cout << f(2, 2);
    return 0;
}