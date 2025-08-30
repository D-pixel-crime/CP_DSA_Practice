#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int findMin(vector<vector<int>> &arr, vector<vector<vector<int>>> &dp, int i, int j, int k)
{
    if (i >= arr.size())
    {
        if (j <= 0 && k <= 0)
            return 0;
        return INT_MAX;
    }
    if (j <= 0 && k <= 0)
        return 0;

    j = max(j, 0), k = max(k, 0);

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    int dont = findMin(arr, dp, i + 1, j, k);
    int take = findMin(arr, dp, i + 1, j - arr[i][0], k - arr[i][1]);
    if (take != INT_MAX)
    {
        take += arr[i][2];
    }

    return dp[i][j][k] = min(dont, take);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p, f, n;
    cin >> p >> f >> n;

    vector<vector<int>> arr(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(p + 1, vector<int>(f + 1, -1)));

    // int ans = findMin(arr, dp, 0, p, f);

    // cout << (ans == INT_MAX ? -1 : ans) << endl;

    vector<vector<int>> prev(p + 1, vector<int>(f + 1, INT_MAX));
    prev[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> curr(p + 1, vector<int>(f + 1, INT_MAX));
        for (int j = 0; j <= p; j++)
        {
            for (int k = 0; k <= f; k++)
            {
                curr[j][k] = prev[j][k];
                int a = max(j - arr[i][0], 0);
                int b = max(k - arr[i][1], 0);
                if (prev[a][b] != INT_MAX)
                {
                    curr[j][k] = min(curr[j][k], prev[a][b] + arr[i][2]);
                }
            }
        }
        prev = curr;
    }

    cout << (prev[p][f] == INT_MAX ? -1 : prev[p][f]) << endl;

    return 0;
}