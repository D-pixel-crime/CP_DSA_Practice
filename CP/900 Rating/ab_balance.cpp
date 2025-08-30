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
    
    if (s == "")
    {
        cout << s << endl;
        return;
    }

    int n = s.size();

    if (s[0] == s[n - 1])
    {
        cout << s << endl;
        return;
    }

    s[n - 1] = s[0];
    cout << s << endl;
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