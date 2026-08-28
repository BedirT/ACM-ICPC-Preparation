// https://www.spoj.com/problems/AGGRCOW/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// overall idea of this problem is that validation is trivial in linear time
// i.e. given k, can we place all cows >= k distance apart?
// thus we can simply binary search for this value k
// low is 1, right is ceiling((furthest right - furthest left)/c)
// then bin search, if we can place all cows >= mid then left = mid
// else right = mid - 1

void solve ()
{
    int n, c; cin >> n >> c;
    vector<int> stalls(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> stalls[i];
    }
    sort(stalls.begin(), stalls.end());

    // run binsearch on stalls

    int l = 1, r = (stalls[n - 1] - stalls[0] + c)/c;

    while(l < r)
    {
        int mid = l + (r - l + 1)/2;

        // validation step
        int cnt = 1;
        int prev = stalls[0];
        for(int i = 1; i < n; ++i)
        {
            if(stalls[i] - prev >= mid)
            {
                prev = stalls[i];
                cnt++;
            }

            // break if validated
            if(cnt >= c)
                break;
        }
    
        if(cnt >= c)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
}

int main ()
{
    int t; cin >> t;
    while(t--) solve();
}