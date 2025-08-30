// You are given an integer N
// . You are also given an array A
//  consisting of N
//  integers.

// Find the first natural number that is not present in A
// .

// Natural numbers are positive integers.

// Input
// One integer N
//  on the first line.

// N
//  integers on the second line. The i
// -th integer is vi
// .

// Constraints
// 1≤N≤106

// 1≤vi≤109

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
    vector<long long int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    long long int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ans)
            ans++;
    }
    cout << ans << endl;
    return 0;
}