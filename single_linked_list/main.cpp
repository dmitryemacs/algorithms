#include <iostream>
#include <ostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinedList {

private:
    Node* head; // указатель на голову списка

public: 
    LinedList() : head(nullptr) {} // Конструктор

    ~LinedList() { // Деструктор
        Node* current = head;
        Node* nextNode;
        while(current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void display() const {
        Node* current = head;
        while(current != nullptr) {
            std::cout << current->data << "-->";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main(void) {
    LinedList list;
    list.append(10);
    list.append(43);
    list.append(41);
    list.append(34);
    list.append(12);
    list.display();
}


