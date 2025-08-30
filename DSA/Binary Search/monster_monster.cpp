// You have run into an army of
// N
// N monsters, and you must defeat them all!

// Each monster has a certain amount of health points (HP) which you know beforehand — the
// i
// i-th monster has
// H
// i
// H
// i
// ​
//   HP.
// You can attack exactly one monster per day, and only if your attack stat
// A
// A is greater than or equal to the monster's HP. In other words, you can attack a monster only if you can defeat it in a single hit.

// At the end of each day, the HP of each alive monster increases by a fixed value,
// X
// X.

// Find the minimum possible value of the attack stat
// A
// A you need to be able to kill all the monsters.
// Note that you're allowed to kill the monsters in any order you like.

// Input Format
// The first line of input will contain a single integer
// T
// T, denoting the number of test cases.
// Each test case consists of two lines of input.
// The first line of each test case contains two space-separated integers
// N
// N and
// X
// X — the number of monsters and the amount by which HP increases per day, respectively.
// The next line contains
// N
// N space separated integers,
// H
// 1
// ,
// H
// 2
// ,
// …
// ,
// H
// N
// H
// 1
// ​
//  ,H
// 2
// ​
//  ,…,H
// N
// ​
//  , the initial HP stats of the
// N
// N monsters.
// Output Format
// For each test case, output on a new line a single integer, the minimum attack stat
// A
// A needed to be able to kill all monsters.

#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPossible(vector<ll> &arr, ll &x, ll &mid)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > mid - (i * x))
            return 0;
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> arr(n);
        ll start = -1, end = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            start = max(start, arr[i]);
        }
        start--;
        sort(arr.begin(), arr.end(), greater<int>());
        while (start + 1 < end)
        {
            ll mid = start + (end - start) / 2;
            if (isPossible(arr, x, mid))
                end = mid;
            else
                start = mid;
        }

        cout << end << endl;
    }
}