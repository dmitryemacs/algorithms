#include <iostream>
#include <random>

void shell_sort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void randomization(int *arr, int size) {
    std::random_device dev;
    std::mt19937 mt(dev());
    std::uniform_int_distribution<int> dis(1, 1000);
    for (int i = 0; i < size; i++) {
        arr[i] = dis(mt);
    }
}

int main(int argc, char const *argv[])
{
    int *arr = new int[10000000];
    randomization(arr, 10000000);
    std::cout << "Rand" << std::endl; 
    shell_sort(arr, 10000000);
    std::cout << "Sorted" << std::endl;

    return 0;
}
