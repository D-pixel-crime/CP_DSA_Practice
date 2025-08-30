#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)cin >> arr[i];

    ll ans = 0;
    int i = 0;
    while(i < n){
        int j = i;
        while(j < n && arr[j] <= q){
            j++;
        }

        int len = j - i;
        if(len >= k){
            for(int a = k; a <= len; a++){
                ans += (ll)(len - a + 1);
            }
        }
        if(j != i)i = j;
        else i++;
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