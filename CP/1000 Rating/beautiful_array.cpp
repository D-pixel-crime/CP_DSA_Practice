#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    ll n, b, k, s;
    cin >> n >> k >> b >> s;

    ll start = b * k, end = start + (n * (k - 1));

    if(s < start || s > end){
        cout << -1 << endl;
        return;
    }

    vector<ll> ans(n);

    ll remain = s - start;
    ll temp = start + min(k - 1, remain);
    remain -= min(k - 1, remain);

    cout << temp << " ";

    for(int i = 1; i < n; i++){
        temp = min(k - 1, remain);
        remain -= temp;

        cout << temp << " ";
    }

    cout << endl;
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