#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    string ans = "";
    int i = 0, n = s.size();
    string curr = "";

    while (i < n)
    {
        if (i < n - 2 && s.substr(i, 3) == "WUB")
        {
            if (curr != "")
            {
                ans += (curr + " ");
            }
            curr = "";
            i += 3;
        }
        else
        {
            curr.push_back(s[i]);
            i++;
        }
    }

    if (curr != "")
        ans += (curr);

    cout << ans << endl;

    return 0;
}