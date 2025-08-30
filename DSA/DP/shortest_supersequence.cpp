#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    if (s.size() < t.size())
    {
        swap(s, t);
    }
    int n = s.size(), m = t.size();
    vector<int> prev(m + 1);

    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(m + 1);
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(curr[j - 1], prev[j]);
            }
        }
        prev = curr;
    }

    if (prev[m] == m)
    {
        cout << n << endl;
    }
    else
    {
        cout << n + (m - prev[m]) << endl;
    }

    return 0;
}