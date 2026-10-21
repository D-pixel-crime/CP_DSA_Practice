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
    string s;
    cin >> s;

    bool isOk = true;
    unordered_map<char, int> count;
    count[s[0]]++;
    for (int i = 0, j = 1; j < s.size(); i++, j++)
    {
        if (s[i] == s[j])
        {
            isOk = false;
        }
        count[s[j]]++;
    }

    if (count.size() == 1)
    {
        cout << "YES\n";
        return;
    }
    if (!isOk)
    {
        cout << "NO\n";
        return;
    }

    for (auto &i : count)
    {
        if (i.second > 2 && count.size() > 2)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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