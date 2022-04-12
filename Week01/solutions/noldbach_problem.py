# https://codeforces.com/problemset/problem/17/A
#
# Author: Bedir Tapkan
 
def sieveE(n):
    primes = [True] * (n + 1)
    primes[0] = False
    primes[1] = False
    prime_nums = []
    for i in range(2, int(n ** 0.5) + 1):
        if primes[i]:
            prime_nums.append(i)
            for j in range(i * i, n + 1 ,i):
                primes[j] = False
    return prime_nums + [i for i in range(int(n**0.5)+1, n+1)
                         if primes[i]], primes
           # Prime integers, Truth values in a table


def noldbach():
    primes, primes_table = sieveE(3500) # 1000+ primes
    n, k = map(int, input().split())
    res = 0
    for i in range(len(primes)-1):
        num_check = primes[i] + primes[i+1] + 1
        if num_check > n:
            break
        if primes_table[num_check]:
            res += 1
    if res >= k:
        print("YES")
    else:
        print("NO")


if __name__=="__main__":
    noldbach()
