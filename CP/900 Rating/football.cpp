#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int i = 0;
    while (i < s.size())
    {
        int j = i;
        while (j < s.size() && s[j] == s[i])
            j++;
        if (j - i >= 7)
        {
            cout << "YES\n";
            return 0;
        }
        i = j;
    }

    cout << "NO\n";

    return 0;
}