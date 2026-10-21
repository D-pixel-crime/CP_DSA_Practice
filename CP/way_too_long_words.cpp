#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    if (n <= 10)
    {
        cout << s << endl;
        return;
    }

    string ans = string(1, s[0]);

    int l = n - 2;

    string temp = "";

    while (l)
    {
        int res = l % 10;
        temp = string(1, res + '0') + temp;
        l /= 10;
    }

    ans = ans + temp + string(1, s[n - 1]);

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