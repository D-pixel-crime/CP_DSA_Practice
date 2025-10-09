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

    int n;
    cin >> n;

    ll ans = LLONG_MIN, curr = LLONG_MIN;
    while (n--)
    {
        ll temp;
        cin >> temp;

        curr = curr == LLONG_MIN ? temp : max(temp, curr + temp);
        ans = max(ans, curr);
    }

    cout << ans << endl;

    return 0;
}