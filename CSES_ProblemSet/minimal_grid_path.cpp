#include <iostream>
#include <string>
#include <vector>
using namespace std;

// string findMin(vector<vector<string>> &dp, vector<string> &g, int i, int j) {
//   if (!i && !j) {
//     return string(1, g[i][j]);
//   }
//   if (dp[i][j] != ".") {
//     return dp[i][j];
//   }

//   string ans = "";
//   if (i - 1 >= 0) {
//     ans = findMin(dp, g, i - 1, j);
//   }
//   if (j - 1 >= 0) {
//     ans = ans.empty() ? findMin(dp, g, i, j - 1)
//                       : min(ans, findMin(dp, g, i, j - 1));
//   }
//   ans.push_back(g[i][j]);

//   return dp[i][j] = ans;
// }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }

  vector<string> prev(n), curr(n);
  prev[0] = string(1, g[0][0]);

  for (int j = 1; j < n; j++) {
    prev[j] = prev[j - 1];
    prev[j].push_back(g[0][j]);
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!j) {
        curr[j] = prev[j];
      } else {
        curr[j] = (prev[j] < curr[j - 1]) ? prev[j] : curr[j - 1];
      }

      curr[j].push_back(g[i][j]);
    }

    prev.swap(curr);
  }

  cout << prev[n - 1] << endl;

  return 0;
}