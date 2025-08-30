// A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

bool isPossible(vector<ll> &arr, ll &mid, ll &h)
{
    ll hours = 0;
    for (auto curr : arr)
    {
        ll temp = (curr % mid == 0) ? curr / mid : (curr / mid) + 1;
        if (hours <= h - temp)
            hours += temp;
        else
            return false;
    }
    return true;
}

void find_speed(vector<ll> &arr, ll &h)
{
    ll start = 0, end = *max_element(arr.begin(), arr.end());
    while (start + 1 < end)
    {
        ll mid = start + (end - start) / 2;
        if (isPossible(arr, mid, h))
            end = mid;
        else
            start = mid;
    }

    ll mid = start + (end - start) / 2;
    if (isPossible(arr, mid, h))
        cout << mid << endl;

    cout << end << endl;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll h;
    cin >> h;

    find_speed(arr, h);
}