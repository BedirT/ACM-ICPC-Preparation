// Sieve of Eratosthenes
// 
// Author: Bedir Tapkan
//
// Desc: Find the prime numbers from 1 - n

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void sieve(long n, bool * composite, vector<int> &primes){
    // n -> the max number to check for primes
    // composite -> bool arr to mark composite nums
    // primes -> vector that contains primes from 2 -> n

	// O(n*sqrt(n)) - but much faster in practice
	for (long i = 2; i <= n; ++i){ 	
	    // Check 2->n if they are already marked as composite
        // and mark composites along the way
		if (!composite[i]){
			// Checking if prime
			primes.push_back(i);
			for (long j = i*i; j <= n; j += i){
				composite[j] = true;
			}
		}
	}
}
void printVector(vector<int> vc) {
	for (int i = 0; i < vc.size(); ++i)
		cout << vc[i] << " ";
	cout << endl << endl;
}

int main() {
	long n;
	cin >> n; // number to check for primes up to

	bool composite[n+1];
	memset(composite, false, sizeof composite);
	vector<int> primes;

	sieve(n, composite, primes);
	printVector(primes);
}

