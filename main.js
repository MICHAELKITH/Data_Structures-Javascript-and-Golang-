// Function to check if a number is prime
function isPrime(num) {
  if (num < 2) return false;
  for (let i = 2; i <= Math.sqrt(num); i++) {
      if (num % i === 0) return false;
  }
  return true;
}

// Function to print Fizz, Buzz, FizzBuzz, and Prime
function fizzBuzzPrime() {
  for (let i = 1; i <= 100; i++) {
      let output = '';

      // Check if the number is prime
      if (isPrime(i)) {
          output += 'Prime ';
      }

      // Check for multiples of 3, 5, or both
      if (i % 3 === 0 && i % 5 === 0) {
          output += 'FizzBuzz';
      } else if (i % 3 === 0) {
          output += 'Fizz';
      } else if (i % 5 === 0) {
          output += 'Buzz';
      }

      // If none of the above, just print the number only
      if (output === '') {
          output = i;
      }

      console.log(output);
  }
}

// Call the function to run the program
fizzBuzzPrime();
