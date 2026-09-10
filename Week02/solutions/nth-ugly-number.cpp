// https://leetcode.com/problems/ugly-number-iii/description/

#include <iostream>
using namespace std;

long long gcd (long long a, long long b)
{
    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm (long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int solve(int n, int a, int b, int c)
{
    long long la = a;
    long long lb = b;
    long long lc = c;

    long long lab = lcm(la, lb);
    long long lbc = lcm(lb, lc);
    long long lac = lcm(la, lc);

    long long labc = lcm(lab, lc);

    // run bin search on val of n
    int l = 0;
    int r = 2e9 + 1;
    // if mid has n leq then r = mid
    // else l = mid + 1
    while(l < r)
    {
        long long mid = l + (r - l)/2;
        long long num = mid/a + mid/b + mid/c - mid/lab - mid/lac - mid/lbc + mid/labc;
        if(num >= n)
            r = mid;
        else
            l = mid+1;
    }
    return l;
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << solve(n, a, b, c);
}
