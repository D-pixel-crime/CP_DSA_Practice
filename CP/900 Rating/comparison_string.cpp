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
    string s;
    cin >> s;

    int ans = 0;
    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && s[j] == s[i])
            j++;

        ans = max(ans, j - i + 1);
        i = j;
    }

    cout << ans << "\n";
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