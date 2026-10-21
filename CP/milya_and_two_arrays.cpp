#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> a, b;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a[temp]++;
    }
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        b[temp]++;
    }

    if(a.size() + b.size() < 4){
        cout << "NO\n";
    }else cout << "YES\n";
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