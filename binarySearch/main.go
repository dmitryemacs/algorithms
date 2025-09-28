package main

import (
	"fmt"
)

func binarySearch(arr[] int, target int) int{
    left := 0
	right := len(arr) - 1

	for left <= right {
		mid := left + (right - left) / 2
		if(arr[mid] == target) {
			return mid

		} else if(arr[mid] < target) {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return -1
}

func main() {
	arr := []int{1, 3, 4, 6, 22, 44, 54, 55, 85, 91, 102, 202}
	fmt.Println("Slice: ", arr);
	fmt.Println("Search 55 index: ", binarySearch(arr[:], 55));
}
