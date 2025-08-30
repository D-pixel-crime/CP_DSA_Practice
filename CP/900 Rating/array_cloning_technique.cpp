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
    vector<ll> arr(n);
    int maxDup = 0;
    unordered_map<ll, int> count;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        count[arr[i]]++;
    }

    for (auto &i : count)
    {
        maxDup = max(maxDup, i.second);
    }

    if (maxDup == n)
    {
        cout << 0 << endl;
        return;
    }

    int ans = 0;

    while (maxDup < n)
    {
        ans++;
        int req = min(maxDup, n - maxDup);
        ans += req;
        maxDup += req;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}