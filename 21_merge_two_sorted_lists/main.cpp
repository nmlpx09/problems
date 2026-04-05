/*

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

#include <iostream>

struct node {
    int v;
    node* n = nullptr;
};

void print(const node* l) {
    if (l == nullptr) {
        return;
    }
    std::cout << l->v << std::endl;
    print(l->n);
}

void push_front(node** l, int v) {
    auto* n = new node;
    n->v = v;
    n->n = *l;
    *l = n;
}

node* merdge(node* l1, node* l2) {
    node* ml = nullptr;
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }

    auto* c1 = l1;
    auto* c2 = l2;

    if (l1->v < l2->v) {
        ml = l1;
        c1 = l1->n;
    } else {
        ml = l2;
        c2 = l2->n;
    } 
    auto* n = ml;
    while(c1 != nullptr && c2 != nullptr) {
        if (c1->v < c2->v) {
            n->n = c1;
            auto* nn = c1->n;
            n = c1;
            c1 = nn;
        } else {
            n->n = c2;
            auto* nn = c2->n;
            n = c2;
            c2 = nn;
        }
    }
    if (c1 != nullptr) {
        n->n = c1;
    }
    if (c2 != nullptr) {
        n->n = c2;
    }
    return ml;
}

int main() {
    node* l1 = nullptr;
    node* l2 = nullptr;
    push_front(&l1, 5);
    push_front(&l1, 4);
    push_front(&l1, 2);
    push_front(&l1, 1);
    push_front(&l2, 4);
    push_front(&l2, 3);
    push_front(&l2, 1);
    print(l1);
    print(l2);
    std::cout << "\n";
    auto* r = merdge(l2, l1);
    print(r);
    return 1;
}