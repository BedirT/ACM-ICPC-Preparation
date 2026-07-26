// https://www.hackerrank.com/challenges/power-of-large-numbers/problem
#include <iostream>
#include <string>
using namespace std;

// key things to note:
// we can take x mod 1e9 + 7, won't affect result at all
// because 1e9 + 7 is prime, fermat's little theorem applies
// fermat's little theorem states that for a % p != 0, (a ^ p) % p = a
// thus (a ^ (p - 1)) % p = 1
// thus we can take y mod 1e9 + 6
// then we can take x mod 1e9 + 7 and y mod 1e9 + 6 and perform modular exponentiation
 
void solve()
{
    string x, y;
    long long res = 1;
    cin >> x >> y;
    const long long MOD = 1e9 + 7;

    // convert string x into long long xmod = x % MOD;
    long long xmod = 0;
    for(int i = 0; i < x.size(); ++i)
    {
        xmod *= 10;
        xmod %= MOD;
        xmod += x[i]-'0';
        xmod %= MOD;
    }

    // convert y into long long ymod = y % (MOD - 1)
    long long ymod = 0;
    for(int i = 0; i < y.size(); ++i)
    {
        ymod *= 10;
        ymod %= (MOD - 1);
        ymod += y[i] - '0';
        ymod %= (MOD - 1);
    }

    // perform modular exponentiation
    while(ymod > 0)
    {
        if(ymod%2 == 1)
            res = (res * xmod) % MOD;
         
        ymod /= 2;
        xmod = (xmod * xmod) % MOD;
    }

    cout << res << '\n';
}

int main()
{
    int n; cin >> n;
    while(n--) solve();
}