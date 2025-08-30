#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    int mini = INT_MAX, maxi = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i >= 1)
            ans = max(ans, arr[i - 1] - arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
            mini = min(mini, arr[i]);
        if (i >= 1)
            maxi = max(maxi, arr[i]);
    }

    cout << max({ans, arr[n - 1] - mini, maxi - arr[0], 0}) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}