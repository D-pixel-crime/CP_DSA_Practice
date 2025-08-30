#include <bits/stdc++.h>
using namespace std;

int lpss(string &s, vector<vector<int>> &dp, int i, int j)
{
    if (i == j)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 1;

    if (s[i] == s[j])
    {
        ans = 2 + lpss(s, dp, i + 1, j - 1);
    }
    else
    {
        ans = max(lpss(s, dp, i + 1, j), lpss(s, dp, i, j - 1));
    }

    return dp[i][j] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // cout << lpss(s, dp, 0, n - 1) << endl;
    cout << dp[0][n - 1] << endl;

    return 0;
}