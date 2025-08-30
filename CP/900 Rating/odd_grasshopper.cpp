#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    ll x, n;
    cin >> x >> n;

    ll res = n % 4;

    if (!(x & 1))
    {
        if (res == 1)
        {
            cout << x - n << endl;
            return;
        }
        if (res == 2)
        {
            cout << x + 1 << endl;
            return;
        }
        if (res == 3)
        {
            cout << x + n + 1 << endl;
            return;
        }

        cout << x << endl;
    }
    else
    {
        if (res == 1)
        {
            cout << x + n << endl;
            return;
        }
        if (res == 2)
        {
            cout << x - 1 << endl;
            return;
        }
        if (res == 3)
        {
            cout << x - n - 1 << endl;
            return;
        }

        cout << x << endl;
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