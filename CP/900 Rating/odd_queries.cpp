#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    vector<ll> prefix(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prefix[i] = i == 0 ? arr[i] : prefix[i - 1] + arr[i];
    }

    while (q--)
    {
        int l, r;
        ll k;
        cin >> l >> r >> k;

        ll req = k * (r - l + 1);

        ll diff = req - (prefix[r - 1] - prefix[l - 1] + arr[l - 1]);

        cout << (((prefix[n - 1] + diff) & 1) ? "YES\n" : "NO\n");
    }
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