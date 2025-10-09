#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
int mod = 1e9 + 7;

unordered_map<int, int> factVals;

int countBits(int x)
{
    return floor(log2(x)) + 1;
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
    {
        return 1;
    }
    if (factVals.count(n))
    {
        return factVals[n];
    }
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map<int, int> count;
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        if (!count.count(temp))
        {
            count[temp] = 1;
        }
        count[temp]++;
    }

    int ans = 1;
    for (auto &i : count)
    {
        int n = i.second;
        ans = (1LL * ans * nCx(n, 1)) % mod;
    }

    cout << ans - 1 << endl;

    return 0;
}