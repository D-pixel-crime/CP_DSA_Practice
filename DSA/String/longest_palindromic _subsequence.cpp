// Given a string s, return the length of the longest palindromic subsequence in s.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int LPS(string &s, int i, int j)
{
    if (i > j)
        return 0;
    if (i == j)
        return 1;

    if (s[i] == s[j])
    {
        return 2 + LPS(s, i + 1, j - 1);
    }
    else
        return max(LPS(s, i + 1, j), LPS(s, i, j - 1));
}

int main()
{
    fastread;
    string s;
    cin >> s;
    cout << LPS(s, 0, s.size() - 1) << endl;
}