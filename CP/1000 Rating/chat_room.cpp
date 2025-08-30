#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    if (s.size() < 5)
    {
        cout << "NO\n";
        return 0;
    }
    else
    {
        int i = 0;
        string temp = "";
        for (auto ch : s)
        {
            if (ch == 'h' && temp == "")
            {
                temp.push_back(ch);
            }
            else if (ch == 'e' && temp == "h")
            {
                temp.push_back(ch);
            }
            else if (ch == 'l' && temp == "he")
            {
                temp.push_back(ch);
            }
            else if (ch == 'l' && temp == "hel")
            {
                temp.push_back(ch);
            }
            else if (ch == 'o' && temp == "hell")
            {
                temp.push_back(ch);
            }
        }

        cout << (temp == "hello" ? "YES\n" : "NO\n");
    }
    return 0;
}