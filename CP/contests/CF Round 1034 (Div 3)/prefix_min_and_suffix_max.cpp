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
    vector<int> mini(n), maxi(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << 1;
    mini[0] = arr[0];
    for(int i = 1; i < n; i++){
        mini[i] = min(arr[i], mini[i - 1]);
    }

    maxi[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--){
        maxi[i] = max(maxi[i + 1], arr[i]);
    }

    for(int i = 1; i < n - 1; i++){
        if(mini[i] == arr[i] || maxi[i] == arr[i]){
            cout << 1;
        }else cout << 0;
    }

    cout << 1 << endl;
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