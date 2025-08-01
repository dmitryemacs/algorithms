#include <iostream>

int linear_search(int arr[], int size, int x) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == x) {
            return i + 1;
        }
    }
    return -1;
}

int main(void) {
    int arr[10] = {1, 3, 85, 35, 35, 24, 63, 5, 4, 73};
    int x = 0;
    std::cout << "Enter number for search: "; 
    std::cin >> x;
    std::cout << "Index = " << linear_search(arr, 10, x);
    return 0;
}