# https://codeforces.com/contest/664/problem/A
#
# Author: Bedir Tapkan

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a


def solve(a, b):
    cur_gcd = a
    for i in range(a+1, b+1):
        cur_gcd = gcd(i, cur_gcd)
        if cur_gcd == 1:
            return 1
    return cur_gcd


if __name__ == "__main__":
    a, b = map(int, input().split(" "))
    print(solve(a,b))