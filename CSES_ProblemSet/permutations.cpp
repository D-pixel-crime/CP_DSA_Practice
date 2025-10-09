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

pair<bool, vector<int>> checkOdd(int n)
{
    vector<int> arr;
    for (int i = 1; i <= n; i += 2)
    {
        arr.push_back(i);
    }
    for (int i = 2; i <= n; i += 2)
    {
        if (abs(arr.back() - i) == 1)
        {
            return {false, arr};
        }
        arr.push_back(i);
    }

    return {true, arr};
}

pair<bool, vector<int>> checkEven(int n)
{
    vector<int> arr;
    for (int i = 2; i <= n; i += 2)
    {
        arr.push_back(i);
    }
    for (int i = 1; i <= n; i += 2)
    {
        if (abs(arr.back() - i) == 1)
        {
            return {false, arr};
        }
        arr.push_back(i);
    }

    return {true, arr};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    auto [ans, arr] = checkOdd(n);
    if (ans)
    {
        for (auto i : arr)
        {
            cout << i << " ";
        }
        return 0;
    }
    else
    {
        auto [ans, arr] = checkEven(n);
        if (ans)
        {
            for (auto i : arr)
            {
                cout << i << " ";
            }
            return 0;
        }
    }

    cout << "NO SOLUTION";

    return 0;
}