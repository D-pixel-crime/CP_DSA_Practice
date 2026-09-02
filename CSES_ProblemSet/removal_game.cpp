#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<vector<ll>> dp;

ll solve(vector<ll> &arr, int i, int j) {
  if (i == j) {
    return arr[i];
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  return dp[i][j] =
             max(arr[i] - solve(arr, i + 1, j), arr[j] - solve(arr, i, j - 1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  ll tot = 0;

  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    tot += arr[i];
  }

  dp = vector<vector<ll>>(n, vector<ll>(n, -1));
  ll diff = solve(arr, 0, n - 1);

  cout << (tot + diff) / 2 << endl;

  return 0;
}