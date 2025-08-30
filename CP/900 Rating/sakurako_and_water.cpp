#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int mini = INT_MAX;
        for(int j = 0, k = i; k < n; j++, k++){
            mini = min(mini, arr[j][k]);
        }
        if(mini < 0){
            ans += abs(mini);
        }
    }

    for(int i = 1; i < n; i++){
        int mini = INT_MAX;
        for(int j = i, k = 0; j < n; j++, k++){
            mini = min(mini, arr[j][k]);
        }
        if(mini < 0){
            ans += abs(mini);
        }
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