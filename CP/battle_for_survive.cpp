#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++)cin >> arr[i];

    ll diff = 0;
    for(int i = n - 3; i >= 0; i--){
        diff += arr[i];
    }

    diff = arr[n - 2] - diff;

    cout << arr[n - 1] - diff << endl;
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