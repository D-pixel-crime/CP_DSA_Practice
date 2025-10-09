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

    int n;
    cin >> n;

    function<int(int)> countFact5 = [&](int x)
    {
        if (x == 0)
            return 0;
        return x / 5 + countFact5(x / 5);
    };

    cout << countFact5(n) << endl;

    return 0;
}