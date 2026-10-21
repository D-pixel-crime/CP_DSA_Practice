#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        int n;
        cin >> a >> b >> n;

        ll ans = b;

        while (n--)
        {
            ll temp;
            cin >> temp;

            ans += min(temp, a - 1);
        }

        cout << ans << "\n";
    }

    return 0;
}