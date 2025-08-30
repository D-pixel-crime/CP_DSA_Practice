#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

bool isVowel(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y')
        return true;
    if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'Y')
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    string ans = "";

    for (auto ch : s)
    {
        if (!isVowel(ch))
        {
            if (ch >= 'a' and ch <= 'z')
            {
                ans = ans + "." + string(1, ch);
            }
            else if (ch >= 'A' and ch <= 'Z')
            {
                ans = ans + "." + string(1, (ch - 'A') + 'a');
            }
        }
    }

    cout << ans << endl;

    return 0;
}