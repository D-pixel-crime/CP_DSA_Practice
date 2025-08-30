// Given two strings, find the length of their Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

int recursiveLCS(string &s, string &t, int i, int j)
{
    if (i == s.size() || j == t.size())
        return 0;

    if (s[i] == t[j])
    {
        return 1 + recursiveLCS(s, t, i + 1, j + 1);
    }
    else
    {
        return max(recursiveLCS(s, t, i + 1, j), recursiveLCS(s, t, i, j + 1));
    }
}

int dpLCS(vector<vector<int>> &dp, string &s, string &t, int i, int j)
{
    if (i == s.size() || j == t.size())
        return 0;
    if (dp[i][j] > -1)
        return dp[i][j];

    if (s[i] == t[j])
    {
        return dp[i][j] = 1 + dpLCS(dp, s, t, i + 1, j + 1);
    }
    else
        return dp[i][j] = max(dpLCS(dp, s, t, i + 1, j), dpLCS(dp, s, t, i, j + 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    string t;
    cin >> s >> t;

    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));

    // cout << recursiveLCS(s, t, 0, 0) << endl;

    // cout << dpLCS(dp, s, t, 0, 0) << endl;

    // Iterative method
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[s.size()][t.size()] << endl;

    // Printing the LCS
    int i = s.size(), j = t.size();
    string lcs = "";
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            lcs = string(1, s[i - 1]) + lcs;
            i--, j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    cout << lcs << endl;

    return 0;
}