/*

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3

Example 2:

Input: dividend = 7, divisor = -3
Output: -2

*/

#include <cstdlib>
#include <iostream>

int f(int a, int b) {
    int s = -1;
    if (a > 0 && b > 0 || a < 0 && b < 0) {
        s = 1;
    }
    a = std::abs(a);
    b = std::abs(b);

    int r = 0;
    while(a > b) {
        a -= b;
        ++r;
    }
    return s * r;
}

int main() {
    std::cout << f(-10, -3);
    return 0;
}
