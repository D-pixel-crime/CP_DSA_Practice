// What is fast i/o & how you can implement it in your language:

// C++: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
// Java: https://www.geeksforgeeks.org/fast-io-in-java-in-competitive-programming/
// Python: https://www.geeksforgeeks.org/fast-i-o-for-competitive-programming-in-python/
// The Sphinx has presented you with N
//  numbers. The i
// -th number is ni
// . The sphinx now asks you Q
//  questions. The j
// -th question specifies two integers lj
//  and rj
// . You must answer with the sum of integers in the range [lj,rj]
// . That is the sum of all ni
//  where lj≤i≤rj
// .

// Input
// One integer N
//  on the first line.

// N
//  integers on the second line. The i
// -th integer is ni
// .

// One integer Q
//  on the third line.

// Q
//  lines follow. The j
// -th of these lines has two integers lj
//  rj
// .

// Constraints
// 1≤N,Q≤106

// 1≤ni≤106

// 1≤li≤ri≤N

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
    vector<int> arr(n, 0);
    vector<int> prefix(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i > 0)
            prefix[i] = arr[i] + prefix[i - 1];
        else prefix[i] = arr[i];
    }

    int q;
    cin >> q;
    while(q--){
        int s, e;
        cin >> s >> e;
        if(s > 1){
            cout << prefix[e - 1] - prefix[s - 1] + arr[s - 1];
        }
        else cout << prefix[e - 1];
        cout << endl;
    }
}