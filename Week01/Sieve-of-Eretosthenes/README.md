<!--?title Sieve of Eratosthenes -->

# Sieve of Eratosthenes

Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment __[ 1 ; n ]__ using __O(n _log log_ n)__ operations.

The idea is simple: at the beginning we write down a row of numbers and eliminate all numbers divisible by 2, 
except number 2 itself,  then divisible by 3, except number 3 itself, next by 7, 11, 
and all the remaining prime numbers till **_n_**.

##Implementation

````cpp
int n;
vector<char> prime (n + 1, true);
prime[0] = prime[1] = false;
for (int i = 2; i * i <= n; ++i)
    if (prime[i])
        if (i * 1ll * i <= n)
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
````

This code firstly marks all numbers except zero and number one as prime numbers, then it begins the process of sifting composite numbers. 
For this purpose we go through all numbers __2__ to __n__ in a cycle, and if the current number __i__ is a prime number, 
then we mark all numbers that are multiple to it as composite numbers.
In doing so, we are starting from __i^2__ as all lesser numbers that are multiple to __i__ necessary have prime factor 
which is less than __i__, and that means that all of them were sifted earlier.
(Since __i^2__ can easily overflow the type __int__ the additional verification is done using type __long long__ before the second 
nested cycle).

Using such implementation the algorithm consumes __O(n)__ of the memory (obviously) and performs __O(n _log log_ n)__ 
(this is being proved in the next section).
