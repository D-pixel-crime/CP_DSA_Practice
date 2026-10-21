#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

bool isFair(ll& n){
    ll temp = n;
    while(temp){
        int dig = temp % 10;
        if(dig != 0 and n % dig != 0){
            return false;
        }
        temp /= 10;
    }

    return true;
}

void solve() {
    ll n;
    cin >> n;

    while(!isFair(n)){
        n++;
    }

    cout << n << endl;
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