// Corona has affected the country of IslandLand and people need to practice social distancing. IslandLand is a country on the X-Axis with M
//  islands floating on water. There are N
//  people living in this country.

// You have been given the start and end coordinates Li
//  and Ri
//  of all the M
//  islands. Suppose the government arranges the people in IslandLand in such a way that all the people have their feet on some island segment. Your task is to find the largest possible value of the minimum distance between any two people and report it to the government so that the government can ensure social distancing.

// Important Notes

// ⦿ People can stand only on integer coordinates.

// ⦿ Distance between two people standing on different islands has to also be considered.

// ⦿ It is guaranteed that the islands are non-overlapping

// Constraints
// 2≤N≤105

// 1≤M≤105

// 0≤Li≤Ri≤1018

// INPUT
// The first line contains two integers N
//  and M
// . The next M
//  lines contain two integers Li,Ri
//  denoting the start point and the end point of the island segment.

// OUTPUT
// Output a single integer indicating the largest possible value of the minimum distance between any two people.

// Example
// Input:
// 5 3
// 0 2
// 4 7
// 9 9
// Output:
// 2

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

bool isPossible(vector<vector<ll>> &arr, ll &mid, ll &n)
{
    ll totalPersons = 1;
    ll last = arr[0][0];
    ll curr = 0;

    while (true)
    {
        ll temp = last + mid;
        if (temp <= arr[curr][1])
        {
            last = temp;
            totalPersons++;
        }
        else
        {
            curr++;
            if (curr >= arr.size())
                break;
            if (temp < arr[curr][0])
            {
                last = arr[curr][0];
                totalPersons++;
            }
            else
            {
                last = temp;
                totalPersons++;
            }
        }
        if (totalPersons >= n)
            break;
    }

    return totalPersons >= n;
}

int main()
{
    fastread;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(m, vector<ll>(2));
    for (auto i = 0; i < m; i++)
        cin >> arr[i][0] >> arr[i][1];
    ll start = -1, end = arr[m - 1][1] - arr[0][0] + 1;
    while (start + 1 < end)
    {
        ll mid = start + (end - start) / 2;
        if (isPossible(arr, mid, n))
            start = mid;
        else
            end = mid;
    }

    cout << start << endl;
}