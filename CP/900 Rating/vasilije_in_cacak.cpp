#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, x;
        cin >> n >> k >> x;

        ll firstKSum = (k * (k + 1)) / 2;
        ll lastKSum = ((n * (n + 1)) / 2) - (((n - k) * (n - k + 1)) / 2);

        cout << (firstKSum <= x && x <= lastKSum ? "YES\n" : "NO\n");
    }

    return 0;
}