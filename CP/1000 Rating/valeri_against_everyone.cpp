#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> isThere;
    string ans = "NO\n";
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(isThere.count(temp)){
            ans = "YES\n";
        }
        isThere[temp]++;
    }

    cout << ans;
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