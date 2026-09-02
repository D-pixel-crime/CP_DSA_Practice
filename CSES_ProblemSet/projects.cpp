#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using ll = long long;
using namespace std;

vector<pair<ll, int>> arr;
unordered_map<int, vector<ll>> pos;
vector<ll> dp;

int upb(int targ)
{
    int start = -1, end = arr.size();
    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid].first <= targ)
        {
            start = mid;
        }
        else
        {
            end = mid;
        }
    }

    return end;
}

ll solve(int i)
{
    if (i >= dp.size())
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    ll dont = solve(i + 1), take = pos[arr[i].second][2] + solve(upb(pos[arr[i].second][1]));

    return dp[i] = max(take, dont);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    arr = vector<pair<ll, int>>(n);
    for (int i = 0; i < n; i++)
    {
        ll a, b, val;
        cin >> a >> b >> val;
        pos[i] = {a, b, val};
        arr[i] = {a, i};
    }

    dp = vector<ll>(n, -1);
    sort(arr.begin(), arr.end());

    cout << solve(0) << endl;

    return 0;
}