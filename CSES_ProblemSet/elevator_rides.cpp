#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, maxAllowed;
    cin >> n >> maxAllowed;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int lim = 1 << n;
    vector<pair<int, int>> dp(lim, make_pair(21, 0));
    dp[0] = {1, 0};

    for (int i = 1; i < lim; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int curr = 1 << j;
            if (i & curr)
            {
                auto prev = dp[i ^ curr];
                if (prev.second > maxAllowed - arr[j])
                {
                    prev.first++;
                    prev.second = min(prev.second, arr[j]);
                }
                else
                {
                    prev.second += arr[j];
                }

                dp[i] = min(dp[i], prev);
            }
        }
    }

    cout << dp[lim - 1].first << endl;

    return 0;
}