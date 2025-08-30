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

    unordered_map<int, int> count;
    for(int i = 0; i < n - 1; i++){
        if(count.count(s[i])){
            cout << "Yes\n";
            return;
        }
        count[s[i]]++;
    }

    count.clear();
    for(int i = n - 1; i > 0; i--){
        if(count.count(s[i])){
            cout << "Yes\n";
            return;
        }
        count[s[i]]++;
    }

    cout << "No\n";
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