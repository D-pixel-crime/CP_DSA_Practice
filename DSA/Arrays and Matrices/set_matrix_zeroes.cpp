// Given an n*m matrix, with zeroes in some cells. Make the row and columns of those cells zeroes.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

void set_matrix_zeroes(vector<vector<ll>> &arr, int &i, int &j)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int b = 0; b < m; b++)
        arr[i][b] = 0;
    for (int a = 0; a < n; a++)
        arr[a][j] = 0;
}

int main()
{
    fastread;
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m, 1));
    int k;
    cin >> k;
    vector<pair<int, int>> temp;
    while (k--)
    {
        int i, j;
        cin >> i >> j;
        temp.push_back({i, j});
    }
    
    for(auto curr : temp){
        set_matrix_zeroes(arr, curr.first, curr.second);
    }

    for (auto &i : arr)
    {

        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}