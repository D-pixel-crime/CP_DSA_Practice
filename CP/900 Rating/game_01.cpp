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

    int zero = 0, one = 0;
    for (auto ch : s)
    {
        if (ch == '0')
            zero++;
        else
            one++;
    }

    int pairs = min(zero, one);
    if (pairs == 0)
    {
        cout << "NET\n";
        return;
    }

    if (pairs & 1)
    {
        cout << "DA\n";
        return;
    }
    cout << "NET\n";
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