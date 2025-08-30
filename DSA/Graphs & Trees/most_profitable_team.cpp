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
    cin >> n;

    unordered_map<int, vector<int>> tree;
    for (int i = 2, v; i <= n; i++)
    {
        cin >> v;
        tree[v].push_back(i);
    }

    unordered_map<int, int> profit;
    for (int i = 1; i <= n; i++)
    {
        cin >> profit[i];
    }

    int ans = INT_MIN;
    function<int(int)> dfs = [&](int node)
    {
        if (!tree.count(node))
        {
            ans = max(ans, profit[node]);
            return profit[node];
        }

        int total = profit[node];
        for (auto j : tree[node])
        {
            total += dfs(j);
        }

        ans = max(ans, total);
        return total;
    };
    dfs(1);
    cout << ans << endl;

    return 0;
}