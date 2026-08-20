// https://www.spoj.com/problems/MERGSORT/

#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& arr)
{
    // sort left and right -> combine
    // base case is len = 1
    if(arr.size() == 1) return;
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
    mergeSort(left);
    mergeSort(right);
    int l = 0;
    int r = 0;
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
        }
        else
        {
            arr[i] = left[l];
            l++;
        }
    }
}

int main()
{
    // handle input
    vector<int> arr;
    int n;
    while(scanf("%i", &n) != EOF)
        arr.push_back(n);
        
    mergeSort(arr);
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
}