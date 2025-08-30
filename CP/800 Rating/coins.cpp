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
        ll n, k;
        cin >> n >> k;

        if (!(n & 1))
        {
            cout << "Yes" << endl;
        }
        else
        {
            if (!(k & 1))
            {
                cout << "No" << endl;
            }
            else
            {
                if (n >= 2 + k || n == k)
                {
                    cout << "Yes" << endl;
                }
                else
                    cout << "No" << endl;
            }
        }
    }

    return 0;
}