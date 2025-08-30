#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> count(26, 0);
        for (auto ch : s)
            count[ch - 'a']++;

        sort(count.begin(), count.end());

        int i = 0;
        while (i < 26 && count[i] == 0)
            i++;

        int after = n - k;
        int odd = 0;

        while (i < 26)
        {
            if (count[i] & 1)
                odd++;
            i++;
        }

        if (odd <= k + (after & 1 ? 1 : 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}