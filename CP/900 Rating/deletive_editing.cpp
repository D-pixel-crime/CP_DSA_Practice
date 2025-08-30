#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    string s, t;
    cin >> s >> t;

    if (s == t)
    {
        cout << "YES\n";
        return;
    }

    vector<int> temp = {};
    vector<vector<int>> pos(26, temp);

    for (int i = 0; i < s.size(); i++)
    {
        pos[s[i] - 'A'].push_back(i);
    }

    for (int i = t.size() - 1; i > 0; i--)
    {
        if (pos[t[i] - 'A'] == temp || pos[t[i - 1] - 'A'] == temp)
        {
            cout << "NO\n";
            return;
        }
        if (t[i] != t[i - 1] && pos[t[i] - 'A'].back() < pos[t[i - 1] - 'A'].back())
        {
            cout << "NO\n";
            return;
        }

        pos[t[i] - 'A'].pop_back();
    }

    if (t.size() > 0 && pos[t[0] - 'A'] == temp)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}