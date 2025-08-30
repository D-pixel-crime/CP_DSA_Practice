// You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'.
// Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given threshold value.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

bool isPossible(vector<ll> &arr, ll &mid, ll &limit)
{
    ll ans = 0;
    for (auto curr : arr)
    {
        if(curr % mid == 0){
            ans += (curr / mid);
        }
        else ans += ((curr / mid) + 1);
    }

    return ans <= limit;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll limit;
    cin >> limit;
    ll start = 0, end = *max_element(arr.begin(), arr.end()) + 1, temp = end;
    while (start + 1 < end)
    {
        ll mid = start + (end - start) / 2;
        if (isPossible(arr, mid, limit))
            end = mid;
        else
            start = mid;
    }

    if (end != temp)
        cout << end << endl;
    else
        cout << -1 << endl;
}