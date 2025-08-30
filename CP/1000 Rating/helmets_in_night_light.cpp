#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, p;
    cin >> n >> p;

    ll ans = p;
    vector<pair<ll, ll>> arr(n);
    arr.pb({p, INT_MAX});
    for(int i = 0; i < n; i++){
        cin >> arr[i].second;
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
    }

    sort(all(arr));

    int i = 0, got = 1;
    while(got < n){
        int left = n - got;
        if(arr[i].second <= left){
            ans += (arr[i].second * arr[i].first);
            got += arr[i].second;
        }else{
            ans += (arr[i].first * left);
            got = n;
        }
        i++;
    }

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