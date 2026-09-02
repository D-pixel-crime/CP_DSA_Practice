#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<string> s(n);
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, n + 1));
  vector<pair<pair<char, int>, pair<int, int>>> curr;

  for (int d = 2 * n - 2; d >= 0; d--)
  {
    curr.clear();
    for (int i = 0; i < n; i++)
    {
      int j = d - i;
      if (j >= 0 && j < n)
      {
        curr.emplace_back(make_pair(s[i][j], min(dp[i + 1][j], dp[i][j + 1])), make_pair(i, j));
      }
    }

    sort(curr.begin(), curr.end());
    int k = 0;

    for (int p = 0; p < curr.size(); p++)
    {
      if (!k || curr[p].first != curr[p - 1].first)
      {
        k++;
      }
      auto &[i, j] = curr[p].second;
      dp[i][j] = min(dp[i][j], k);
    }
  }

  int i = 0, j = 0;
  while (i < n && j < n)
  {
    cout << s[i][j];
    if (dp[i + 1][j] < dp[i][j + 1])
    {
      i++;
    }
    else
    {
      j++;
    }
  }

  cout << endl;

  return 0;
}