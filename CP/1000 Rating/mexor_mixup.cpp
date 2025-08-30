#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int a, b;
    cin >> a >> b;

    if(a == 1 && b == 1){
        cout << 3 << endl;
        return;
    }

    int temp = (a - 1) % 4;
    if(temp == 1){
        temp = 1;
    }else if(temp == 2){
        temp = a;
    }else if(temp == 3){
        temp = 0;
    }else if(temp == 0){
        temp = a - 1;
    }

    if(temp == b){
        cout << a << endl;
    }else{
        int needed = temp ^ b;
        if(needed != a){
            cout << a + 1 << endl;
        }else cout << a + 2 << endl;
    }
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