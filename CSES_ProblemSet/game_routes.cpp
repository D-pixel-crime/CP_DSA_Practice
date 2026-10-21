#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

vector<vector<int>> g;
vector<int> dp;

int solve(int i)
{
    if (i == dp.size() - 1)
    {
        return 1;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int ans = 0;
    for (auto &j : g[i])
    {
        ans = (0LL + ans + solve(j)) % MOD;
    }

    return dp[i] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g = vector<vector<int>>(n + 1);
    dp = vector<int>(n + 1, -1);

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        g[a].push_back(b);
    }

    cout << solve(1) << "\n";

    return 0;
}