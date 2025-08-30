// Given a string with spaces, print the a string words backwards without any trailing or leading spaces.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    fastread;
    string s;
    getline(cin, s);
    string ans = "";
    string temp = "";
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ')
        i--;
    for (; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            if (temp != "")
            {
                reverse(temp.begin(), temp.end());
                ans += temp + " ";
                temp = "";
            }
        }
        else
            temp += s[i];
    }
    if (s[i] != ' ')
    {
        reverse(temp.begin(), temp.end());
        ans += temp;
    }
    if (!ans.empty() && ans[ans.size() - 1] == ' ')
        ans.pop_back();

    cout << ans << endl;
}