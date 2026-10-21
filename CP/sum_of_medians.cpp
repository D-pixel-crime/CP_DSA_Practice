#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n * k);
    for (ll i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    ll ans = 0;
    ll needed;
    if (n & 1)
    {
        needed = (ll)ceil(n / 2.0);
    }
    else
    {
        needed = (ll)(n / 2) + 1;
    }

    for (ll i = arr.size() - needed; i >= 0 && k; i -= needed, k--)
    {
        ans += arr[i];
    }

    cout << ans << endl;
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