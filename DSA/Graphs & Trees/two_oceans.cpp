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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<bool>> isFirstReachable(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < n; i++)
    {
        isFirstReachable[i][0] = true;
        q.push({i, 0});
    }
    for (int i = 0; i < m; i++)
    {
        isFirstReachable[0][i] = true;
        q.push({0, i});
    }

    function<void(vector<vector<bool>> &)> bfs = [&](vector<vector<bool>> &isReachable)
    {
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            for (auto [a, b] : dir)
            {
                int ni = i + a, nj = j + b;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && arr[ni][nj] >= arr[i][j] && !isReachable[ni][nj])
                {
                    isReachable[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    };

    bfs(isFirstReachable);

    vector<vector<bool>> isSecondReachable(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        isSecondReachable[i][m - 1] = true;
        q.push({i, m - 1});
    }
    for (int i = 0; i < m; i++)
    {
        isSecondReachable[n - 1][i] = true;
        q.push({n - 1, i});
    }

    bfs(isSecondReachable);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isFirstReachable[i][j] && isSecondReachable[i][j])
            {
                cout << 1 << " ";
            }
            else
                cout << 0 << " ";
        }
        cout << endl;
    }

    return 0;
}