#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int a, b;
    cin >> a >> b;

    if(a == b){
        cout << 2 << endl;
        return;
    }
    if(a < b){
        cout << 1 << endl;
        return;
    }

    int ans = INT_MAX, op;
    for(int i = 0; i <= 32; i++){
        int new_b = b + i;
        if(new_b == 1)continue;
        op = i;
        int temp = a;
        while(temp){
            temp /= new_b;
            op++;
        }

        ans = min(ans, op);
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