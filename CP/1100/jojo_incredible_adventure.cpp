#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int maxConsecutive(string &s)
{
    int ans = 0, n = s.size(), i = 0;
    while (i < n)
    {
        if (s[i] == '0')
        {
            i++;
            continue;
        }
        int j = i + 1;
        while (j < n && s[j] == '1')
        {
            j++;
        }

        ans = max(ans, j - i);
        i = j;
    }

    return ans;
}

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    s = s + s;
    int maxLen = maxConsecutive(s);

    if (maxLen >= n)
    {
        cout << 1LL * n * n << endl;
        return;
    }

    ll x = (maxLen + 1) / 2;
    ll y = ((maxLen + 1) / 2) + ((maxLen + 1) % 2);

    cout << x * y << endl;
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