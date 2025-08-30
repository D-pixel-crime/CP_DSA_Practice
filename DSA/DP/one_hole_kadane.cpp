#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    ll temp;
    cin >> temp;
    ll take, dont = 0, ans = temp;
    take = temp;
    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        dont = max(take, dont + temp);
        take = max(take + temp, temp);
        ans = max({ans, dont, take});
    }

    cout << ans << endl;

    return 0;
}