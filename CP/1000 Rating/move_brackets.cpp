#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    stack<char> st;
    int ans = 0;

    for(auto ch: s){
        if(ch == ')'){
            if(st.empty()){
                ans++;
            }else st.pop();
        }else st.push(ch);
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