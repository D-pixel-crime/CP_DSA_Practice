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

    vector<int> first(26, 0), second(26, 0);
    int sum = 0, a = 0, b = 0;
    for (auto ch : s)
    {
        if (second[ch - 'a'] == 0)
            b++;
        second[ch - 'a']++;
    }

    sum = b;
    for (auto ch : s)
    {
        if (first[ch - 'a'] == 0)
            a++;
        first[ch - 'a']++;
        second[ch - 'a']--;
        if (second[ch - 'a'] == 0)
            b--;

        sum = max(sum, a + b);
    }

    cout << sum << endl;
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