#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, r, b;
    cin >> n >> r >> b;

    int parts = b + 1;
    int base = r / parts;
    int extra = r % parts;

    string ans = "";
    for (int i = 0; i < parts; ++i) {
        int rs = base + (extra > 0 ? 1 : 0);
        ans += string(rs, 'R');
        if (extra > 0) extra--;

        if (b > 0) {
            ans += 'B';
            b--;
        }
    }

    cout << ans << '\n';
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