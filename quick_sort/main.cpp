#include <iostream>
#include <random>

template <size_t N> 
void quick_sort(int (&arr) [N], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for(int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
            std::swap(arr[i + 1], arr[high]);
            int partition = i++;
            
            quick_sort(arr, low, partition - 1);
            quick_sort(arr, partition -1, high);
        }
    }
}

template <size_t N>
void random(int (&arr) [N]) {
    std::random_device dev();
    std::mt19937 mt(dev());
    std::uniform_int_distribution<int> dis(1, 100);
    for(size_t i = 0; i < N; i++) {
        arr[i] = dis(mt);
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
