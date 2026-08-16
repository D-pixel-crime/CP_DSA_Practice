#include <iostream>
#include <vector>
using namespace std;

constexpr int MOD = 1e9 + 7;

int ways(vector<int> &dp, const int &n, int i)
{
    if (i == n)
    {
        return 1;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int ans = 0;
    for (int j = 1; j <= 6; j++)
    {
        if (i + j <= n)
        {
            ans = (0LL + ans + ways(dp, n, i + j)) % MOD;
        }
    }

    return dp[i] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << ways(dp, n, 0) << endl;

    return 0;
}