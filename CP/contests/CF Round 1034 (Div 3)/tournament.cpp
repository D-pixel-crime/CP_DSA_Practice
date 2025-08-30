#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, j, k;
    cin >> n >> j >> k;

    int count = 0, maxi = INT_MIN;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        maxi = max(arr[i], maxi);
    }

    int needed = arr[j];

    if(maxi == needed){
        cout << "YES\n";
    }else{
        if(k == 1){
            cout << "NO\n";
        }else cout << "YES\n";
    }
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