/*

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

*/

#include <iostream>

struct node {
    int v;
    node* next = nullptr;
};

void push_front(node** l, int v) {
    auto* n = new node;
    n->v = v;
    n->next = *l;
    *l = n;
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
    auto* n = (*l)->next;
    auto* c = *l;
    (*l)->next = nullptr;
    while(n != nullptr) {
        auto* nn = n->next;
        n->next = c;
        c = n;
        n = nn;
    }
    *l = c;
}

void f(node** l, uint r) {
    if(r == 0) {
        return;
    }
    reverse(l);
    if (r == 1) {
        auto n = (*l)->next;
        delete *l;
        *l = n;
    } else {
        auto* p = *l;
        auto* c = p->next;
        while (c != nullptr && r > 1) {
            --r;
            if (r == 1) {
                p ->next = c-> next;
                delete c;
                break;
            }
            p = c;
            c = c->next;
        }
    }
    reverse(l);
}

int main() {
    node* l = nullptr;
    push_front(&l, 5);
    push_front(&l, 4);
    push_front(&l, 3);
    push_front(&l, 2);
    push_front(&l, 1);
    f(&l, 6);
    print(l);
    return 1;
}