// Given a square matrix A
//  of size N×N
// , rotate it by 90 degrees in the anti-clockwise direction and output the new rotate matrix.

// Note: Since the input/output is huge in size, use fast input/output methods to avoid TLE.

// 1≤N≤1000

// 0≤Aij≤109

// INPUT
// The first line contains a single integer N
// .

// The next N
//  lines contain N
//  integers each indicating the rows of the matrix.

// OUTPUT
// Output N
//  rows with N
//  space separated integers representing the rotated matrix.

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
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> arr[i][j];

    for (ll j = n - 1; j >= 0; j--)
    {
        for (ll i = 0; i < n; i++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}