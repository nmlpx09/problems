/*

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

*/

#include <iostream>
#include <string>

bool z(const std::string& a) {
    for (auto i = 0; i < a.size(); ++i) {
        if (a[i] != '0') {
            return false;
        }
    }
    return true;
}

std::string s(const std::string& a, const std::string& b) {
    std::string r;
    uint d = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    for (; j >= 0 && i >= 0; --j, --i) {
        uint s = (uint)a[i] + (uint)b[j] - '0' - '0' + d;
        d = s / 10;
        r = (char)(s % 10 + '0') + r;
    }
    for (; j >= 0; --j) {
        uint s = (uint)b[j] - '0' + d;
        d = s / 10;
        r = (char)(s % 10 + '0') + r;
    }
    for (; i >= 0; --i) {
        uint s = (uint)a[i] - '0' + d;
        d = s / 10;
        r = (char)(s % 10 + '0') + r;
    }
    if (d != 0) {
        r = (char)(d + '0') + r;
    }
    if (r.size() == 0) {
        return "0";
    }
    return r;
}

std::string d(const std::string& a) {
    if (z(a)) {
        return "0";
    }
    std::string r;
    int d = 1;
    int i = a.size() - 1;
    for (; i >= 0; --i) {
        int s = (int)a[i] - '0' - d;
        if (s < 0) {
            r = (char)(s + '0' + 10) + r;
        } else {
            r = (char)(s + '0') + r;
            --i;
            break;
        }
    }
    for (; i >= 0; --i) {
        r = a[i] + r;
    }
    return r;
}

std::string f(const std::string& a, const std::string& b) {
    std::string r = "0";
    std::string bb = b;
    while (!z(bb)) {
        r = s(r, a);
        bb = d(bb);
    }
    return r;
}

int main() {
    std::cout << f("456", "123") << std::endl;
    return 0;
}
