#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

bool isPrime(ll &x){
    if(x == 2 || x == 3)return true;
    ll temp = sqrt(x);
    for(int i = 2; i <= temp + 1; i++){
        if(x % i == 0){
            return false;
        }
    }

    return true;
}

void solve() {
    int d;
    cin >> d;

    ll a = 1 + d;
    while(!isPrime(a)){
        a++;
    }

    ll b = a + d;
    while(!isPrime(b)){
        b++;
    }

    cout << min(a * a * a, a * b) << endl;
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