#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector> // STL
#include <bitset> // STL

using namespace std;

vector<int> primes;

void sieve(int size) {
	bitset<10000010> was;
	was.set();        
	was[0] = was[1] = 0;
	for (int i = 2; i <= size; i++) 
  		if (was[i]) {
  			primes.push_back(i);
	    		for (int j = i * i; j <= size; j += i) was[j] = 0;
  		}
}

vector<int> primeFactors(int N){
	vector<int> vc;
	// Comment line below for using other method (iterator)
	//
	int idx = 0, f = primes[idx]; // f standing for FACTOR - idx is index that we will increment 
	//
	// More advanced usage would be pointers :
	// vector<int>::iterator it = primes.begin(); int f = *it; ///// Uncomment for using iterator
	//
	while(N != 1 && N >= f * f){
		while(N % f == 0){
			N /= f;
			vc.push_back(f);
		}
		//
		// f = *(++it); ///// Uncomment for using iterator
		//
		f = primes[++idx]; // Comment this for using other method (iterator)
		//
	}
	if(N != 1) vc.push_back(N); // This case is for prime numbers or having factor greater than sqrt(N).
	return vc;
}

int main(){
	
	sieve(10000);
	int n = 18;
	// cin >> n;
	vector<int> pF = primeFactors(n);
	for(int i = 0; i < pF.size() ; ++i){
		cout << pF[i] << " " ;
	}
	cout << endl;
}
