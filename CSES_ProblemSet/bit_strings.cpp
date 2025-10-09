#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
int mod = 1e9 + 7;

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

    int n;
    cin >> n;

    ll ans = 1LL;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans * 2) % mod;
    }

    cout << ans << endl;

    return 0;
}