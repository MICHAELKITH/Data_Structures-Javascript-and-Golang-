package main

import (
	"fmt"
	"time"
)

func f() {
	fmt.Println("F function")
}

func main() {
	go f()
	time.Sleep(time.Second * 1)

	fmt.Println("Main Function")
}