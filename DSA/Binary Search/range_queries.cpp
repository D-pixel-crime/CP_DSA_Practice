// You are given an array of n
//  integers and q
//  queries. In each query, you are given 2
//  integers l
//  and r
// . You need to report the number of array elements having value between l
//  and r
// .

// INPUT
// The first line contains 2
//  integers n,q(1≤n,q≤105)
// .
// The next line contains n
//  separated integers a1,a2,...,an(−109≤ai≤109)
//  - the given array.
// Each of the next q
//  lines contain 2
//  space separated integers - li,ri(−109≤li≤ri≤109)
// .

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

int find_index(vector<ll> &arr, ll &x)
{
    int start = -1, end = arr.size();
    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= x)
            start = mid;
        else
            end = mid;
    }

    return (start != -1 && arr[start] == x) ? start : start + 1;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        int i = find_index(arr, a);
        int j = find_index(arr, b);
        if (i != -1 && j != -1)
        {
            cout << j - i + 1 << " ";
        }
        else if (i == -1)
        {
            cout << j + 1 << " ";
        }
        else if (j == -1)
        {
            cout << n - i << " ";
        }
    }
}