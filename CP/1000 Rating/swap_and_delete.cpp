#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    string s;
    cin >> s;

    int one = 0, zero = 0;
    for(auto ch: s){
        if(ch == '1')one++;
        else zero++;
    }

    int newLen = 0;
    for(auto ch: s){
        if(ch == '1'){
            if(!zero){
                break;
            }
            zero--;
            newLen++;
        }else{
            if(!one){
                break;
            }
            one--;
            newLen++;
        }
    }

    cout << s.size() - newLen << endl;
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