#include <iostream>
using namespace std;

typedef long long ll;

static constexpr int MOD = 1e9 + 7;
static constexpr int LIM = 1e6 + 1;

ll dp[LIM + 1][2];

void solve() {
  int n;
  cin >> n;

  cout << (dp[n][0] + dp[n][1]) % MOD << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  dp[1][0] = dp[1][1] = 1;
  for (int i = 1; i < LIM; i++) {
    dp[i + 1][0] = dp[i][1];
    dp[i + 1][1] = dp[i][0];
    dp[i + 1][0] = (dp[i + 1][0] + 2 * dp[i][0]) % MOD;
    dp[i + 1][1] = (dp[i + 1][1] + 4 * dp[i][1]) % MOD;
  }

  while (t--) {
    solve();
  }

  return 0;
}