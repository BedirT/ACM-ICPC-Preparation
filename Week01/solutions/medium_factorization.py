# https://www.spoj.com/problems/FACTCG2/
# This is a conceptual code snippet. It won't pass the test cases
# due to language limitations.
#
# Author: Bedir Tapkan

def sieveE(n):
    primes = [0] * (n + 1)
    primes[0] = 0
    primes[1] = 0

    for i in range(2, n + 1):
        if not primes[i]:
            for j in range(i * i, n + 1, i):
                if not primes[j]:
                    primes[j] = i # smallest prime factor
    return primes


def factorize(n, primes):
    """
    Return the prime factors of the num n
    as string including 1 ie. for n=4; 1 x 2 x 2
    """
    factors = ["1"]
    while primes[n] != 0 and n % primes[n] == 0: 
        # n is not prime and n is divisible by f
        factors.append(str(primes[n]))
        n = n // primes[n]
    if n != 1:        
        factors.append(str(n))
    return " x ".join(factors)


def solution():
    # Input is until there is no more input given
    # When reached EOF, break
    primes = sieveE(10001)
    while True:
        try:
            n = int(input())
            if n == 1:
                print("1")
            else:
                print(factorize(n, primes))
        except EOFError:
            break


if __name__ == "__main__":
    solution()