// You are at a candy shop, which has an unlimited type of candies and the number of candies of the i−th
//  type is i
// . Each candy costs 1
//  rupee and you have n
//  rupees. If you purchase a particular type of candy, you need to purchase all the candies of that type and the types less than that. Find the maximum number of types of candies you can purchase with n
//  rupees. For e.g. if you purchase 2 types of candies, you need to purchase 1
//  unit of the first type and 2
//  units of the second type.

// INPUT
// A single integer n
//  - amount of money you have. 0≤n≤1018
// .

// OUTPUT
// Output a single integer - the maximum number of types of candies.

// EXAMPLE
// Sample 1 INPUT:
// 5
// Sample 1 OUTPUT:
// 2

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

bool isPossible(ll &n, ll &mid)
{
    return ((mid * (mid + 1)) / 2) <= n;
}

int main()
{
    fastread;
    ll n;
    cin >> n;
    ll start = 0, end = sqrt(2 * n) + 1;
    while (start + 1 < end)
    {
        ll mid = start + (end - start) / 2;
        if (isPossible(n, mid))
            start = mid;
        else
            end = mid;
    }

    cout << start << endl;

    return 0;
}