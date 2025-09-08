#include <iostream>
#include <vector>

int binarySearch(const std::vector<int> &arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
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

auto main(int argc, char *argv[]) -> int {

    std::vector<int> vec = {1, 4, 5, 8, 10};
    std::cout << "Vec: ";
    for(int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    int input;
    std::cout << "Enter number for search: "; std::cin >> input;
    int result = binarySearch(vec, input);
    if(result != -1) {
        std::cout << "number " << input << " found index: " << result + 1;
    } else {
        std::cout << "Not found";
    }

    return 0;
}
