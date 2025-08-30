// You are given a matrix A
//  with N
//  rows and M
//  columns. You have to traverse the matrix in spiral form and output the elements in the order that you encounter them.

// The spiral traversal starts from the top row of the matrix from the left to right direction. Please look at the sample testcase to understand the spiral traversal.

// CONSTRAINTS
// 1≤N×M≤1000000

// 0≤Aij≤109
// INPUT
// The first line contains two numbers N
//  and M
// . The next N
//  lines contain M
//  integers each representing the rows of the matrix.

// OUTPUT
// Output N×M
//  integers representing the order of the elements.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

int main()
{
    fastread;
    ll n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int startRow = 0, endRow = n - 1, startCol = 0, endCol = m - 1;

    while (startRow <= endRow && startCol <= endCol)
    {
        for (int j = startCol; j <= endCol; j++)
            cout << arr[startRow][j] << " ";
        startRow++;

        for (int i = startRow; i <= endRow; i++)
            cout << arr[i][endCol] << " ";
        endCol--;

        for (int j = endCol; j >= startCol; j--)
            cout << arr[endRow][j] << " ";
        endRow--;

        for (int i = endRow; i >= startRow; i--)
            cout << arr[i][startCol] << " ";
        startCol++;
    }
}