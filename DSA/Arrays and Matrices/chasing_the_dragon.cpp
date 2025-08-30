#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    fastread;

    long long int n;
    cin >> n;

    vector<long long int> cost(n, 0);
    vector<long long int> prefix(n, 0);

    for (long long int i = 0; i < n; i++)
    {
        cin >> cost[i];
        if (i == 0)
        {
            prefix[i] = cost[i];
        }
        else
        {
            prefix[i] = cost[i] + prefix[i - 1];
        }
    }

    long long int k;
    cin >> k;

    long long int curr = 0;

    while (k--)
    {
        long long int dir, dist, prev = curr;
        cin >> dir >> dist;

        dist %= n;

        if (dir == -1)
        {
            curr = (curr - dist + n) % n;
        }
        else
        {
            curr = (curr + dist) % n;
        }

        long long int ans = 0;

        if (curr >= prev)
        {
            ans = min(prefix[curr] - prefix[prev],
                      prefix[n - 1] - (prefix[curr] - prefix[prev]));
        }
        else
        {
            ans = min(prefix[prev] - prefix[curr],
                      prefix[n - 1] - (prefix[prev] - prefix[curr]));
        }

        cout << ans << endl;
    }

    return 0;
}
