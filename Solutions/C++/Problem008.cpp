
#include <iostream>

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data;
};

bool countUnival(Node* node, int& unival) {
    if(node == nullptr) {
        return true;
    }

    bool leftUnival = countUnival(node->left, unival);
    bool rightUnival = countUnival(node->right, unival);

    if((!leftUnival or !rightUnival) or
       (node->left and node->data != node->left->data) or
       (node->right and node->right->data != node->data)) {
        return false;
    }

    ++unival;

    return true;
}

int main(int argc, char** argv) {

    return 0;
}
