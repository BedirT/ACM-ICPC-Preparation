// https://www.spoj.com/problems/INVCNT/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// we solve this via divide and conquer
// divide: 
// split into left and right subarrays
// find the # of inversions in left subarray
// find the # of inversions in right subarray

// combine:
// then find the # of inversions between left and right subarray 
// when we insert value from right, how many values in left are remaining? 
// that is # of inversions for one element of right

long long countInversions(vector<int>& arr)
{
    if(arr.size() == 1)
        return 0;
    vector<int> left;
    vector<int> right;
    for(int i = 0; i < arr.size()/2; ++i)
    {
        left.push_back(arr[i]);
    }
    for(int i = arr.size()/2; i < arr.size(); ++i)
    {
        right.push_back(arr[i]);
    }
    long long res = 0;
    res += countInversions(left);
    res += countInversions(right);
    int l = 0;
    int r = 0;
    int reml = left.size();
    for(int i = 0; i < arr.size(); i++)
    {
        if(l == left.size())
        {
            arr[i] = right[r];
            r++;
            continue;
        }
        if(r == right.size())
        {
            arr[i] = left[l];
            l++;
            continue;
        }
        if(left[l] > right[r])
        {
            arr[i] = right[r];
            r++;
            res += reml;
        }
        else
        {
            arr[i] = left[l];
            l++;
            reml--;
        }
    }
    return res;
}

void solve()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << countInversions(arr) << '\n';
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}