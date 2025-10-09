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
    return __popcount(x);
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

class Trie
{
private:
    vector<vector<int>> g;
    vector<int> hotnode;
    int nodeCnt;

public:
    Trie()
    {
        nodeCnt = 0;
        g.push_back({-1, -1});
    }

    void insertNumber(int &n)
    {
        vector<int> all;
        int temp = n;
        while (temp)
        {
            all.push_back((temp & 1) ? 1 : 0);
            temp >>= 1;
        }

        while (all.size() != 32)
        {
            all.push_back(0);
        }

        int curr = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (g[curr][all[i]] != -1)
            {
                curr = g[curr][all[i]];
            }
            else
            {
                nodeCnt++;
                hotnode.push_back(0);
                g.push_back({-1, -1});
                curr = g[curr][all[i]] = nodeCnt;
            }
        }

        hotnode[curr]++;
    }

    int maxXorPossible(int &pre)
    {
        vector<int> all;
        int temp = pre;
        while (temp)
        {
            all.push_back((temp & 1) ? 1 : 0);
            temp >>= 1;
        }

        while (all.size() != 32)
        {
            all.push_back(0);
        }

        int curr = 0, ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int desired = !all[i];
            if (g[curr][desired] != -1)
            {
                ans = (ans << 1) | 1;
                curr = g[curr][desired];
            }
            else
            {
                ans <<= 1;
                curr = g[curr][all[i]];
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Trie numTrie = Trie();

    int pre = 0, ans = 0;
    numTrie.insertNumber(pre);
    for (int i = 0, input; i < n; i++)
    {
        cin >> input;
        pre ^= input;

        ans = max(ans, numTrie.maxXorPossible(pre));

        numTrie.insertNumber(pre);
    }

    cout << ans << endl;

    return 0;
}