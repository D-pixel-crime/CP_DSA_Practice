// You are given an array 'arr' of size 'n' which denotes the position of stalls.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

bool is_possible(vector<ll> &arr, ll &mid, int k)
{
    ll total = 1, lastPos = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - lastPos >= mid)
        {
            total++;
            lastPos = arr[i];
        }
    }

    return total >= k;
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
    sort(arr.begin(), arr.end());

    ll start = 0, end = arr[n - 1] - arr[0] + 1;

    while (start + 1 < end)
    {
        ll mid = start + (end - start) / 2;
        if (is_possible(arr, mid, k))
            start = mid;
        else
            end = mid;
    }

    cout << start << endl;

    return 0;
}