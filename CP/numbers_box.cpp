#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 0,mini = INT_MAX, count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp;
            cin >> temp;

            if(temp < 0){
                count++;
            }
            ans += abs(temp);
            mini = min(mini, abs(temp));
        }
    }

    if(count & 1){
        cout << ans - (2 * mini) << endl;
    }else cout << ans << endl;
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