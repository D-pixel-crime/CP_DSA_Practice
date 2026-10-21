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
        int x;
        cin >> x;
        int temp = x;
        int len = 0;
        while (temp)
        {
            len++;
            temp /= 10;
        }

        int oneStepDown = len - 1;

        int step = pow(10, oneStepDown);
        int i = step;
        int ans = 9 * oneStepDown;

        while (i <= x)
        {
            ans++;
            i += step;
        }

        cout << ans << "\n";
    }

    return 0;
}