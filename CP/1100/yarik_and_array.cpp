#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++)cin >> arr[i];

    int ans = arr[0], curr = ans;
    for(int i = 1; i < n; i++){
        if((arr[i] & 1) == (arr[i - 1] & 1)){
            curr = arr[i];
            ans = max(ans, curr);
        }else{
            curr = max(curr + arr[i], arr[i]);
            ans = max(ans, curr);
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