// https://www.codechef.com/problems/MRGSRT

#include <iostream>
using namespace std;

void solve()
{
    int s, t, i; cin >> s >> t >> i;
    if(s > i || t < i)
    {
        cout << "-1\n";
        return;
    }
    int cnt = 1;
    while(s != i || t != i)
    {
        cout << s << ' ' << t << '\n';
        // there are (t - s + 1) elements
        // first half contains floor (t - s + 2)/2 elements, or has upper bound index of (t-s)/2
        // second half contains floor (t - s + 1)/2 elements
        int mid = s + (t - s)/2;
        if(i <= mid)
            t = mid;
        else
            s = mid + 1;
        cnt++;
    }
    cout << i << ' ' << i << '\n';
    cout << cnt << '\n';
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}
