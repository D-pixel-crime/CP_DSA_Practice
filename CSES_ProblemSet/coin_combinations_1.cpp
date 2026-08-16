#include <iostream>
#include <vector>
using namespace std;

constexpr int MOD = 1e9 + 7;

int ways(vector<int> &dp, vector<int> &arr, const int &x, int i)
{
    if (i == x)
    {
        return 1;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int ans = 0;
    for (auto &j : arr)
    {
        if (i + j <= x)
        {
            ans = (0LL + ans + ways(dp, arr, x, i + j)) % MOD;
        }
    }

    return dp[i] = ans;
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

    vector<int> dp(x + 1, -1);
    cout << ways(dp, arr, x, 0) << endl;

    return 0;
}