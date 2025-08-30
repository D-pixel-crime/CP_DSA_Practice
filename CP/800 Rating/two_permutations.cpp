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
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b >= n - 1)
        {
            if (a == n && b == n)
                cout << "Yes";
            else
                cout << "No";
        }
        else
            cout << "Yes";
        cout << "\n";
    }

    return 0;
}