#include <iostream>
#include <random>

template <size_t N>
void sort(int (&arr) [N]) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N - i - 1; j++)
      if(arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
  }  
}

template <size_t N>
void print(int (&arr) [N]) {
    for(size_t i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template <size_t N>
void randomization(int (&arr) [N]) {
    std::random_device dev;
    std::mt19937_64 mt(dev());
    std::uniform_int_distribution<int> dis(1, 100);

    for(size_t i = 0; i < N; i++) {
        arr[i] = dis(mt);
    }
}

int main(void) {
    int arr[20];
    randomization(arr);
    std::cout << "Random array: "; print(arr);
    std::cout << "Sort array: "; sort(arr); print(arr);
}
