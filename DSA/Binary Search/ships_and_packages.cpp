// You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.
// The weights of the packages are given in an array 'of weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
// Find out the least-weight capacity so that you can ship all the packages within 'd' days.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

bool isPossible(vector<ll> &arr, ll &mid, ll &d)
{
    ll curr = 0, days = 1;
    for (auto i : arr)
    {
        if (curr + i <= mid)
        {
            curr += i;
        }
        else
        {
            days++;
            if(i > mid)return false;
            else curr = i;
        }
    }

    return days <= d;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll d;
    cin >> d;
    ll start = 0, end = accumulate(arr.begin(), arr.end(), 0ll) + 1, temp = end;
    while (start + 1 < end)
    {
        ll mid = start + (end - start) / 2;
        if (isPossible(arr, mid, d))
            end = mid;
        else
            start = mid;
    }

    if (end != temp)
        cout << end << endl;
    else
        cout << -1 << endl;
}