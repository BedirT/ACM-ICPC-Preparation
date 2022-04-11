# https://www.spoj.com/problems/AMR11E/
#
# Author: Bedir Tapkan

def sieve_of_eratosthenes_modified(n):
    """
    Sieve of Eratosthenes implementation
    with a tweak:
        Instead of true-false calculate the number
        of prime numbers to generate the composites.
    """
    primes = [0] * (n + 1)
    primes[0] = -1
    primes[1] = -1
    for i in range(2, n + 1):
        if not primes[i]: # 0 for prime
            for j in range(i + i, n + 1, i):
                primes[j] += 1
    return [i for i in range(2, n + 1) if primes[i] >= 3]


def solution():
    res = sieve_of_eratosthenes_modified(2700)
    T = int(input())
    for t in range(T):
        n = int(input())
        print(res[n-1])
        

if __name__ == "__main__":
    solution()