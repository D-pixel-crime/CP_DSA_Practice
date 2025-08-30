// Given a string, give the lexicographically smallest string possible after swapping atmost 1 element

#include <bits/stdc++.h>
using namespace std;

void lexicographicallySmallestAfter1Swap(string &s)
{
    string temp = s;
    sort(temp.begin(), temp.end());

    if (temp == s)
        return;

    int pos = -1;
    char toChange;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != temp[i])
        {
            toChange = temp[i];
            pos = i;
            break;
        }
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == toChange)
        {
            swap(s[i], s[pos]);
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;

    lexicographicallySmallestAfter1Swap(s);

    cout << s << endl;

    return 0;
}