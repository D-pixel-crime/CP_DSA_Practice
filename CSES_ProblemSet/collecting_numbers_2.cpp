#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int countBits(int x)
{
    return floor(log2(x)) + 1;
}

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n), pos(n + 2);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int ans = 1;
    int curr = 1;
    while (curr < n)
    {
        if (pos[curr + 1] < pos[curr])
        {
            ans++;
        }
        curr++;
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        auto isInversionPresent = [&](const int &a, const int &b)
        {
            if (pos[a] > pos[b])
            {
                return 1;
            }
            return 0;
        };

        int mini = min(arr[a], arr[b]), maxi = max(arr[a], arr[b]);

        set<pair<int, int>> affectedPairs;
        if (mini != 1)
        {
            affectedPairs.insert({mini - 1, mini});
        }
        if (maxi != n)
        {
            affectedPairs.insert({maxi, maxi + 1});
        }
        affectedPairs.insert({mini, mini + 1});
        affectedPairs.insert({maxi - 1, maxi});

        for (auto &[i, j] : affectedPairs)
        {
            ans -= isInversionPresent(i, j);
        }

        swap(arr[a], arr[b]);
        pos[arr[a]] = a, pos[arr[b]] = b;

        for (auto &[i, j] : affectedPairs)
        {
            ans += isInversionPresent(i, j);
        }

        cout << ans << endl;
    }

    return 0;
}