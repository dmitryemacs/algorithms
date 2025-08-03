#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bin_search(int arr[], int size, int x) {
    int low, hight, mid;
    low = 0;
    hight = size - 1;
    while(low <= hight) {
        mid = (low + hight) / 2;
        if(x < arr[mid]) {
            hight = mid - 1;
        } else if (x > arr[mid]) {
            low = mid + 1;
        }
        else return mid;
    }
    return -1;
}

int main(void) {
    int *arr = malloc(sizeof(int) * 10);
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    printf("Random array: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    printf("Введите значение для поиска: ");
    int num = 0;
    scanf("%d", &num);
    printf("Элемент под индексом: %d\n", bin_search(arr, 10, num));
}
