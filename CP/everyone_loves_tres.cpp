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

    if (n & 1)
    {
        if (n == 1 || n == 3)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i < n - 5; i++)
            {
                cout << 3;
            }
            cout << 36366 << endl;
        }
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            cout << 3;
        }
        cout << 66 << endl;
    }
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