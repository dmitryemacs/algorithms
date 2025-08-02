#include <stdio.h>

void insertion_sort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        int j = i;
        while ((j > 0) && (array[j] < array[j - 1])) {
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
}

void print(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {

    int arr[10] = {1, 4, 2, 53, 12, 5, 9, 10, 73, 17};
    printf("Not sort array: ");
    print(arr, 10);
    printf("Sort array: ");
    insertion_sort(arr, 10);
    print(arr, 10);
}
