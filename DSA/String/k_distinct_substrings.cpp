// Given a string s of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters.

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
    cin >> s;
    unordered_map<string, bool> count;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = s.size() - 1; j >= i; j--)
        {
            string temp = s.substr(i, j - i + 1);
            if (count.find(temp) == count.end())
            {
                count[temp] = true;
            }
        }
    }

    cout << count.size() << endl;
}