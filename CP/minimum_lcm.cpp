#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)


void solve() {
    int n;
    cin >> n;

    int ans = 1;
    int end = sqrt(n);
    for(int i = 2; i <= end; i++){
        if(n % i == 0){
            ans = max({ans, i, n / i});
        }
    }

    cout << ans << " " << n - ans << endl;
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