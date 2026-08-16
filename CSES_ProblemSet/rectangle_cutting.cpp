#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> a >> b;

  vector<vector<int>> dp(a + 1, vector<int>(b + 1));
  for (int i = 0; i <= a; i++) {
    dp[i][1] = i;
    dp[i][0] = 0;
  }
  for (int j = 0; j <= b; j++) {
    dp[0][j] = 0;
    dp[1][j] = j;
  }
  for (int i = 0; i <= min(a, b); i++) {
    dp[i][i] = 0;
  }

  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (i == j) {
        continue;
      }

      int ans = INT_MAX;
      for (int k = 1; k < i; k++) {
        ans = min(ans, 1 + dp[k][j] + dp[i - k][j]);
      }
      for (int k = 1; k < j; k++) {
        ans = min(ans, 1 + dp[i][k] + dp[i][j - k]);
      }

      dp[i][j] = ans;
    }
  }

  cout << dp[a][b] << endl;

  return 0;
}