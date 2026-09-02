#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int mod = 1000000007;
unordered_map<int, int> factVals;

int countBits(int x) { return floor(log2(x)) + 1; }

vector<bool> simpleSieve(int &n) {
  vector<bool> arr(n + 1, true);

  for (int i = 2; i * i <= n; i++) {
    if (arr[i]) {
      for (int j = i * i; j <= n; j += i) {
        arr[j] = false;
      }
    }
  }

  return arr;
}

int binaryExponentiation(int x, int n, int m = 1) {
  int ans = 1;
  while (n) {
    if (n & 1) {
      ans = (ans * x) % m;
      n--;
    } else {
      x = (x * x) % m;
      n >>= 2;
    }
  }

  return ans;
}

int extendedEuclidean(int a, int m, int &x, int &y) {
  if (m == 0) {
    x = 1, y = 0;
    return a;
  }
  int x1, y1;
  int gcd = extendedEuclidean(m, a % m, x1, y1);
  x = y1;
  y = x1 - (a / m) * y1;
  return gcd;
}

int modularInverse(int a, int m) {
  int x, y;
  int gcd = extendedEuclidean(a, m, x, y);
  if (gcd != 1)
    return -1;
  return (x % m + m) % m;
}

int fact(int n) {
  if (n <= 1)
    return 1;
  if (factVals.count(n))
    return factVals[n];
  int ans = 1, i = n;
  while (i >= 2) {
    if (factVals.count(i)) {
      return factVals[n] = (1LL * ans * factVals[i]) % mod;
    } else {
      ans = (1LL * ans * i) % mod;
      i--;
    }
  }
  return factVals[n] = ans;
}

int nCx(int n, int x) {
  int num = fact(n);
  int denom = (1LL * fact(x) * fact(n - x)) % mod;
  return (1LL * num * modularInverse(denom, mod)) % mod;
}

int solve(vector<vector<int>> &dp, int &tot, int i, int j) {
  if (j > tot) {
    return 0;
  }
  if (i == dp.size()) {
    if (tot == j) {
      return 1;
    }
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  return dp[i][j] =
             (0LL + solve(dp, tot, i + 1, j + i) + solve(dp, tot, i + 1, j)) %
             mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int tot = n * (n + 1) / 2;

  if (tot & 1) {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<int>> dp(n + 1, vector<int>(tot + 1, -1));
  tot /= 2;

  int ans = solve(dp, tot, 1, 0);

  cout << (1LL * ans * modularInverse(2, mod)) % mod << endl;

  return 0;
}