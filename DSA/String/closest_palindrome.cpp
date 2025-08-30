// Given a number in the form of a string 's', find the closest palindromic number to it.
// If there are two more at the same deviation from 's', output the smaller number

#include <bits/stdc++.h>
using namespace std;

string findClosestPalindromic(string &s)
{
    if (s.size() == 0)
        return "0";
    if (s.size() == 1)
    {
        if (s == "0")
            return "1";
        return string(1, s[0] - 1);
    }

    if (s.substr(1, s.size() - 1) == string(s.size() - 1, '0'))
    {
        return string(s.size() - 1, '9');
    }

    if (s == string(s.size(), '9'))
    {
        string ans = string(s.size() + 1, '0');
        ans[0] = '1';
        ans[ans.size() - 1] = '1';
        return ans;
    }

    string a = "";
    if (s.size() % 2 == 0)
    {
        a = s.substr(0, s.size() / 2);
        for (int i = a.size() - 1; i >= 0; i--)
        {
            a.push_back(a[i]);
        }
    }
    else
    {
        a = s.substr(0, (s.size() / 2) + 1);
        for (int i = a.size() - 2; i >= 0; i--)
        {
            a.push_back(a[i]);
        }
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    string ans = findClosestPalindromic(s);

    cout << ans << endl;

    return 0;
}