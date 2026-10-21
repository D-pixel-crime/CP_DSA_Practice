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
        ll a, b, c;
        cin >> a >> b >> c;

        ll anna = a + (c / 2), katie = b + (c / 2);
        if (c & 1)
            anna++;

        cout << (anna > katie ? "First" : "Second") << endl;
    }

    return 0;
}