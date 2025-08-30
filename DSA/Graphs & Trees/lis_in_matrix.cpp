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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, -1));
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    function<int(int, int)> dfs = [&](int i, int j)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1;
        for (auto [a, b] : dir)
        {
            int ni = i + a, nj = b + j;
            if (ni >= 0 and ni < n and nj >= 0 and nj < m and arr[ni][nj] > arr[i][j])
            {
                ans = max(ans, dfs(ni, nj) + 1);
            }
        }

        return dp[i][j] = ans;
    };

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] == -1)
            {
                ans = max(ans, dfs(i, j));
            }
        }
    }

    cout << ans << endl;

    return 0;
}