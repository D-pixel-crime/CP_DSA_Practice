#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int countBits(int x)
{
    return floor(log2(x)) + 1;
}

void solve()
{
    ll x, y;
    cin >> x >> y;

    ll ans;
    if (x > y)
    {
        if (x & 1)
        {
            ans = ((x - 1) * (x - 1)) + y;
        }
        else
        {
            ans = (x * x) - y + 1;
        }
    }
    else
    {
        if (!(y & 1))
        {
            ans = ((y - 1) * (y - 1)) + x;
        }
        else
        {
            ans = (y * y) - x + 1;
        }
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
