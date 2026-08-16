#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMin(vector<int> &dp, int i)
{
    if (!i)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int ans = INT_MAX;
    int temp = i;
    while (temp)
    {
        int dig = temp % 10;
        if (dig)
        {
            int nxt = findMin(dp, i - dig);
            if (nxt != INT_MAX)
            {
                ans = min(ans, 1 + nxt);
            }
        }
        temp /= 10;
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
    cout << findMin(dp, n) << endl;

    return 0;
}