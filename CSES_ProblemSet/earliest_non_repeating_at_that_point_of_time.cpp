#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

// Given a string stream, for each character, print the earliest non-repeating character found so far!

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    if (s.empty())
    {
        return 0;
    }

    set<pair<int, char>> nonRepeat;
    vector<int> pos(256, -1);

    nonRepeat.insert({0, s[0]});
    pos[s[0]] = 0;
    char last = s[0];
    cout << s[0];

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != last)
        {
            if (pos[s[i]] == -1)
            {
                if (last == '#')
                {
                    last = s[i];
                }

                pos[s[i]] = i;
                nonRepeat.insert({i, s[i]});
            }
            else
            {
                nonRepeat.erase({pos[s[i]], s[i]});
            }
        }
        else
        {
            nonRepeat.erase({pos[s[i]], s[i]});
            if (nonRepeat.empty())
            {
                last = '#';
            }
            else
            {
                last = (*nonRepeat.begin()).second;
            }
        }
        cout << last;
    }

    return 0;
}