#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int *temp_arr, int start, int mid, int end) {
    int temp = 0;
    int lower = start;
    int upper = mid + 1;

    while (lower <= mid && upper <= end) {
        if(arr[lower] < arr[upper]) {
            temp_arr[temp++] = arr[lower++];
        } else {
            temp_arr[temp++] = arr[upper++];
        }
    }

    while (lower <= mid) {
        temp_arr[temp++] = arr[lower++];
    }
    while (upper <= end) {
        temp_arr[temp++] = arr[upper++];
    }
    for(int i = 0; i < temp; i++) {
        arr[start + i] = temp_arr[i];
    }
}

void ms_helper(int arr[], int *temp_arr, int head, int tail) {
    if (head >= tail) return;
    int mid = (head + tail) / 2;
    ms_helper(arr, temp_arr, head, mid);
    ms_helper(arr, temp_arr, mid + 1, tail);
    merge(arr, temp_arr, 0, mid, tail);
}

void merge_sort(int arr[], int size) {
    int *temp_arr = malloc(sizeof(int) * size);
    ms_helper(arr, temp_arr, 0, size - 1);
    free(temp_arr);
}

void rands(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int *arr = malloc(sizeof(int) * 20);
    printf("Random array: "); rands(arr, 20); print(arr, 20);
    printf("Sorted array: "); merge_sort(arr, 20); print(arr, 20);
    return 0;
}
