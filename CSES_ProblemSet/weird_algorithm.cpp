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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    while (n != 1)
    {
        cout << n << " ";
        if (!(n & 1))
        {
            n /= 2;
        }
        else
        {
            n = n * 3 + 1;
        }
    }
    cout << 1 << endl;

    return 0;
}