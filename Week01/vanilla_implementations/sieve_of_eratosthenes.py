# Sieve of Eratosthenes implementation in Python
#
# Author: Bedir Tapkan
# Date:   04/11/2022

def sieve_of_eratosthenes(n):
    """
    Sieve of Eratosthenes implementation;
    Finding prime numbers from 2 to n (inclusive).
    """
    primes = [True] * (n + 1)
    primes[0] = False
    primes[1] = False
    results = [] # List to store the prime numbers
    for i in range(2, int(n ** 0.5) + 1):
        if primes[i]:
            results.append(i)
            for j in range(i * i, n + 1, i):
                primes[j] = False
    return results + [i for i in range(int(n ** 0.5) + 1, n + 1) if primes[i]]

def main():
    """
    Main function
    """
    n = int(input("n: "))
    primes = sieve_of_eratosthenes(n)
    print(primes)


if __name__ == "__main__":
    main()
