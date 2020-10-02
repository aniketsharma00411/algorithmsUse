package main

import (
	"log"
	"os"
	"strconv"
)

func main() {
	arg := os.Args[1]

	if n, err := strconv.Atoi(arg); err != nil {
		log.Fatal(err)
	} else {
		log.Println(fibonacci(n))
	}

}

func fibonacci(num int) int {
	if num <= 1 {
		return num
	}

	return fibonacci(num-1) + fibonacci(num-2)
}
