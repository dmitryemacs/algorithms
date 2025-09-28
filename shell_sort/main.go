package main

import (
	"fmt"
	"math/rand"
	"time"
)

func random(arr[]int) {
    for i := 0; i < len(arr); i++ {
		r := rand.New(rand.NewSource(time.Now().UnixNano()))
		arr[i] = r.Int() % 100
	}
}

func ShellSort(arr[]int) {
    for gap := len(arr) / 2; gap > 0; gap /= 2 {
		for i := 0; i < len(arr); i++ {
			temp := arr[i]
			j := i
			for j >= gap && arr[j - gap] > temp {
				arr[j] = arr[j - gap]
				j -= gap
			}
			arr[j] = temp
		}
	}
}

func main() {
	arr := [30]int{}
	random(arr[:])
	fmt.Println("Radnom slice: ", arr)
	ShellSort(arr[:])
	fmt.Println("Soted slice: ", arr)

}
