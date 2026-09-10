// https://leetcode.com/problems/nth-magical-number/

#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
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

int solve (int n, int a, int b)
{
    const int MOD = 1e9 + 7;
    long long lcmAB = lcm(a, b);
    long long da = lcmAB/a;
    long long db = lcmAB/b;
    long long d = da+db-1;
    
    long long x = n/d;
    long long y = n%d;

    lcmAB %= MOD;
    long long res = (lcmAB * x) % MOD;
    // find the yth smallest # as x and y
    if(y == 0)
        return res;
    if(y == 1)
        return (res + min(a, b))%MOD;
    long long t1 = 0, t2 = 0;
    vector<long long> ln;
    for(int i = 0; i < y; i++)
    {
        t1 += a;
        t2 += b;
        ln.push_back(t1);
        ln.push_back(t2);
    }
    sort(ln.begin(), ln.end());
    y--;
    res += (ln[y]) % MOD;
    res %= MOD;
    return res;
}

int main ()
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << solve(n, a, b);
}
