#include <iostream>

class Node {

    public:
        int data;
        Node* next;
        Node* prev;

        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DualList {
    private:
        Node* head;
        Node* tail;


    public:
        DualList() : head(nullptr), tail(nullptr) {}

        ~DualList() {
            Node* current = head;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void displayBackward() const {
            Node *current = tail;
            while (current != nullptr) {
                std::cout << current->data << " "; 
                current = current->prev;
            }
            std::cout << std::endl;
        }

        void diplayFormward() const {
            Node *current = head;
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
};

int main (int argc, char *argv[]) {
    DualList list;
    list.append(43);
    list.append(82);
    list.append(23);
    list.append(33);
    list.append(3);
    list.append(8);
    list.append(26);
    std::cout << "Forward: "; list.diplayFormward();
    std::cout << "Backward: "; list.displayBackward();

    return 0;
}
