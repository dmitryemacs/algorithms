#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(const int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void shell_sort(int* arr, int size) {
    for(int gap = size / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void randoms(int* arr, int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        arr[i] = random() % 100;
    }
}

void print_arr(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int* arr = malloc(sizeof(int) * 20);
    int input = 0;
    int result = 0;
    randoms(arr, 20);
    shell_sort(arr, 20);
    print_arr(arr, 20);


    printf("Enter search nubmer: ");
    scanf("%d", &input);
    result = binarySearch(arr, 20, input);
    if(result != -1) {
        printf("Found number %d index: %d", input, result);
    } else {
        printf("Number not found");
    }

    return 0;
}
