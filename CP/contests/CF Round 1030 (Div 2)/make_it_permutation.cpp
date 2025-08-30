#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;

    cout << 2 * n - 1 << endl;
    for(int i = 1; i < n; i++){
        cout << i << " " << 1 << " " << i << endl;
        cout << i << " " << i + 1 << " " << n << endl;
    }

    cout << n << " " << 1 << " " << n << endl;
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