// Given two strings 's' and 't', find the first index of occurence of 't' in 's'. If 't' does not occur in 's', return '-1'

#include <bits/stdc++.h>
using namespace std;

int patternSearchingNaive(string &s, string &t)
{
    if (t.size() > s.size() || t.size() == 0)
        return -1;

    for (int i = 0; i <= s.size() - t.size(); i++)
    {
        string temp = s.substr(i, t.size());
        if (temp == t)
            return i;
    }

    return -1;
}

int KMP(string &s, string &t)
{
    if (t.size() > s.size() || t.size() == 0)
        return -1;

    // forming the lps array
    vector<int> lps(t.size(), 0);
    int k = 0;
    for (int i = 1; i < t.size(); i++)
    {
        if (t[i] == t[k])
            lps[i] = ++k;
        else
            k = 0;
    }

    int i = 0, j = 0;
    while (i < s.size())
    {
        if (s[i] == t[j])
        {
            i++, j++;
        }
        if (j == t.size())
        {
            return i - j;
        }
        else if (i < s.size() && s[i] != t[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t;
    cin >> s >> t;

    // cout << patternSearchingNaive(s, t) << endl;

    cout << KMP(s, t) << endl;

    return 0;
}