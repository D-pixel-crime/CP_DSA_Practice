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

    int ans = INT_MAX, even = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(!(temp & 1))even++;

        int res = temp % k;
        if(res == 0){
            ans = 0;
        }else{
            ans = min(ans, k - res);
        }
    }

    if(k != 4)cout << ans << endl;
    else{
        cout << min(ans, max(2 - even, 0)) << endl;
    }
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