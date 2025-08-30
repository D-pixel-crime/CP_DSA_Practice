// Rotate a matrix by 90 degrees clockwise

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

void rotate_90degrees(vector<vector<ll>> &arr, int &n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(arr[i][j], arr[j][i]);

    for (int i = 0; i < n; i++)
        reverse(arr[i].begin(), arr[i].end());
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    rotate_90degrees(arr, n);

    for (auto &i : arr)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}