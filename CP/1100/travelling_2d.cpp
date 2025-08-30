#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(ll i = a; i < b; i++)

void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    vector<pair<ll, ll>> arr(k + 1);
    pair<ll, ll> start, end;

    for(int i = 1, x, y; i <= n; i++){
        cin >> x >> y;
        if(i <= k){
            arr[i] = {x, y};
        }
        if(i == a){
            start = {x, y};
        }
        if(i == b){
            end = {x, y};
        }
    }

    if((a <= k and b <= k) || (a == b)){
        cout << 0 << endl;
        return;
    }

    ll ans = llabs(start.first - end.first) + llabs(start.second - end.second), first = LLONG_MAX / 2, second = LLONG_MAX / 2;

    for(int i = 1; i <= k; i++){
        first = min(first, llabs(start.first - arr[i].first) + llabs(start.second - arr[i].second));
        second = min(second, llabs(end.first - arr[i].first) + llabs(end.second - arr[i].second));
    }

    ans = min(ans, first + second);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    ll t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}