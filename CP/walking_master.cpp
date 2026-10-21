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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll yDist = abs(d - b);
        if (d < b || a + yDist < c)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            ll newX = a + yDist;
            ll xDist = abs(c - newX);

            cout << yDist + xDist << endl;
        }
    }

    return 0;
}