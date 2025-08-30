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
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;

        bool isPossible = false;
        int i = 0;

        for (; i <= 7; i++)
        {
            if (x.find(s) != string::npos)
            {
                isPossible = true;
                break;
            }
            x += x;
        }

        if (isPossible)
            cout << i << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}