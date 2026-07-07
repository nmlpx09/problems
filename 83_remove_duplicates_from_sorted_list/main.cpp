/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2

*/

#include <iostream>

struct node {
    uint v = 0;
    node* next = nullptr;
};

void input(node** l, uint v) {
    auto* nn = new node;
    nn->v = v;
    nn->next = *l;
    *l = nn;
}

void print(node* l) {
    auto n = l;
    while(n != nullptr) {
        std::cout << n->v << std::endl;
        n = n->next;
    }
}

void f(node* l) {
    if (l == nullptr) {
        return;
    }

    auto* cn = l;
    auto* nn = cn->next;

    while(nn != nullptr) {
        if (cn->v == nn->v) {
            cn->next = nn->next;
            delete nn;
            nn = cn->next;
        } else {
            cn = nn;
            nn = cn->next;
        }
    }
}

int main() {
    node* l = nullptr;
    input(&l, 1);
    input(&l, 1);
    input(&l, 1);
    input(&l, 1);
    input(&l, 1);
    input(&l, 1);
    input(&l, 1);
    f(l);
    print(l);
    return true;
}
