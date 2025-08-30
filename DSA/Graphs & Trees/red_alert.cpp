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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int c;
    cin >> n >> c;

    set<int> reds;
    for (int i = 1, isRed; i <= n; i++)
    {
        cin >> isRed;
        if (isRed)
        {
            reds.insert(i);
        }
    }

    unordered_map<int, vector<int>> tree;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int ans = 0;
    function<void(int, int, int)> dfs = [&](int node, int par, int currC)
    {
        if (tree[node].size() == 1 && node != 1)
        {
            if (reds.count(node))
            {
                if (currC > 0)
                {
                    ans++;
                }
            }
            else
                ans++;

            return;
        }

        if (reds.count(node))
        {
            if (currC == 0)
            {
                return;
            }
            currC--;
        }
        else
            currC = c;

        for (auto j : tree[node])
        {
            if (j != par)
            {
                dfs(j, node, currC);
            }
        }
    };
    dfs(1, 0, c);

    cout << ans << endl;

    return 0;
}