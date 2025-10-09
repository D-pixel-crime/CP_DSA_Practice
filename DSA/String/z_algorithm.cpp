/*
For string 's', find z-values vector, where
z(k) = longest substring starting at index 'k' which is also a prefix
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int mod = 1000000007;
unordered_map<int, int> factVals;

int countBits(int x)
{
    return __builtin_popcount(x);
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

int binaryExponentiation(int x, int n, int m = 1)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = (ans * x) % m;
            n--;
        }
        else
        {
            x = (x * x) % m;
            n >>= 1;
        }
    }

    return ans;
}

int extendedEuclidean(int a, int m, int &x, int &y)
{
    if (m == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedEuclidean(m, a % m, x1, y1);
    x = y1;
    y = x1 - (a / m) * y1;
    return gcd;
}

int modularInverse(int a, int m)
{
    int x, y;
    int gcd = extendedEuclidean(a, m, x, y);
    if (gcd != 1)
        return -1;
    return (x % m + m) % m;
}

int fact(int n)
{
    if (n <= 1)
        return 1;
    if (factVals.count(n))
        return factVals[n];
    int ans = 1, i = n;
    while (i >= 2)
    {
        if (factVals.count(i))
        {
            return factVals[n] = (1LL * ans * factVals[i]) % mod;
        }
        else
        {
            ans = (1LL * ans * i) % mod;
            i--;
        }
    }
    return factVals[n] = ans;
}

int nCx(int n, int x)
{
    int num = fact(n);
    int denom = (1LL * fact(x) * fact(n - x)) % mod;
    return (1LL * num * modularInverse(denom, mod)) % mod;
}

vector<int> calculateZValues(string &s)
{
    int n = s.size();
    vector<int> z(n, 0);

    pair<int, int> lastBracket;
    for (int i = 1; i < n; i++)
    {
        auto [l, r] = lastBracket;
        if (i <= r)
        {
            if (z[i - l] + i <= r)
            {
                z[i] = z[i - l];
            }
            else
            {
                int a = min(z[i - l], r - i + 1);
                int b = r + 1;
                while (b < n && s[a] == s[b])
                {
                    a++, b++;
                }

                int len = b - i;
                z[i] = len;
                lastBracket = {i, b - 1};
            }
        }
        else
        {
            int a = 0, b = i;
            while (b < n && s[a] == s[b])
            {
                a++, b++;
            }

            int len = b - i;
            lastBracket = {i, b - 1};
            z[i] = len;
        }
    }

    return z;
}

void solve()
{
    string s;
    cin >> s;

    vector<int> ans = calculateZValues(s);
    for (auto &i : ans)
    {
        cout << i << " ";
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