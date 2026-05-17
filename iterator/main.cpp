/*

custom lazy iterator

*/

#include <iterator>
#include <iostream>
#include <cstddef>
#include <functional>

struct Iterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = int;
    using pointer = int*;
    using reference = int&;
    using function_type = std::function<value_type(const reference)>;
public:
    Iterator(pointer ptr) : m_ptr(ptr) {}
    Iterator() = default;

    reference operator*() const {
        if (m_f) {
            *m_ptr = m_f(*m_ptr);
        }
        return *m_ptr;
    }
    Iterator& operator++() { m_ptr++; return *this; }
    Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
    Iterator& operator | (function_type f) { m_f = f; return *this; }
    friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

private:
    pointer m_ptr;
    function_type m_f;
};

class Integers {
public:
    Iterator begin() { return Iterator(&m_data[0]); }
    Iterator end() { return Iterator(&m_data[10]); }

private:
    int m_data[10];
};

int main() {
    static_assert(std::forward_iterator<Iterator>);

    Integers mInt{};

    for (auto it = mInt.begin(); it != mInt.end(); ++it) {
        *it = 0;
        std::cout << *it << std::endl;
    }

    for (auto it = mInt.begin() | [](const int& v) { return v + 2; }; it != mInt.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
