#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int countBits(int x)
{
    return floor(log2(x)) + 1;
}

void solve()
{
    int n;
    cin >> n;

    string a;
    cin >> a;

    int m;
    cin >> m;

    string b, c;
    cin >> b >> c;

    string start = "", end = "";
    for (int i = 0; i < m; i++)
    {
        if (c[i] == 'V')
        {
            start = string(1, b[i]) + start;
        }
        else
            end.push_back(b[i]);
    }

    cout << start << a << end << endl;
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