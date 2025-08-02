#include <stdio.h>
#include <stdlib.h>

void sort_radix(int array[], int size) {
    int *a0 = (int *)malloc(size * sizeof(int));
    int *a1 = (int *)malloc(size * sizeof(int));

    for(int radix = 0; radix < 32; radix++) {
        int a0_size = 0;
        int a1_size = 0;
        for(int i = 0; i < size; i++) {
            if((array[i] & (1 << radix)) == 0) {
                a0[a0_size++] = array[i];
            } else {
                a1[a1_size++] = array[i];
            }
        }
        for (int i = 0; i < a0_size; i++) {
            array[i] = a0[i];
        }
        for (int i = 0; i < a1_size; i++) {
            array[a0_size + i] = a1[i];
        }
    }
    free(a0);
    free(a1);
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{   
    int arr[10];
    for(int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    printf("Random array: ");
    print(arr, 10);
    printf("Sorted array: "); sort_radix(arr, 10); print(arr, 10);

    return 0;
}
