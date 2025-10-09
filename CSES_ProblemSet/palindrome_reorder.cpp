#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int countBits(int x)
{
    return floor(log2(x)) + 1;
}

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    unordered_map<char, int> count;
    for (auto i : s)
    {
        count[i]++;
    }

    if (s.size() & 1)
    {
        bool oneAllowed = false;
        char middle = ' ';
        int i = 0, j = s.size() - 1;
        for (auto &curr : count)
        {
            if (curr.second & 1)
            {
                if (oneAllowed)
                {
                    cout << "NO SOLUTION\n";
                    return 0;
                }
                else
                {
                    oneAllowed = true;
                    middle = curr.first;
                }
            }
            else
            {
                for (int k = 0; k < curr.second / 2; k++)
                {
                    s[i++] = s[j--] = curr.first;
                }
            }
        }
        while (i <= j)
        {
            s[i++] = middle;
        }
    }
    else
    {
        int i = 0, j = s.size() - 1;
        for (auto &curr : count)
        {
            if (curr.second & 1)
            {
                cout << "NO SOLUTION\n";
                return 0;
            }
            else
            {
                for (int k = 0; k < curr.second / 2; k++)
                {
                    s[i++] = s[j--] = curr.first;
                }
            }
        }
    }

    cout << s << endl;

    return 0;
}