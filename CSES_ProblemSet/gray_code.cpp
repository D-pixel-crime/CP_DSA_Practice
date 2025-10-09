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

vector<string> findGrayCodes(int n)
{
    if (n == 1)
    {
        return {"0", "1"};
    }

    vector<string> original = findGrayCodes(n - 1);
    vector<string> temp = original;
    reverse(all(temp));

    for (auto &i : original)
    {
        i = "0" + i;
    }
    for (auto &i : temp)
    {
        i = "1" + i;
        original.push_back(i);
    }

    return original;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> ans = findGrayCodes(n);
    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}