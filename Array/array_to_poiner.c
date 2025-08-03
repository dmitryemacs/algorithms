#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum(int *start, int *end) {
    int total = 0;
    while (start < end) {
        total += *start;
        start++;
    }

    return total;
}

void rd(int *arr, int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void print(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
}

int main() {
    int *arr = malloc(sizeof(int) * 10);
    printf("Random array: ");
    rd(arr, 10);
    print(arr, 10);
    printf("Summ element array: %d\n", sum(arr, arr + 10));
    free(arr);
}
