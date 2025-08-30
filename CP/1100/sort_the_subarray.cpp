#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n;
    cin >> n;

    vector<int> before(n), after(n);
    for (int i = 0; i < n; i++)
        cin >> before[i];
    for (int i = 0; i < n; i++)
        cin >> after[i];

    tuple<int, int, int> ans = {1, 1, 1};
    int i = 0;
    while (i < n)
    {
        int j = i + 1;
        bool applied = before[i] != after[i];
        while (j < n && after[j] >= after[j - 1])
        {
            applied = applied || (before[j] != after[j]);
            j++;
        }

        if (applied)
        {
            int len = j - i + 1;
            auto [maxi, _, _] = ans;
            if (len > maxi)
            {
                ans = {len, i + 1, j};
            }
        }

        i = j;
    }

    auto [len, start, end] = ans;
    cout << start << " " << end << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}