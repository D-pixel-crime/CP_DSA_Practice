#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int j, i = 1;
    cin >> j;
    string s;
    cin >> s;

    int k = s.size() - 1;

    vector<int> ans;

    while (k >= 0)
    {
        if (s[k] == '<')
        {
            ans.push_back(i++);
        }
        else
        {
            ans.push_back(j--);
        }

        k--;
    }

    if (i <= j)
    {
        ans.push_back(i++);
    }

    reverse(all(ans));

    rep(i, 0, ans.size())
    {
        cout << ans[i] << " ";
    }

    cout << endl;
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