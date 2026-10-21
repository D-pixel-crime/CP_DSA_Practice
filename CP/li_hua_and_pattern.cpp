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
    ll k;
    cin >> k;

    vector<vector<ll>> arr(n, vector<ll>(n));
    vector<vector<ll>> sec(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            sec[n - i - 1][n - j - 1] = arr[i][j];
        }
    }

    ll needed = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != sec[i][j])
            {
                needed++;
            }
        }
    }

    needed /= 2;

    if (needed > k)
    {
        cout << "NO\n";
    }
    else
    {
        k -= needed;
        if (n & 1)
        {
            cout << "YES\n";
        }
        else if (k & 1)
        {
            cout << "NO\n";
        }
        else
            cout << "YES\n";
    }
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