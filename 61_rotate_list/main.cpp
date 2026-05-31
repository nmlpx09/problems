/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/

#include <iostream>

struct node {
    uint v = 0;
    node* next = nullptr;
};

void push_front(node** l, uint v) {
    auto* nn = new node;
    nn->v = v;
    nn->next = *l;
    *l = nn;
}

void print(const node* l) {
    auto* cn = l;
    while (cn != nullptr) {
        std::cout << cn->v << std::endl;
        cn = cn->next;
    }
}

void rootate(node** l, uint k) {
    if (*l == nullptr) {
        return;
    }
    auto* cn = *l;
    uint n  = 0;
    while (cn != nullptr) {
        cn = cn->next;
        ++n;
    }

    if (n >= k) {
        k = n - k + 1;
    } else {
        auto od = k % n;
        if (od == 0) {
            k = 1;
        } else {
            k = n - od + 1;
        }
    }

    cn = *l;
    while (k != 0) {
        while (cn != nullptr) {
            if (--k == 0) {
                break;
            }
            cn = cn->next;
        }
        if (k != 0) {
            cn = *l;
        }
    }

    if (cn == *l) {
        return;
    }

    auto* nh = cn;
    auto* cc = cn->next;

    while (cc != nullptr) {
        cn = cc;
        cc = cn->next;
    }
    cn->next = *l;
    cn = *l;
    cc = cn->next;

    while(cc != nh) {
        cn = cc;
        cc = cn->next;
    }

    cn->next = nullptr;
    *l = nh;
}

int main() {
    node* l = nullptr;
    push_front(&l, 5);
    push_front(&l, 4);
    push_front(&l, 3);
    push_front(&l, 2);
    push_front(&l, 1);
    print(l);
    std::cout << '\n';
    rootate(&l, 2);
    print(l);
    return 0;
}
