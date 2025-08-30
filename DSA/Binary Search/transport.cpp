// N
//  passengers arrive at your transport service. The ith
//  passenger arrives at time ti
// . You have M
//  buses at your service and each bus can hold C
//  passengers.

// A bus can depart with any number of passengers from 0
//  to C
//  in it. It is guaranteed that you have sufficient buses to transport all the passengers to their destination i.e. M∗C≥N
// .

// A bus can leave when the last passenger onboard the bus arrives. The other passengers have to wait for the last passenger to arrive to leave. The passengers don't like waiting. So your task is to calculate the smallest possible value of the maximum waiting time of the passengers if the bus departures are scheduled optimally.

// Constraints:
// 1≤N≤105

// 1≤M≤105

// 0≤ti≤109

// 1≤C≤N

// INPUT
// The first line of the input contains three integers - N,M,C
// . The second line of the input contains N
//  integers stating the arrival time of the N
//  passengers.

// OUTPUT
// Output a single number which is the smallest possible value of the maximum waiting time.

// Example
// Input:
// 6 3 2
// 1 1 10 14 4 3
// Output:
// 4

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

bool isPossible(vector<ll> &time, ll &mid, ll &m, ll &c)
{
    ll last = time[0], totalBuses = 1, curr = 1, maxWait = 0;
    for (auto i = 1; i < time.size(); i++)
    {
        if (time[i] - last <= mid && curr <= c)
        {
            curr++;
        }
        else
        {
            totalBuses++;
            last = time[i];
            curr = 1;
        }
    }

    return totalBuses <= m;
}

int main()
{
    fastread;
    ll n, m, c;
    cin >> n >> m >> c;
    vector<ll> time(n);
    for (auto i = 0; i < n; i++)
        cin >> time[i];
    ll start = -1, end = *max_element(time.begin(), time.end()) - *min_element(time.begin(), time.end()) + 1, temp = end;
    sort(time.begin(), time.end());
    while (start + 1 < end)
    {
        ll mid = start + (end - start) / 2;
        if (isPossible(time, mid, m, c))
            end = mid;
        else
            start = mid;
    }

    cout << (end != temp ? end : -1) << endl;
}