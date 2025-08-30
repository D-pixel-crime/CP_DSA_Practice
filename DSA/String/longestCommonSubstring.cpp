// Given two strings 's' and 't', find the length of their Longest Common Substring

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

    int lcs = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                lcs = max(lcs, dp[i][j]);
            }
        }
    }

    string curr = "", ans = "";
    int i = s.size(), j = t.size();
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            curr = string(1, s[i - 1]) + curr;
            i--, j--;
        }
        else
        {
            if (curr.size() > ans.size())
                ans = curr;
            curr.clear();
            if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }

    if (curr.size() > ans.size())
        ans = curr;

    cout << lcs << endl
         << ans << endl;

    return 0;
}