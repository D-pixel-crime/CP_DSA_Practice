#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int mod = 1000000007;
unordered_map<int, int> factVals;

int countSetBits(int x)
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

int binaryExponentiation(int x, int n, int m = mod)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = (1LL * ans * x) % m;
            n--;
        }
        else
        {
            x = (1LL * x * x) % m;
            n >>= 1;
        }
    }
    return ans;
}

int extendedEuclidean(int a, int m, int &x, int &y)
{
    if (m == 0)
    {
        x = 1;
        y = 0;
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
    pair<int, int> lastBracket = {0, 0};
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
                    a++;
                    b++;
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
                a++;
                b++;
            }
            int len = b - i;
            z[i] = len;
            lastBracket = {i, b - 1};
        }
    }
    return z;
}

vector<int> lpsArray(string &s)
{
    int n = s.size();
    vector<int> lps(n);
    int i = 1, len = 0;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int knuthMorrisPratt(string &s, string &p)
{
    vector<int> lps = lpsArray(p);
    lps.insert(lps.begin(), -1);
    p = " " + p;
    int i = 0, j = 0;
    while (i < s.size() && j < p.size() - 1)
    {
        if (s[i] == p[j + 1])
        {
            i++, j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j];
            }
            else
            {
                i++;
            }
        }
    }
    return j == p.size() - 1 ? i - j : -1;
}

void solve()
{
    int n;
    cin >> n;

    set<int> s;
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        if (temp != -1)
            s.insert(temp);
    }

    if (s.size() > 1)
        cout << "NO\n";
    else
    {
        if (s.size() == 1 && *s.begin() == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
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