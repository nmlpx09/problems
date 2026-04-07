/*
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
