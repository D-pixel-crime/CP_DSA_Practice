#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;

    ll needed = k + (y * k) - 1;
    ll sMoves = needed / (x - 1);
    if(needed % (x - 1) != 0){
        sMoves++;
    }
    
    ll ans = sMoves + k;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}