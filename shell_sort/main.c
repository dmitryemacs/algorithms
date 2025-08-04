#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell_sort(int *arr, int size) {
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

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void randomization(int arr[], int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int main(int argc, char *argv[])
{   
    int *arr = malloc(sizeof(int) * 20);
    printf("Random array: ");
    randomization(arr, 20);
    print(arr, 20);
    shell_sort(arr, 20);
    printf("Sorted array: "); print(arr, 20);

    free(arr);
    return 0;
}
