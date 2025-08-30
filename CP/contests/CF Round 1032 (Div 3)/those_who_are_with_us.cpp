#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 0, count = 0;
    unordered_map<int, int> r, c;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] > ans){
                r.clear(), c.clear();
                ans = arr[i][j];
                r[i]++, c[j]++;
                count = 1;
            }else if(arr[i][j] == ans){
                r[i]++, c[j]++;
                count++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == ans){
                if(count - (r[i] + c[j] - 1) == 0){
                    cout << ans - 1 << endl;
                    return;
                }
            }else{
                if(count - (r[i] + c[j]) == 0){
                    cout << ans - 1 << endl;
                    return;
                }
            }
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