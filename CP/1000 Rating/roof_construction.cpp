#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;

    int temp = n - 1;
    int k = 0;
    temp >>= 1;

    while(temp){
        k++;
        temp >>= 1;
    }

    int div = (1 << k) - 1;
    temp = 1 << k;

    for(int i = div; i >= 0; i--){
        cout << i << " ";
    }
    for(int i = temp; i <= n - 1; i++){
        cout << i << " ";
    }

    cout << endl;
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