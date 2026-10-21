#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        if (n % x == 0)
        {
            cout << 2 << endl;
            cout << n - 1 << " " << 1 << endl;
        }
        else
            cout << 1 << endl
                 << n << endl;
    }

    return 0;
}