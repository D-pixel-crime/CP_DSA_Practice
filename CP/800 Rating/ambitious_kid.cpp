#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    fastread;

    int n;
    cin >> n;
    int minDist = INT_MAX;
    while (n--)
    {
        int temp;
        cin >> temp;
        minDist = min(minDist, abs(temp));
    }

    cout << minDist << endl;

    return 0;
}