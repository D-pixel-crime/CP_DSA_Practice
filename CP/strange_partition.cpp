#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n, x;
    cin >> n >> x;

    ll small = 0, large = 0;
    while (n--)
    {
        int temp;
        cin >> temp;
        large += (ll)ceil(temp / (double)x);
        small += temp;
    }

    cout << (ll)ceil(small / (double)x) << " " << large << endl;
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