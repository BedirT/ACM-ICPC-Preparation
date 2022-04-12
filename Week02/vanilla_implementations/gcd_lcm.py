# Vanilla implementation of gcd and lcm
#
# Author: Bedir Tapkan
# Date:   04/12/2022

def gcd(a, b):
    """
    Euclidean algorithm implementation
    """
    while b:
        a, b = b, a % b
    return a


def lcm(a, b):
    """
    Least common multiple implementation
    """
    return a * b // gcd(a, b)


def example():
    """
    Example
    """
    print(gcd(12, 8)) # 4
    print(lcm(12, 8)) # 24


if __name__ == "__main__":
    example()
