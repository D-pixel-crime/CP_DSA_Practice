#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int w, h;
    cin >> w >> h;

    int k;
    cin >> k;
    
    ll ans = 0;
    int mini = INT_MAX, maxi = INT_MIN;
    while(k--){
        int temp;
        cin >> temp;
        mini = min(mini, temp);
        maxi = max(maxi, temp);
    }
    ll temp = 1LL * (maxi - mini) * h;
    ans = max(ans, temp);
    
    cin >> k;
    mini = INT_MAX, maxi = INT_MIN;
    while(k--){
        int temp;
        cin >> temp;
        mini = min(mini, temp);
        maxi = max(maxi, temp);
    }
    temp = 1LL * (maxi - mini) * h;
    ans = max(ans, temp);
    
    cin >> k;
    mini = INT_MAX, maxi = INT_MIN;
    while(k--){
        int temp;
        cin >> temp;
        mini = min(mini, temp);
        maxi = max(maxi, temp);
    }
    temp = 1LL * (maxi - mini) * w;
    ans = max(ans, temp);

    cin >> k;
    mini = INT_MAX, maxi = INT_MIN;
    while(k--){
        int temp;
        cin >> temp;
        mini = min(mini, temp);
        maxi = max(maxi, temp);
    }
    temp = 1LL * (maxi - mini) * w;
    ans = max(ans, temp);


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