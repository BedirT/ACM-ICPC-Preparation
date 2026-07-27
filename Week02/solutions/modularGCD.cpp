// https://www.codechef.com/AUG18B/problems/GCDMOD

#include <iostream>
#include <numeric>
using namespace std;

// gcd of a^n + b^n and a - b (a always >= b, so no need for absolute value)
// let diff = a - b

// because we have a % diff = b % diff
// we also have a^n % diff = b^n % diff
// thus we have (a^n + b^n) mod diff = 2*(b^n) mod diff

// thus our result is gcd(2*b^n mod diff, diff)
// find 2*b^n mod diff through modular exponentiation

// returns (a*b)%m w/ binary multiplication to prevent overflow
long long mulmod(long long a, long long b, long long m)
{
    long long res = 0;
    a %= m;
    b %= m;
    while(b > 0)
    {
        if(b & 1)
        {
            res += a;
            res %= m;
        }
        a *= 2;
        a %= m;
        b = b >> 1;
    }
    return res;
}

// returns (base^exp)%m using binary exponentiation to prevent overflow
long long modpow(long long base, long long exp, long long m)
{
    long long res = 1;
    base %= m;
    while (exp > 0)
    {
        if (exp & 1) res = mulmod(res, base, m);
        base = mulmod(base, base, m);
        exp >>= 1;
    }
    return res;
}

void solve()
{
    long long a, b, n; cin >> a >> b >> n;
    long long diff = a-b;

    const long long MOD = 1e9 + 7;
    // handle a = b edge case, simply calculate a^n + b^n mod 1e9 + 7 because gcd(a^n + b^n, 0) = a^n + b^n
    if(diff == 0)
    {
        long long resA = modpow(a, n, MOD);
        long long resB = modpow(b, n, MOD);
        cout << (resA + resB) % MOD << '\n';
        return;
    }

    // calculate 2*b^n mod diff
    long long res = 2 * modpow(b, n, diff) % diff;
    cout << gcd(res, diff) % MOD << '\n';
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}