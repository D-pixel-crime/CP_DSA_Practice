#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

constexpr int MOD = 1e9 + 7;

int ways(vector<vector<int>> &dp, vector<string> &arr, int &n, int i, int j) {
  if (i == n - 1 && j == n - 1) {
    return 1;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int r = 0, c = 0;
  if (i + 1 < n && arr[i + 1][j] != '*') {
    r = ways(dp, arr, n, i + 1, j);
  }
  if (j + 1 < n && arr[i][j + 1] != '*') {
    c = ways(dp, arr, n, i, j + 1);
  }

  return dp[i][j] = (0LL + r + c) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (arr[0][0] == '*' || arr[n - 1][n - 1] == '*') {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<int>> dp(n, vector<int>(n, -1));
  cout << ways(dp, arr, n, 0, 0) << endl;

  return 0;
}