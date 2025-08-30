#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int findMax(vector<int> &arr, vector<int> &dp, int i)
{
    if (i >= arr.size())
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];

    int ans = 0;

    for (int j = i + 1; j < arr.size(); j++)
    {
        if (arr[j] % arr[i] == 0)
        {
            ans = max(ans, 1 + findMax(arr, dp, j));
        }
    }

    return dp[i] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll ans = LLONG_MIN;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<ll> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] % arr[j] == 0)
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}