#include <iostream>

enum Color { RED, BLACK };

class Node {
    public:
        int data;
        bool color;
        Node *left, *right, *parent;

        Node(int data) : data(data) {
            parent = left = right = nullptr;
            color = RED;
        }
};

class RedBlackTree {
private:
    Node *root;

    void rotateLeft(Node *&);
    void rotateRight(Node *&);
    void fixViolation(Node *&);
    void inorderDisplay(Node *root);
    Node* insertNodeHelper(Node *root, Node *newNode);

public:
    RedBlackTree() { root = nullptr; }
    void insert(int data);
    void inorder() { inorderDisplay(root); }
};

// Вставка узла
void RedBlackTree::insert(int data) {
    Node *newNode = new Node(data);
    root = insertNodeHelper(root, newNode);
    fixViolation(newNode);
}

Node* RedBlackTree::insertNodeHelper(Node *root, Node *newNode) {
    if (root == nullptr) {
        return newNode;
    }
    if (newNode->data < root->data) {
        root->left = insertNodeHelper(root->left, newNode);
        root->left->parent = root;
    } else if (newNode->data > root->data) {
        root->right = insertNodeHelper(root->right, newNode);
        root->right->parent = root;
    }
    return root;
}

void RedBlackTree::fixViolation(Node *&k) {
    Node *parent = nullptr;
    Node *grandparent = nullptr;

    while ((k != root) && (k->color != BLACK) && (k->parent->color == RED)) {
        parent = k->parent;
        grandparent = k->parent->parent;

        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;

            // Случай 1: Дядя красный
            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                k = grandparent;
            } else {
                // Случай 2: Дядя чёрный, узел — правый ребёнок
                if (k == parent->right) {
                    rotateLeft(parent);
                    k = parent;
                    parent = k->parent;
                }
                // Случай 3: Дядя чёрный, узел — левый ребёнок
                rotateRight(grandparent);
                std::swap(parent->color, grandparent->color);
                k = parent;
            }
        }
        // Случай B: Родитель — правый ребёнок
        else {
            Node *uncle = grandparent->left;

            // Случай 1: Дядя красный
            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                k = grandparent;
            } else {
                // Случай 2: Дядя чёрный, узел — левый ребёнок
                if (k == parent->left) {
                    rotateRight(parent);
                    k = parent;
                    parent = k->parent;
                }
                // Случай 3: Дядя чёрный, узел — правый ребёнок
                rotateLeft(grandparent);
                std::swap(parent->color, grandparent->color);
                k = parent;
            }
        }
    }
    root->color = BLACK;
}

// Левый поворот
void RedBlackTree::rotateLeft(Node *&x) {
    Node *y = x->right;
    x->right = y->left;
    if (x->right != nullptr) {
        x->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RedBlackTree::rotateRight(Node *&x) {
    Node *y = x->left;
    x->left = y->right;
    if (x->left != nullptr) {
        x->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

// Обход дерева (in-order)
void RedBlackTree::inorderDisplay(Node *root) {
    if (root == nullptr) return;
    inorderDisplay(root->left);
    std::cout << root->data << " ";
    inorderDisplay(root->right);
}

// Пример использования
int main() {
    RedBlackTree tree;
    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);

    std::cout << "In-order traversal: ";
    tree.inorder();
    return 0;
}
