package main

import (
	"fmt"
	"math/rand"
)

func printArray(arr []int) {
	for _, v := range arr {
		fmt.Printf("%d ", v)
	}
	fmt.Println()
}

func randomArray(size, max int) []int {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = randInt(0, max)
	}
	return arr
}

func randInt(min int, max int) int {
	return min + int((float64(max-min+1))*randFloat())
}

func randFloat() float64 {
	return float64(rand.Intn(10000)) / 10000.0
}

func RadixSort(arr []int) []int {
	max := getMax(arr)
	for exp := 1; max/exp > 0; exp *= 10 {
		countingSort(arr, exp)
	}
	return arr
}

func getMax(arr []int) int {
	max := arr[0]
	for _, v := range arr {
		if v > max {
			max = v
		}
	}
	return max
}

func countingSort(arr []int, exp int) {
	n := len(arr)
	output := make([]int, n)
	count := make([]int, 10)

	for i := 0; i < n; i++ {
		index := (arr[i] / exp) % 10
		count[index]++
	}

	for i := 1; i < 10; i++ {
		count[i] += count[i-1]
	}

	for i := n - 1; i >= 0; i-- {
		index := (arr[i] / exp) % 10
		output[count[index]-1] = arr[i]
		count[index]--
	}

	for i := 0; i < n; i++ {
		arr[i] = output[i]
	}
}

func main() {
	size := 10
	maxValue := 999

	arr := randomArray(size, maxValue)
	fmt.Println("Original array:")
	printArray(arr)

	sortedArr := RadixSort(arr)
	fmt.Println("Sorted array:")
	printArray(sortedArr)
}
