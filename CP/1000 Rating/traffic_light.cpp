#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    char curr;
    cin >> n >> curr;

    string s;
    cin >> s;

    if(curr == 'g'){
        cout << 0 << endl;
        return;
    }

    int ans = 0;
    s += s;
    int last = -1;
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == curr and last != -1){
            ans = max(ans, last - i);
        }else if(s[i] == 'g'){
            last = i;
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