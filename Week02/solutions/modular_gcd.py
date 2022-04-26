# https://www.codechef.com/AUG18B/problems/GCDMOD
#
# Author: Bedir Tapkan

mod_val = 10**9 + 7

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def modexp(a, b, x):
    a %= x
    result = 1
    while b > 0:
        if b & 1:
            result = (result * a) % x
        a = a ** 2 % x
        b >>= 1
    return result

def solve(a, b, n):
    delta = a - b
    if delta == 0:
        return (modexp(a, n, mod_val) + modexp(b, n, mod_val)) % mod_val
    else:
        value = modexp(a, n, delta) + modexp(b, n, delta)
        value %= delta
        return gcd(delta, value) % mod_val

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        a, b, n = map(int, input().split(" "))
        print(solve(a,b,n))
