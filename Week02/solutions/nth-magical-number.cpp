// https://leetcode.com/problems/nth-magical-number/

#include <bits/stdc++.h>
using namespace std;

int solve (int n, int a, int b)
{
    const int MOD = 1e9 + 7;
    // fast find lcm of a, b
    long long t1 = a;
    long long t2 = b;
    while(t1 != t2)
    {
        if(t1 > t2)
            t2 += b;
        else
            t1 += a;
    }
    long long d1 = t1/a;
    long long d2 = t2/b;
    long long d = d1+d2-1;
    
    long long x = n/d;
    long long y = n%d;

    t1 %= MOD;
    long long res = (t1 * x) % MOD;
    // find the yth smallest # as x and y
    if(y == 0)
        return res;
    if(y == 1)
        return (res + min(a, b))%MOD;
    t1 = 0;
    t2 = 0;
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
