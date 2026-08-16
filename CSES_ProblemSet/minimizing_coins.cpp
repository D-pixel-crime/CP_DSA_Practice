#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMin(vector<int> &dp, vector<int> &arr, const int &x, int i)
{
    if (i == x)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int ans = INT_MAX;
    for (auto &j : arr)
    {
        if (i + j <= x)
        {
            int temp = findMin(dp, arr, x, i + j);
            if (temp != INT_MAX)
            {
                ans = min(ans, 1 + temp);
            }
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
    int ans = findMin(dp, arr, x, 0);

    cout << (ans == INT_MAX ? -1 : ans) << endl;

    return 0;
}