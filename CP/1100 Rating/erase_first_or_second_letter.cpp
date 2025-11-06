#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    if(n == 1){
        cout << n << endl;
        return;
    }

    unordered_map<char, int> count;
    vector<int> unique(n);

    count[s[0]]++;
    unique[0] = 1;

    for(int i = 1; i < n; i++){
        count[s[i]]++;
        unique[i] = count.size();
    }

    int ans = 0;
    for(int i = n - 1; i >= 1; i--){
        ans += unique[i - 1];
    }

    cout << ans + unique[n - 1] << endl;
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