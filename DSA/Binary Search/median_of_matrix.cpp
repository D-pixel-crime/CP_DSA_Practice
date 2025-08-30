// Find the median of a row-wise sorted matrix

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

bool isPossible(vector<vector<int>> &arr, int &target, int &m, int &n)
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        int start = -1, end = n;
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (arr[i][mid] <= target)
                start = mid;
            else
                end = mid;
        }
        count += (start + 1);
    }

    return count > (m * n) / 2;
}

int main()
{
    fastread;
    int m, n;
    int start = INT_MAX, end = INT_MIN;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            start = min(arr[i][j], start);
            end = max(arr[i][j], end);
        }
    }
    start--, end++;

    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, mid, m, n))
            end = mid;
        else
            start = mid;
    }

    cout << end << endl;
}