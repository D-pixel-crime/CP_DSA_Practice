// Given an integer array ‘A’ of size ‘N’ and an integer ‘K'.
// Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized.
// Your task is to return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long

bool isPossible(vector<ll> &arr, ll &mid, int &k)
{
    ll curr = 0, count = 1;
    for (auto i : arr)
    {
        if (curr + i <= mid)
            curr += i;
        else
        {
            curr = i;
            count++;
        }
    }

    return count <= k;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;

    if (k > n)
    {
        cout << -1 << endl;
        return 0;
    }

    ll start = *max_element(arr.begin(), arr.end()) - 1, end = accumulate(arr.begin(), arr.end(), 0LL) + 1, temp = end;
    while (start + 1 < end)
    {
        ll mid = start + (end - start) / 2;
        if (isPossible(arr, mid, k))
            end = mid;
        else
            start = mid;
    }

    if (end == temp)
        cout << -1 << endl;
    else
        cout << end << endl;

    return 0;
}