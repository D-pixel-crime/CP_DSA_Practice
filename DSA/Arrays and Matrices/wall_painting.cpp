// There is huge square wall of size 1000×1000
// . A point on the wall can be determined by it's coordinate (x,y)
//  where x,y∈[0,1000]
// .

// N
//  painters come and paint a rectangular portion of the wall such that the endpoints of the rectangle are integer coordinates. Each rectangle is given to you in the form x1,y1,x2,y2
//  where (x1,y1)
//  is the top left corner coordinates of the rectangle and (x2,y2)
//  is the bottom right corner coordinates.

// Your task is to calculate the area of the wall where exactly K
//  painters have painted. The number K
//  is provided to you.

// CONSTRAINTS
// 1≤K≤N≤105

// 0≤xi,yi≤1000
// INPUT
// The first line contains two integers N,K
// . The next N
//  lines contain 4 integers x1,y1,x2,y2
//  for each painter.

// OUTPUT
// Output the area painted by exactly K
//  painters.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

int main()
{
    fastread;
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> arr(1001, vector<ll>(1001, 0));

    while (n--)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr[x1][y1]++;
        if (x2 + 1 <= 1000)
            arr[x2 + 1][y1]--;
        if (y2 + 1 <= 1000)
            arr[x1][y2 + 1]--;
        if (y2 + 1 <= 1000 && x2 + 1 <= 1000)
            arr[x2 + 1][y2 + 1]++;
    }
    ll ans = 0;
    for (ll i = 0; i <= 1000; i++)
        for (ll j = 0; j <= 1000; j++)
        {
            if (i > 0)
                arr[i][j] += arr[i - 1][j];
            if (j > 0)
                arr[i][j] += arr[i][j - 1];
            if (i > 0 && j > 0)
                arr[i][j] -= arr[i - 1][j - 1];

            if (arr[i][j] == k)
                ans++;
        }

    cout << ans << endl;
}