#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int changes(string &n, string &last)
{
    int ans = 0;
    int i = n.size() - 1;

    while (i >= 0 && n[i] != last[1])
    {
        i--;
        ans++;
    }

    if (i < 0)
        return INT_MAX;
    i--;

    while (i >= 0 && n[i] != last[0])
    {
        i--;
        ans++;
    }

    return i < 0 ? INT_MAX : ans;
}

void solve()
{
    string n;
    cin >> n;

    vector<string> needed = {"00", "25", "50", "75"};

    int ans = INT_MAX;
    for (auto s : needed)
    {
        ans = min(ans, changes(n, s));
    }

    cout << ans << endl;
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