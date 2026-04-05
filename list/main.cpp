/*
list op
*/

#include <iostream>

struct Node {
    int v = 0;
    Node* next = nullptr;
};

Node* push_front(Node* l, int v) {
    auto* n = new Node;
    n->v = v;
    n->next = l;
    return n;
}

Node* push_back(Node* l, int v) {
    if (l == nullptr) {
        auto* n = new Node;
        n->v = v;
        return n;
    }
    l->next = push_back(l->next, v);
    return l;
}

Node* reverse(Node* l) {
    if (l == nullptr || l->next == nullptr) {
        return l;
    }
    auto n = l->next;
    l->next = nullptr; 
    for(; n != nullptr;) {
        auto nn = n->next;
        n->next = l;
        l = n;
        n = nn;
    }
    return l;
}

Node* reverse_r(Node* l, Node** h) {
    if (l == nullptr || l->next == nullptr) {
        *h = l;
        return l;
    }
    auto* r = reverse_r(l->next, h);
    r->next = l;
    l->next = nullptr;
    return l;
}

void print(const Node* l) {
    if (l == nullptr) {
        return;
    }
    std::cout << l->v << " ";
    print(l->next);
}

int main() {
    Node* l = nullptr;
    l = push_front(l, 10);
    push_back(l, 12);
    push_back(l, 13);
    l = push_front(l, 5);
    print(l);
    Node* nh = l;
    std::cout << std::endl;
    reverse_r(l, &nh);
    l = nh;
    print(l);
    return 0;
}
