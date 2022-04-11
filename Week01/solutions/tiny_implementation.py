# https://wiki.haskell.org/99_questions/Solutions/39
# Finding prime numbers in a range. (Using Sieve of Eratosthenes)
#
# Author: Bedir Tapkan

def sieve_of_eratosthenes(n):
    """
    Sieve of Eratosthenes implementation
    """
    primes = [True] * (n + 1)
    primes[0] = False
    primes[1] = False
    results = []
    for i in range(2, int(n ** 0.5) + 1):
        if primes[i]:
            # i is prime
            results.append(i)
            for j in range(i * i, n + 1, i):
                primes[j] = False
    return results + [i for i in range(int(n ** 0.5) + 1, n + 1) if primes[i]]


def solution():
    """
    Given a start and an end point,
    Prints the prime numbers in between.
    """
    _start = int(input("Start: "))
    _end = int(input("End: "))
    res = sieve_of_eratosthenes(_end)
    for i, x in enumerate(res):
        if x >= _start:
            start_idx = i
            break
    print(res[start_idx:])


if __name__ == "__main__":
    solution()

