#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    ll n, x;
    cin >> n >> x;
    queue<ll> a, b, c;

    for(ll i = 0, temp; i < n; i++){
        cin >> temp;
        a.push(temp);
    }
    for(ll i = 0, temp; i < n; i++){
        cin >> temp;
        b.push(temp);
    }
    for(ll i = 0, temp; i < n; i++){
        cin >> temp;
        c.push(temp);
    }

    vector<queue<ll>> arr = {a, b, c};
    ll curr = 0;

    for(auto st: arr){
        while(!st.empty()){
            ll top = st.front(); st.pop();
            if((top | x) == x){
                curr |= top;
            }else break;
        }
    }

    cout << (curr == x ? "Yes" : "No") << endl;
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