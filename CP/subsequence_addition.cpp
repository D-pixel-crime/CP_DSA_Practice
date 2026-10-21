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

    bool isOk = true;
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        if (temp > n)
        {
            isOk = false;
        }
    }

    cout << (isOk ? "Yes\n" : "No\n");
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