// Given a string, generate its Longest Prefix which also a suffix (LPS) array

#include <bits/stdc++.h>
using namespace std;

void fillLPS(vector<int> &lps, string &s)
{
    int k = 0;
    for (int i = 1; i < lps.size(); i++)
    {
        if (s[i] == s[k])
            lps[i] = ++k;
        else
            k = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    string s;
    cin >> s;

    vector<int> lps(s.size(), 0);

    fillLPS(lps, s);

    for (auto i : lps)
        cout << i << " ";

    return 0;
}