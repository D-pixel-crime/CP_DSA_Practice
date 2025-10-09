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

    ll n;
    cin >> n;

    /*
    Number of ways of arranging 1st knight = k^2
    Number of ways of arranging 2nd knight when 1st has been allocated = k^2 - 1
    Total ways of arranging both = (k^2 * (k^2 - 1)) / 2!  -----> Basic Permutation

    Knights attack each other when they are at opposite corners of a 2x3 block or 3x2 block
    Number of 2x3 block = (k - 1) * (k - 2) ----> Ways for attacking in each = 2 * (k - 1) * (k - 2)
    Number of 3x2 block = (k - 2) * (k - 1) ----> Ways for attacking in each = 2 * (k - 2) * (k - 1)

    Total attacking scenarios = 4 * (k - 1) * (k - 2)

    Total valid ways = ((k^2 * (k^2 - 1)) / 2!) - (4 * (k - 1) * (k - 2))
    */

    for (ll i = 1; i <= n; i++)
    {
        ll ans = (((i * i) * ((i * i) - 1)) / 2) - (4 * (i - 1) * (i - 2));
        cout << ans << endl;
    }

    return 0;
}