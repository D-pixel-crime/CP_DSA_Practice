#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    ll a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (a > b)
    {
        swap(a, b);
    }
    if (b % a != 0)
    {
        cout << -1 << endl;
        return;
    }

    ll res = b / a;
    if (res == 8 || res == 4 || res == 2)
    {
        cout << 1 << endl;
        return;
    }
    if (res % 8 != 0 && res % 4 != 0 && res % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }

    ll ans = 0;
    while (a < b && res % 8 == 0)
    {
        ans++;
        a <<= 3;
        res = b / a;
    }
    if (a == b)
    {
        cout << ans << endl;
        return;
    }

    while (a < b && res % 4 == 0)
    {
        ans++;
        a <<= 2;
        res = b / a;
    }
    if (a == b)
    {
        cout << ans << endl;
        return;
    }

    while (a < b && res % 2 == 0)
    {
        ans++;
        a <<= 1;
        res = b / a;
    }

    cout << (a == b ? ans : -1) << endl;
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