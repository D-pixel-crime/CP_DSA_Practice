#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    sort(all(arr));

    vector<ll> pref, suff;
    pref.push_back(arr[0] + arr[1]);
    for(int i = 2, j = 3; j < n; i+=2, j+=2){
        pref.push_back(arr[i] + arr[j] + pref.back());
    }

    suff.push_back(arr[n - 1]);
    for(int i = n - 2; i >= 0; i--){
        suff.push_back(suff.back() + arr[i]);
    }

    ll ans = suff[k - 1];
    for(int i = 1; i < k; i++){
        ll temp = pref[i - 1] + suff[k - i - 1];
        ans = min(ans, temp);
    }
    ans = min(ans, pref[k - 1]);

    cout << sum - ans << endl;
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