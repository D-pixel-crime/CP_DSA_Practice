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

bool removeAndCheckPalindrome(vector<int> temp, int &target)
{
    int i = 0, j = temp.size() - 1;
    while (i < j)
    {
        if (temp[i] != temp[j])
        {
            if (temp[i] == target)
            {
                i++;
            }
            else if (temp[j] == target)
            {
                j--;
            }
            else
                return false;
        }
        else
            i++, j--;
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] == arr[j])
        {
            i++, j--;
        }
        else
            break;
    }

    int first = arr[i], second = arr[j];
    if (removeAndCheckPalindrome(arr, first))
    {
        cout << "YES\n";
    }
    else if (removeAndCheckPalindrome(arr, second))
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}