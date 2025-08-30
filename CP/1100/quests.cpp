#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, k;
    cin >> n >> k;

    ll ans = 0;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int maxi = INT_MIN;
    ll curr = 0;
    for(int i = 1; i <=n ; i++){
        int temp;
        cin >> temp;
        if(k >= i){
            maxi = max(maxi, temp);
            curr += a[i - 1];
            ans = max(ans, curr + (maxi * (k - i)));
        }
    }

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