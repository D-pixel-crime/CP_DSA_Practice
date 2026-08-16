#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

const int mod = 1000000007;
unordered_map<int, int> factVals;

int countBits(int x)
{
    return floor(log2(x)) + 1;
}

vector<bool> simpleSieve(int &n)
{
    vector<bool> arr(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = false;
            }
        }
    }
    return arr;
}

ll binaryExponentiation(ll x, ll n, ll m = 1)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}

ll extendedEuclidean(ll a, ll m, ll &x, ll &y)
{
    if (m == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extendedEuclidean(m, a % m, x1, y1);
    x = y1;
    y = x1 - (a / m) * y1;
    return gcd;
}

ll modularInverse(ll a, ll m)
{
    ll x, y;
    ll gcd = extendedEuclidean(a, m, x, y);
    if (gcd != 1)
        return -1;
    return (x % m + m) % m;
}

ll fact(ll n)
{
    if (n <= 1)
        return 1;
    if (factVals.count(n))
        return factVals[n];
    ll ans = 1, i = n;
    while (i >= 2)
    {
        if (factVals.count(i))
            return factVals[n] = (1LL * ans * factVals[i]) % mod;
        else
        {
            ans = (1LL * ans * i) % mod;
            i--;
        }
    }
    return factVals[n] = ans;
}

ll nCx(ll n, ll x)
{
    ll num = fact(n);
    ll denom = (1LL * fact(x) * fact(n - x)) % mod;
    return (1LL * num * modularInverse(denom, mod)) % mod;
}

void solve()
{
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