#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<vector<int>> &dp, string &s, string &t, int i, int j) {
  if (i == -1) {
    return j + 1;
  }
  if (j == -1) {
    return i + 1;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int skip = findMin(dp, s, t, i - 1, j - 1);
  if (s[i] == t[j]) {
    return dp[i][j] = skip;
  }
  return dp[i][j] = 1 + min({findMin(dp, s, t, i - 1, j),
                             findMin(dp, s, t, i, j - 1), skip});
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s, t;
  cin >> s >> t;

  int n = s.size(), m = t.size();

  if (n > m) {
    swap(s, t);
    swap(n, m);
  }

  vector<vector<int>> dp(n, vector<int>(m, -1));
  cout << findMin(dp, s, t, n - 1, m - 1) << endl;

  return 0;
}