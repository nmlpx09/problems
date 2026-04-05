/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

#include <iostream>

struct node {
    uint v = 0;
    node* next = nullptr;
};

void pus_front(node** l, uint v) {
    auto* nn = new node;
    nn->next = *l;
    nn->v = v;
    *l = nn;
}

void print(const node* l) {
    if (l == nullptr) {
        return;
    }
    std::cout << l->v << std::endl;
    print(l->next);
}

void reverse(node** l) {
    if (*l == nullptr) {
        return;
    }
    node* n = (*l)->next;
    node* c = *l;
    c->next = nullptr;
    for (; n != nullptr;) {
        auto* nn = n->next;
        n->next = c;
        c = n;
        n = nn;
    }
    *l = c;
}

node* summ(node* n1, node* n2) {
    reverse(&n1);
    reverse(&n2);
    node* r = nullptr;
    uint s = 0;
    for (; n1 != nullptr || n2 != nullptr; n1 = n1->next, n2 = n2->next) {
        auto n = n1->v + n2->v + s;
        s = n / 10;
        pus_front(&r, n % 10);
    }
    if (s > 0) {
        pus_front(&r, s);
    }
     reverse(&r);
     return r;
}

int main() {
    node* n1 = nullptr;
    node* n2 = nullptr;
    pus_front(&n1, 3);
    pus_front(&n1, 4);
    pus_front(&n1, 2);
    pus_front(&n2, 4);
    pus_front(&n2, 6);
    pus_front(&n2, 5);

    auto* r = summ(n1, n2);
    print(r);
    return 0;
}