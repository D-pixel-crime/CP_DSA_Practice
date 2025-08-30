// There are n
//  rectangular boxes of the same size: w
//  in width and h
//  in length. You are required to find a square of the smallest size into which these boxes can be packed. Boxes cannot be rotated.

// The image above shows one of the ways of packing 10
//  boxes having width 2
//  and height 3
//  into a square of side 9
//  as given in the first test case of the sample.

// INPUT
// The first line contains the number of testcases t(1≤t≤104)
// . The input for each test case contains three integers w,h,n(1≤w,h,n≤109)
// .

// OUTPUT
// Output t
//  lines. For each test case, output the minimum length of a side of a square, into which the given boxes can be packed..

// EXAMPLE
// Sample 1 INPUT:
// 5
// 2 3 10w
// 1 5 2
// 1 1 6
// 4 1 5
// 1 9 9
// Sample 1 OUTPUT:
// 9
// 5
// 3
// 5
// 9

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

bool isPossible(ll &mid, ll &w, ll &h, ll &n)
{
    return (mid / w) * (mid / h) >= n;
}

int main()
{
    fastread;
    int t;
    cin >> t;
    while (t--)
    {
        ll w, h, n;
        cin >> w >> h >> n;
        ll start = 0, end = 1;
        while ((end / w) * (end / h) <= n)
            end *= 2;
        while (start + 1 < end)
        {
            ll mid = start + (end - start) / 2;
            if (isPossible(mid, w, h, n))
                end = mid;
            else
                start = mid;
        }

        cout << end << endl;
    }
}