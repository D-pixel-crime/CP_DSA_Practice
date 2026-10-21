#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, x;
    cin >> n >> x;

    int count = 0;
    vector<ll> arr(n);
    cin >> arr[0];

    ll l = arr[0] - x;
    ll r = arr[0] + x;
    for(int i = 1; i < n; i++){
        cin >> arr[i];
        l = max(l, arr[i] - x), r = min(r, arr[i] + x);
        if(l > r){
            count++;
            l = arr[i] - x, r = arr[i] + x;
        }
    }

    cout << count << endl;
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