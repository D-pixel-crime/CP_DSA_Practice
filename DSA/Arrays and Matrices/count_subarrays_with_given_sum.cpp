// Count subarrays with given sum

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

int count_subarrays_with_given_sum(vector<ll> &arr, ll sum)
{
    unordered_map<ll, int> isPresent;
    ll curr = 0;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        curr += arr[i];
        if (curr == sum)
        {
            ans++;
        }
        else if (isPresent.find(curr - sum) != isPresent.end())
        {
            ans += isPresent[curr - sum];
        }

        isPresent[curr]++;
    }

    return ans;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll sum;
    cin >> sum;

    cout << count_subarrays_with_given_sum(arr, sum) << endl;
}