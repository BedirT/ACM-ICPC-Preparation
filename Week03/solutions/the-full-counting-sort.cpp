// https://www.hackerrank.com/challenges/countingsort4/problem

#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main ()
{
    int n; cin >> n;
    vector<pair<int, string>> arr(n);
    vector<int> cnt(100, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
        cnt[arr[i].first]++;
    }

    // set first half of inputs strings to -
    for(int i = 0; i < n/2; ++i)
    {
        arr[i].second = '-';
    }

    // change cnt from # of occurences per # to prefix sum
    for(int i = 0; i < 99; ++i)
    {
        cnt[i+1] += cnt[i];
    }

    // perform counting sort
    // logic wise, for arr[i].first, if there are n elements
    // with index j s.t. arr[j].first < arr[i].first 
    // || (arr[i].first == arr[j].first && j <= i)
    // then it is processed and placed at the n-1 index (0 indexed)
    // because cnt[arr[i].first] = n at the time of processing
    // thus sorted and preserves order of values

    vector<pair<int, string>> res(n);
    for(int i = n - 1; i >= 0; --i)
    {
        res[cnt[arr[i].first] - 1] = arr[i];
        cnt[arr[i].first]--;
    }

    for(int i = 0; i < n; ++i)
    {
        cout << res[i].second << ' ';
    }
}