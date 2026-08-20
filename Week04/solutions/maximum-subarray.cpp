// https://leetcode.com/problems/maximum-subarray/description/

// note that we COULD do kadane's, but because this is in the mergesort section
// i'm going to use divide and conquer for this problem (although sorting isn't involved)

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// split into left and right and find max subarray sum for both
// then to combine, find max subarray sum ending at rightmost index of left subarray
// and find max subarray sum starting at leftmost index of right subarray
// then add those 2 together
// then take the max of left, right, and combination of left + right

int findMaxSubarraySum(vector<int>& arr, int l, int r)
{
    if(l == r)
        return arr[l];

    int mid = (l + r)/2;
    int lSum = findMaxSubarraySum(arr, l, mid);
    int rSum = findMaxSubarraySum(arr, mid + 1, r);

    int midLSum = INT_MIN;
    int midRSum = INT_MIN;
    int currSum = 0;

    for(int i = mid; i >= l; --i)
    {
        currSum += arr[i];
        midLSum = max(midLSum, currSum);
    }

    currSum = 0;
    for(int i = mid + 1; i <= r; ++i)
    {
        currSum += arr[i];
        midRSum = max(midRSum, currSum);
    }

    int res = midLSum + midRSum;
    res = max(res, max(lSum, rSum));
    return res;
}

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << findMaxSubarraySum(arr, 0, n - 1);
}
