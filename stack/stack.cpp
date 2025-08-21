#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    
    void push(const T& element) {
        elements.push_back(element);
    }

    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Стек пуст");
        }
        elements.pop_back();
    }

    T top() const {
        if (isEmpty()) {
            throw std::out_of_range("Стек пуст");
        }
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    Stack<int> intStack;

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    std::cout << "Верхний элемент: " << intStack.top() << std::endl;
    intStack.pop();
    std::cout << "Верхний элемент после pop: " << intStack.top() << std::endl;

    return 0;
}
