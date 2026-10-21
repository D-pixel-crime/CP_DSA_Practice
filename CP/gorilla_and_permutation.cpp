#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = n; i >= k; i--)cout << i << " ";
    for(int i = m + 1; i <= k - 1; i++)cout << i << " ";
    for(int i = 1; i <= m; i++)cout << i << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}