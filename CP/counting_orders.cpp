#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

ll mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(all(a));
    sort(all(b));

    int i = 0, j = 0;
    ll ans = 1;
    while (i < n && j < n)
    {
        if (a[i] <= b[j])
        {
            i++;
        }
        else
        {
            ll available = n - i - (n - 1 - j);
            if (available <= 0)
            {
                cout << 0 << endl;
                return;
            }
            ans = (ans * available) % mod;
            j++;
        }
    }

    if (j < n)
    {
        cout << 0 << endl;
    }
    else
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