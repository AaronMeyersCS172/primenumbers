//////////////////////////////////////////////////////
// Aaron Meyers
// 4/27/16
// Homework 9: Display First 50 Prime Numbers
///////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	// Establishs the variables that will be used in the program
	const int ArraySize = 50;
	int PrimeNum[ArraySize]; // This array will hold only 50 numbers
	const int Prime = 50;
	const int LineLimit = 10; // Limits the number of outputs per line
	const int OutputSpace = 5; // Creates a space between outputs 
	int Primecount = 0;
	int i = 0;
	int number = 2; // This will be the variable that will be tested for "Primeness" and will increment upwards by 1 as the program runs 
					//(It is "2" because "2" is the first offical prime number)

	// This is introductory text
	cout << "The first 50 prime numbers are " << endl;

	// This loop will continue until only the first 50 prime numbers have been saved in the 50 spaces that are available in the array
	while (Primecount < ArraySize)
	{
		bool isPrime = true; // Thismeans that the number is not a prime number and requires it to be tested

		int PrimeCheck = sqrt(number); //This makes "PrimeCheck" equal to one so that the following loop will only execute once

		// This loop will help to check to see if the current number is evenly divisible by any past prime numbers
		for (int i = 0; i < Primecount; i++)
		{
			// This will automatically execute because "i" will always be less than "PrimeCheck"
			// This will test to see if the current number is evenly divisible by apast prime numbers
			if (PrimeNum[i] <= PrimeCheck)
			{
				if (number % PrimeNum[i] == 0) // This execute if the current number is evenly divisible by past prime numbers
				{
					isPrime = false; // This means that the number fulfills the condition that makes a number prime
					break; //This stops the loop if the number is proven to be prime
				}
			}
			else
			{
				break; // This stops the loop after the testing fails to prove that the current number is prime
			}
		}
		

		// This section is for saving the prime number to a spot in the array
		// This will also output the prime number and will also organize it into lines of 10 numbers
		if (isPrime)
		{
			PrimeNum[Primecount] = number; // Sva ethe prime number to the array
			Primecount++; // Increases the array value by one for the next prime number

			// This is for organizing the numbers into lines of a set size and distance from each other
			if (Primecount % LineLimit == 0) // This is for creating a new line afer every 10 numbers and outputs the prime number
			{
				cout << setw(OutputSpace) << number << endl;
			}
			else // This is for outputing the prime numbers that are not at the end of the line 
			{
				cout << setw(OutputSpace) << number;
			}
		}

		number++; // This increases the variable by 1 so that the next number will be tested for "Primeness" 
	}

	return 0;
}
