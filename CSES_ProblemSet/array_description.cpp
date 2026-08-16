#include <iostream>
#include <vector>
using namespace std;

constexpr int MOD = 1e9 + 7;

int solve(vector<vector<int>> &dp, vector<int> &arr, int &m, int i, int j) {
  if (i >= arr.size()) {
    return 1;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (arr[i] && j && abs(arr[i] - j) > 1) {
    return dp[i][j] = 0;
  }

  int ans = 0;
  if (arr[i]) {
    ans = solve(dp, arr, m, i + 1, arr[i]);
  } else {
    if (!j) {
      for (int k = 1; k <= m; k++) {
        ans = (0LL + ans + solve(dp, arr, m, i + 1, k)) % MOD;
      }
    } else {
      ans = solve(dp, arr, m, i + 1, j);
      if (j > 1) {
        ans = (0LL + ans + solve(dp, arr, m, i + 1, j - 1)) % MOD;
      }
      if (j < m) {
        ans = (0LL + ans + solve(dp, arr, m, i + 1, j + 1)) % MOD;
      }
    }
  }

  return dp[i][j] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<vector<int>> dp(n, vector<int>(m + 1, -1));
  cout << solve(dp, arr, m, 0, 0) << endl;

  return 0;
}