#include <iostream>

void insertion_sort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int j = i;
		while ((j > 0) && (array[j] < array[j-1])) {
			int temp = array[j];
			array[j] = array[j -1];
			array[j-1] = temp;
			j--;
		}
	}
}

void print(int array[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    } 
    std::cout << std::endl;
}

int main(void) {
    int array[10] = {1, 4, 7, 32, 51, 65, 34, 33, 76 ,4};
    std::cout << "Array: "; print(array, 10);
    insertion_sort(array, 10);
    std::cout << "Sorted array: "; print(array, 10);
}
