
#include <iostream>

class Node {
public:
    Node* xorNode;
    int data;

    friend Node* operator^ (const Node* lhs, const Node& rhs);
    friend Node* operator^ (const Node& lhs, const Node* rhs);
    friend Node* operator^ (const Node& lhs, const Node& rhs);
};

class XORList {
public:
    XORList();
    ~XORList();
    
    size_t size;
    Node* node;

    void visit();
    Node* xorFunction(Node* left, Node* right);
    void add(int data);

    // TODO: Overload << operator
    void print();
    void clean();
};

XORList::XORList(): size(0), node(nullptr) {
}

XORList::~XORList() {
    clean();
}

Node* XORList::xorFunction(Node* left, Node* right) {
    return (Node*)((uintptr_t)(left) ^ (uintptr_t)(right));
}

Node* operator^ (const Node& lhs, const Node* rhs) {
    const Node* lhsP = &lhs;
    return (Node*)((uintptr_t)(lhsP) ^ (uintptr_t)(rhs));
}

Node* operator^ (const Node* lhs, const Node& rhs) {
    const Node* rhsP = &rhs;
    return (Node*)((uintptr_t)(lhs) ^ (uintptr_t)(rhsP));
}

Node* operator^ (const Node& lhs, const Node& rhs) {
    const Node* lhsP = &lhs;
    const Node* rhsP = &rhs;
    return (Node*)((uintptr_t)(lhsP) ^ (uintptr_t)(rhsP));
}

void XORList::visit() {
    Node* current = node;
    Node* previous = nullptr;
    Node* next = nullptr;

    while(current != NULL) {
        next = *previous ^ *current->xorNode;
        // next = xorFunction(previous, current->xorNode);

        previous = current;
        current = next;
    }
}

void XORList::add(int data) {
    Node* newNode = new Node();
    newNode->data = data;

    // newNode->xorNode = xorFunction(node, nullptr);
    newNode->xorNode = *node ^ nullptr;

    if(node) {
        node->xorNode = *newNode ^ (*node->xorNode ^ nullptr);
        // node->xorNode = xorFunction(newNode, xorFunction(node->xorNode,  NULL));
    }

    ++size;

    node = newNode;
}

void XORList::print() {
    Node* current = node;  
    Node* previous = nullptr;  
    Node* next;  
    
    while(current != nullptr) {
        std::cout << current->data << " ";

        next = *previous ^ *current->xorNode;
        // next = xorFunction(previous, current->xorNode);

        previous = current;
        current = next;
    }
}

void XORList::clean() {
    Node* current = node;
    Node* previous = nullptr;
    Node* next = nullptr;

    if(node == nullptr) {
        return;
    }

    while(current != nullptr) {
        // next = xorFunction(previous, current->xorNode);
        next = *previous ^ *current->xorNode;
        previous = current;
        delete current;
        current = next;
    }
}

int main(int argc, char** argv) {
    
    return 0;
}
