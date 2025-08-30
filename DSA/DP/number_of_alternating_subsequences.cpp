#include <bits/stdc++.h>
using namespace std;

#define ll long long
int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll one = 2, zero = 1;
    for (int i = 2; i < n; i++)
    {
        if (i & 1)
        {
            one = (one + zero + 1) % mod;
        }
        else
        {
            zero = (zero + one + 1) % mod;
        }
    }

    cout << (zero + one) % mod << endl;

    return 0;
}