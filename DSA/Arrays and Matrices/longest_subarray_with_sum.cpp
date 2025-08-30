// Find the longest subarray with the given sum

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

int longest_subarray_with_given_sum(vector<ll> &arr, ll sum)
{
    int n = arr.size();
    unordered_map<ll, int> isPresent;
    ll temp = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        temp += arr[i];
        if (temp == sum)
        {
            ans = max(ans, i + 1);
        }
        else if (isPresent.find(temp - sum) != isPresent.end())
        {
            ans = max(ans, i - isPresent[temp - sum]);
        }
        if (isPresent.find(temp) == isPresent.end())
            isPresent[temp] = i;
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

    cout << longest_subarray_with_given_sum(arr, sum) << endl;
}