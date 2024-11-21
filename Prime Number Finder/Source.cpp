/*
	Imane Jourji
	Computer Science Fall 2024
	Due : Wednsday November 20, 2024 11:59pm
	Coding Challenge Prime Number Finder
	This challenge is a C++ program to print all prime numbers up to a limit = 1000000
*/


#include<iostream>
#include <chrono>                           //for measuring time taken to complete the task
#include <vector>                           //for using vector

using namespace std;


void findPrimes(int limit) {                //function to find prime numbers up to a limit
    
    
    chrono::time_point<chrono::system_clock> start;
    chrono::time_point<chrono::system_clock> end;
    chrono::duration<float> elapsed;

    start = chrono::system_clock::now();    // Start the timer

	vector<bool> isPrime(limit + 1, true);  // Create a vector of booleans to store whether each number is prime or not
	                                        //initialize all numbers as prime
	isPrime[0] = isPrime[1] = false;        // Mark 0 and 1 as not prime
   
	// Sieve of Eratosthenes algorithm to find prime numbers
    for (int i = 2; i * i <= limit; ++i) {   
		if (isPrime[i]) {                   // If i is prime, then none of its multiples will be prime
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

	end = chrono::system_clock::now();      // Stop the timer
	elapsed = end - start;                  // Calculate the time taken to complete the task

    
    cout << "Time to complete task: " << elapsed.count() << " seconds" << endl;

                                            // Print the primes
    cout << "Prime numbers up to " << limit << ":" << endl;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    
    int limit = 1000000;                 
    findPrimes(limit);                     // Call the function to find primes
    return 0;
}