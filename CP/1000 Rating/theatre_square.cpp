#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a;
    cin >> n >> m >> a;

    ll l = (ll)ceil(n / (double)a);
    ll w = (ll)ceil(m / (double)a);

    cout << l * w << endl;

    return 0;
}