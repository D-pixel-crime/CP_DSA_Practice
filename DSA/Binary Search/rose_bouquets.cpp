// You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
// You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
// Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

ll possible(vector<ll> &arr, ll &mid, ll &k, ll &m)
{
    ll count = 0, bouquets = 0;
    for (auto i : arr)
    {
        if (i <= mid)
        {
            count++;
        }
        else
        {
            bouquets += (count / k);
            count = 0;
        }
    }

    bouquets += (count / k);
    return bouquets >= m;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll k, m;
    cin >> k >> m;
    if (k * m > n)
    {
        cout << -1 << endl;
        return 0;
    }

    sort(arr.begin(), arr.end());

    ll start = *min_element(arr.begin(), arr.end()) - 1;
    ll temp = *max_element(arr.begin(), arr.end()), end = temp + 1;

    while (start + 1 < end)
    {
        ll mid = start + (end - start) / 2;
        if (possible(arr, mid, k, m))
            end = mid;
        else
            start = mid;
    }

    if (end != temp + 1)
        cout << end << endl;
    else
        cout << -1 << endl;
}