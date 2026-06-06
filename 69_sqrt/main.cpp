/*

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2

Example 2:

Input: 8
Output: 2

*/

#include <iostream>

uint f(uint n) {
    if (n == 1) {
        return 0;
    }
    uint r = 1;
    uint rr = 1;
    while (true) {
        rr = rr + r * 2 + 1;
        if (rr > n) {
            return r;
        }
        ++r;
    }
}

int main() {
    std::cout << f(10);
    return 0;
}
