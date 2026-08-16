#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MOD = 1e9 + 7;

int ways(vector<vector<int>> &dp, vector<int> &arr, const int &x, int i, int j)
{
    if (i >= arr.size())
    {
        return j == x;
    }
    if (j == x)
    {
        return 1;
    }
    if (j > x - arr[i])
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int dont = ways(dp, arr, x, i + 1, j), take = 0;
    if (j <= x - arr[i])
    {
        take = ways(dp, arr, x, i, j + arr[i]);
    }

    return dp[i][j] = (0LL + dont + take) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    vector<int> prev(x + 1), curr(x + 1);
    prev[x] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        curr[x] = 1;
        for (int j = x - 1; j >= 0; j--)
        {
            curr[j] = prev[j];
            if (j <= x - arr[i])
            {
                curr[j] = (0LL + curr[j] + curr[j + arr[i]]) % MOD;
            }
        }
        prev.swap(curr);
    }

    cout << prev[0] << endl;

    return 0;
}