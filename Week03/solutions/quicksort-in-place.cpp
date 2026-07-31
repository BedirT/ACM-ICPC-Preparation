// https://www.hackerrank.com/challenges/quicksort3/problem

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int main()
{
    // always pick last element in subarray as pivot
    // parition left then right
    // print out whole array at end of each partition
    // an array of length 1 or less will be considered sorted

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack<pair<int, int>> s;
    s.push({0, n - 1});

    // track number of items less than pivot
    // any time we find another item less than the pivot
    // swap that item with index at # less than pivot
    // then increment # less than pivot
    // at the end when we reach the pivot itself, swap with index at # less than pivot
    // then add right and left to stack

    // this does it iteratively rather than recursively, recursive soln has same idea though

    while(!s.empty())
    {
        auto [ l, r ] = s.top();
        s.pop();
        
        if(l >= r)
            continue;
        int pivot = arr[r];
        // handle size 2 arr
        if(r-l == 1)
        {
            if(arr[l] > pivot)
                swap(arr[l], arr[r]);
            for(int i = 0; i < n; i++)
            {
                cout << arr[i] << ' ';
            }
            cout << '\n';
            continue;
        }
        
        // track # less than pivot
        int ltPivot = 0;
        for(int i = l; i < r; i++)
        {
            if(arr[i] < pivot)
            {
                ltPivot++;
                if(i-l != ltPivot-1)
                    swap(arr[l + ltPivot-1], arr[i]);
            }
        }
        
        // swap pivot with first # greater than pivot
        swap(arr[l + ltPivot], arr[r]);

        // output array
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        // push right half, then left half (so left half is on top of stack)
        s.push({l + ltPivot + 1, r});
        s.push({l, l + ltPivot - 1});
    }
}