#include <iostream>
#include <vector>
#include <random>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {
        destroyTree(root);
    }

    void insert(int value) {
        insertRec(root, value);
    }

    void inorder() {
        inorderRec(root);
    }

private:

    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            std::cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    Node* insertRec(Node* node, int value) {
        if(node != nullptr) {
            return new Node(value);
        }
        if(value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->left, value);
        }
        return node;
    }

    void destroyTree(Node* node) {
        if(node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
        }
        delete node;
    }
};

template <class T>
void merge(T *arr, T *temp_arr, int start, int mid, int end) {
    int temp = 0;
    int lower = start;
    int upper = mid + 1;
    while (lower <= mid && upper <= end) {
        if (arr[lower] < arr[upper]) {
            temp_arr[temp++] = arr[lower++];
        } else {
            temp_arr[temp++] = arr[upper++];
        }
    }
    while(lower <= mid ) {
        temp_arr[temp++] = arr[lower++];
    }
    while (upper <= end) {
        temp_arr[temp++] = arr[upper++];
    }
    for (int i = 0; i < temp; i++) {
        arr[start + i] = temp_arr[i];
    }
}

template <class T>
void ms_helper(T* arr, T* temp_arr, int head, int tail) {
    if(head >= tail) {
        return;
    }
    int mid = (head + tail) / 2;
    ms_helper(arr, temp_arr, head, mid);
    ms_helper(arr, temp_arr, mid + 1, tail);
    merge(arr, temp_arr, head, mid, tail);
}

template <class T>
void merge_sort(T* arr, int size) {
    T* temp_arr = new T[size];
    ms_helper(arr, temp_arr, 0, size - 1);
    delete[] temp_arr;
}

void radix_sort(int *arr, int size) {
    int *a0 = new int[size];
    int *a1 = new int[size];
    for (int radix = 0; radix < 32; radix++) {
        int a0_size = 0;
        int a1_size = 0;
        for (int i = 0; i < size; i++) {
            if ((arr[i] & (1 << radix)) == 0) {
                a0[a0_size++] = arr[i];
            } else {
                a1[a1_size++] = arr[i];
            }
        }
        for (int i = 0; i < a0_size; i++) {
            arr[i] = a0[i];
        }
        for (int i = 0; i < a1_size; i++) {
            arr[a0_size + i] = a1[i];
        }
    }
    delete[] a0;
    delete[] a1;
}

void shell_sort(int *arr, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template <class T>
void print(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template <class T>
void random(T* arr, int size) {
    std::random_device dev;
    std::mt19937 mt(dev());
    std::uniform_int_distribution<int> dis(1, 100);
    for (int i = 0; i < size; i++) {
        arr[i] = dis(mt);
    }
}

int main() {
    int* arr = new int[20];
    std::cout << "Random array: "; random(arr, 20); print(arr, 20);
    std::cout << "Sorted array: "; radix_sort(arr, 20); print(arr, 20);
    return 0;
}