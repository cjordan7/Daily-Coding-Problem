
#include <iostream>
#include <string>
#include <vector>

struct Node;

struct Node {
    Node* left;
    Node* right;
    char data;
};

void serialize(Node* node, std::string::iterator* s) {
    if(node == nullptr) {
        return;
    }

    *s += node->data;
    serialize(node->left, s);
    serialize(node->right, s);
}

void deserialize(Node* node, std::string& string, std::string::iterator* s) {
    if(string.end() == *s) {
        return;
    }

    node = new Node();
    
    node->data = *(*s);
    ++s;
    serialize(node->left, s);
    serialize(node->right, s);    
}

int main(int argc, char** argv) {
    return 0;
}
