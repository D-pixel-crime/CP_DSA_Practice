#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int mod = 998244353;

ll power_mod(ll base, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
        {
            n--;
            ans = (ans * base) % mod;
        }
        else
        {
            base = (base * base) % mod;
            n /= 2;
        }
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> p(n);
    vector<ll> q(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }

    ll a = 0, b = a;
    cout << (power_mod(2LL, p[0]) + power_mod(2LL, q[0])) % mod << " ";
    for (int i = 1; i < n; i++)
    {
        if (p[i] > p[a])
        {
            a = i;
        }
        if (q[i] > q[b])
        {
            b = i;
        }
        if (p[a] > q[b])
        {
            cout << (power_mod(2LL, p[a]) + power_mod(2LL, q[i - a])) % mod << " ";
        }
        else if (q[b] > p[a])
        {
            cout << (power_mod(2LL, q[b]) + power_mod(2LL, p[i - b])) % mod << " ";
        }
        else
        {
            if (q[i - a] > p[i - b])
            {
                cout << (power_mod(2LL, p[a]) + power_mod(2LL, q[i - a])) % mod << " ";
            }
            else
            {
                cout << (power_mod(2LL, q[b]) + power_mod(2LL, p[i - b])) % mod << " ";
            }
        }
    }

    cout << endl;
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