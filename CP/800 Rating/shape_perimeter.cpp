#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;

    n--;
    int ans = 0;
    while(n--){
        cin >> x >> y;
        ans += (x + y);
    }

    ans *= 2;
    ans += (4 * m);
    cout << ans << endl;
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