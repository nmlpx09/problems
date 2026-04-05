/*
Given a 32-bit signed integer, reverse digits of an integer.

Input: 123
Output: 321

Input: 120
Output: 21

Input: -123
Output: -321
*/

#include <list>
#include <iostream>

int f(int n) {
    std::list<int> l;
    bool sig = n < 0;
    for (; n != 0; n /= 10) {
        l.push_front(n % 10);
    }
    auto result = 0;
    auto m = 1;
    for (const auto& v: l) {
        result += v * m;
        m *= 10;
    }
    if (sig) {
        return -1 * result;
    }
    return result;
}

int main() {
    std::cout << f(-123);
    return 0;
}