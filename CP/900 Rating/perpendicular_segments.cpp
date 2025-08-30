#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    int diff = abs(x - y);
    int maxi = max(x, y);

    if(x == y){
        cout << 0 << " " << 0 << " " << x << " " << y << endl;
        cout << 0 << " " << y << " " << x << " " << 0 << endl;
    }else{
        if(x > y){
            cout << diff << " " << 0 << " " << x << " " << y << endl;
            cout << x - diff << " " <<  0 << " " << 0 << " " << y << endl;
        }else{
            cout << 0 << " " << diff << " " << x << " " << y << endl;
            cout << 0 << " " << y - diff << " " << x << " " << 0 << endl;
        }
    }
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