#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

void solve(vector<vector<bool>> &dp, vector<int> &arr, int i, int j) {
  if (i >= arr.size()) {
    if (j) {
      ans.push_back(j);
    }
    return;
  }
  if (dp[i][j]) {
    return;
  }

  solve(dp, arr, i + 1, j);
  solve(dp, arr, i + 1, j + arr[i]);
  dp[i][j] = true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int tot = 0;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    tot += arr[i];
  }

  vector<vector<bool>> dp(n + 1, vector<bool>(tot + 1, false));
  solve(dp, arr, 0, 0);

  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());

  cout << ans.size() << endl;
  for (auto &i : ans) {
    cout << i << " ";
  }

  return 0;
}