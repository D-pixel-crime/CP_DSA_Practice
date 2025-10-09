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

ll binExp(ll x, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = ans * x;
            n--;
        }
        else
        {
            x = x * x;
            n >>= 1;
        }
    }

    return ans;
}

void solve()
{
    ll n;
    cin >> n;

    ll cost = 0;
    while (n)
    {
        ll x = (ll)log(n) / (ll)log(3);
        n -= x;
        cost += (binExp(3LL, x + 1) + (x * binExp(3LL, x - 1)));
    }

    cout << cost << endl;
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