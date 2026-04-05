/*

24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

*/

#include <iostream>

struct node {
    int v;
    node* n = nullptr;
};

void print(const node* l) {
    if (l == nullptr) {
        std::cout << "\n";
        return;
    }
    std::cout << l->v << " ";
    print(l->n);
}

void push_front(node** l, int v) {
    auto* nn = new node;
    nn->v = v;
    nn->n = *l;
    *l = nn;
}

void f(node* l) {
    if (l == nullptr || l->n == nullptr) {
        return;
    }
    auto* c = l;
    auto* n = c->n;
    while(true) {
        std::swap(c->v, n->v);
        c = n->n;
        if(c == nullptr) {
            break;
        }
        n = c->n;
        if (n == nullptr) {
            break;
        }
    }
}

int main() {
    node* l = nullptr;
    push_front(&l, 5);
    push_front(&l, 4);
    push_front(&l, 3);
    push_front(&l, 2);
    push_front(&l, 1);
    print(l);
    f(l);
    print(l);
    return 1;
}