package main

import (
	"fmt"
	"math"
)


func pt() {
	i, j := 42, 2701
	
	p := &i // point to i
	fmt.Println(*p) // read i through the pointer
	*p = 21 // set i through the pointer
	fmt.Println(i) // see the new value of i
	
	p = &j // point to j
	*p = *p / 37 // divide j through the pointer
	fmt.Println(j) // see the new value of j
	}


// Function to check if a number is prime
func isPrime(num int) bool {
	if num < 2 {
		return false
	}
	for i := 2; i <= int(math.Sqrt(float64(num))); i++ {
		if num%i == 0 {
			return false
		}
	}
	return true
}

// Function to print Fizz, Buzz, FizzBuzz, and Prime
func fizzBuzzPrime() {
	for i := 1; i <= 100; i++ {
		output := ""

		// Check if the number is prime
		if isPrime(i) {
			output += "Prime "
		}

		// Check for multiples of 3, 5, or both
		if i%3 == 0 && i%5 == 0 {
			output += "FizzBuzz"
		} else if i%3 == 0 {
			output += "Fizz"
		} else if i%5 == 0 {
			output += "Buzz"
		}

		// If none of the above, just print the number
		if output == "" {
			fmt.Println(i)
		} else {
			fmt.Println(output)
		}
	}
}

func main() {
	// Call the function to execute the program
	fizzBuzzPrime()
	pt()
}
