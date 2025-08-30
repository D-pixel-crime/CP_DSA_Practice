#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

pair<int, int> countChar(string &s)
{
    int one = 0, zero = 0;
    for (auto ch : s)
    {
        if (ch == '1')
            one++;
        else
            zero++;
    }

    return {zero, one};
}

int findMax(vector<pair<int, int>> &arr, vector<vector<vector<int>>> &dp, int i, int j, int k)
{
    if (i >= arr.size())
        return 0;
    if (j <= 0 && k <= 0)
        return dp[i][j][k] = 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    int dont = findMax(arr, dp, i + 1, j, k);
    int take = 0;
    if (j >= arr[i].first && k >= arr[i].second)
    {
        take = 1 + findMax(arr, dp, i + 1, j - arr[i].first, k - arr[i].second);
    }

    return dp[i][j][k] = max(dont, take);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, m, n;
    cin >> c >> m >> n;

    vector<pair<int, int>> arr(c);

    for (int i = 0; i < c; i++)
    {
        string s;
        cin >> s;
        arr[i] = countChar(s);
    }

    // vector<vector<vector<int>>> dp(c, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

    // cout << findMax(arr, dp, 0, m, n) << endl;

    vector<vector<int>> prev(m + 1, vector<int>(n + 1));

    for(int i = 0; i < c; i++){
        vector<vector<int>> curr(m + 1, vector<int>(n + 1));
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= n; k++){
                curr[j][k] = prev[j][k];
                if(j >= arr[i].first && k >= arr[i].second){
                    curr[j][k] = max(curr[j][k], 1 + prev[j - arr[i].first][k - arr[i].second]);
                }
            }
        }
        prev = curr;
    }

    cout << prev[m][n] << endl;

    return 0;
}