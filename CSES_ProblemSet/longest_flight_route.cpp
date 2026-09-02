#include <bits/stdc++.h>
using namespace std;

#define INF INT_MIN

int solve(vector<int> &dp, vector<int> &nxt, vector<vector<int>> &g, int &n, int i)
{
    if (i == n)
    {
        return 1;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int ans = INF;
    for (auto &j : g[i])
    {
        int temp = 1 + solve(dp, nxt, g, n, j);
        if (temp > ans)
        {
            ans = temp;
            nxt[i] = j;
        }
    }

    return dp[i] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        g[a].push_back(b);
    }

    vector<int> dp(n + 1, -1);
    vector<int> nxt(n + 1, -1);
    dp[n] = 1;

    int ans = solve(dp, nxt, g, n, 1);

    if (ans <= 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << ans << "\n";

    int i = 1;
    while (i != n)
    {
        cout << i << " ";
        i = nxt[i];
    }
    cout << n << "\n";

    return 0;
}