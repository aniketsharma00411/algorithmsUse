package main

import (
	"fmt"
	"math/rand"
)

func main() {
	slice := []int{43,123,42,2,45}
	fmt.Println("Unsorted:", slice)
	quicksort(slice)
	fmt.Println("Sorted:", slice)
}

func quicksort(a []int) []int {
    if len(a) < 2 {
        return a
    }
      
	left := 0
	right := len(a)-1  
    pivot := rand.Int() % len(a)
      
    a[pivot], a[right] = a[right], a[pivot]
      
    for i, _ := range a {
        if a[i] < a[right] {
            a[left], a[i] = a[i], a[left]
            left++
        }
    }
      
    a[left], a[right] = a[right], a[left]
      
    quicksort(a[:left])
    quicksort(a[left+1:])
      
    return a
}