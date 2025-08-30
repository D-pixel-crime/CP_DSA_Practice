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

    int n = stol(s);

    if (n == 0)
    {
        cout << 0 << " " << 0 << endl;
        return;
    }

    int temp = sqrt(n);
    if ((temp * temp) == n)
    {
        cout << temp - 1 << " " << 1 << endl;
    }
    else
        cout << -1 << endl;
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