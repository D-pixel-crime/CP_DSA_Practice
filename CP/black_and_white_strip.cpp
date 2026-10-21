#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, k
    ;cin >> n >> k;

    string s;
    cin >> s;

    vector<int> prefix(n);
    if(s[0] == 'W')prefix[0] = 1;

    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1];
        if(s[i] == 'W')prefix[i]++;
    }

    int i = 0, j = k - 1, ans = INT_MAX;
    while(j < n){
        int count = prefix[j] - prefix[i] + (s[i] == 'W' ? 1 : 0);
        ans = min(count, ans);
        i++, j++;
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