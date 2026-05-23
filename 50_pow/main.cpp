/*

50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

*/

#include <iostream>

double f(double x, int n) {
    auto p = [] (auto x, auto n) {
        double r = 1;
        for (; n != 0; n >>= 1) {
            if (n & 1) {
                r *= x;
            }
            x *= x;
        }
        return r;
    };
    return (n > 0 ? p(x, n) : 1 / p(x, -n));
}

int main() {
    std::cout << f(2.0, -1);
    return 0;
}
