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
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int ans = 0;
    int i = 0;
    while (i < s.size())
    {
        int j = i + 1;
        while (j < s.size() && s[j] == s[i])
        {
            j++;
        }

        ans = max(ans, j - i);
        i = j;
    }

    cout << ans << endl;

    return 0;
}