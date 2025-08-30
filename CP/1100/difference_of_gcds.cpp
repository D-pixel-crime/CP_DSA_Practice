#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;

    unordered_map<int, int> val;
    bool isOk = true;
    for (int i = 1; i <= n; i++)
    {
        val[i] = (((l - 1) / i) + 1) * i;
        isOk = isOk && val[i] <= r;
    }

    if (isOk)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            cout << val[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "NO\n";
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