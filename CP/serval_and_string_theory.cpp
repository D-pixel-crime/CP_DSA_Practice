#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (n == 1)
    {
        cout << "NO\n";
        return;
    }

    if (k == 0)
    {
        string temp = s;
        reverse(all(temp));

        if (temp > s)
            cout << "YES\n";
        else
            cout << "NO\n";

        return;
    }

    unordered_map<char, int> count;
    for (auto ch : s)
    {
        count[ch]++;
    }

    if (count.size() == 1)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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