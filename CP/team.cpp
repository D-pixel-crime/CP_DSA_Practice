#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ans = 0;
    while (n--)
    {
        int curr = 0;
        for (int i = 0; i < 3; i++)
        {
            int temp;
            cin >> temp;
            curr += temp;
        }

        if (curr >= 2)
            ans++;
    }

    cout << ans << endl;

    return 0;
}