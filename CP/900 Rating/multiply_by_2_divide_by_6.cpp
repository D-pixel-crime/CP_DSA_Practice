#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    ll n;
    cin >> n;

    ll ans = 0;
    while (n != 1)
    {
        if (n % 6 == 0)
        {
            ans++;
            n /= 6;
        }
        else if (n % 3 == 0)
        {
            ans++;
            n *= 2;
        }
        else
        {
            cout << -1 << endl;
            return;
        }
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