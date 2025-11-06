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

    vector<ll> pre(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
        if (i > 0)
        {
            pre[i] += pre[i - 1];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, __gcd(pre[i], pre[n - 1] - pre[i]));
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