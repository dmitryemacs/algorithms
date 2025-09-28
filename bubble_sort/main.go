package main

import (
	"fmt"
	"math/rand"
	"time"
)

func random(arr[]int) {
	for i := 0; i < len(arr); i++ {
		arr[i] = rand.New(rand.NewSource(time.Now().UnixNano())).Int() % 100
	}
}

func BubbleSort(arr[]int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr) - i - 1; j++ {
			if(arr[j] > arr[j + 1]) {
				arr[j], arr[j + 1] = arr[j + 1], arr[j];
			}
		}
	}
}

func main() {
	arr := [30]int{}
	random(arr[:])
	fmt.Println("Random slice: ", arr)
	BubbleSort(arr[:])
	fmt.Println("Sorted slice: ", arr)
}
