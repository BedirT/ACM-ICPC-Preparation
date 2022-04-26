# https://www.hackerrank.com/challenges/sherlock-and-gcd/problem
#
# Author: Bedir Tapkan

import math
import os
import random
import re
import sys

#
# Complete the 'solve' function below.
#
# The function is expected to return a STRING.
# The function accepts INTEGER_ARRAY a as parameter.
#

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a
        
def solve(a):
    # if all the gcd of all the elements is 1 return 'YES'
    # otherwise return 'NO'
    a = list(set(a))
    tot_gcd = a[0]
    for i in range(1, len(a)):
        tot_gcd = gcd(tot_gcd, a[i])
    if tot_gcd > 1:
        return 'NO'
    return 'YES'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        a_count = int(input().strip())

        a = list(map(int, input().rstrip().split()))

        result = solve(a)

        fptr.write(result + '\n')

    fptr.close()
