#include <iostream>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    int original = x;
    long reversed = 0;

    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return original == reversed;
}

int main() {

    std::cout << "Palingrome 45:" << isPalindrome(45); std::cout << "\n";
    std::cout << "Palingrome 33:" << isPalindrome(33); std::cout << "\n";
    
    return 0;
}