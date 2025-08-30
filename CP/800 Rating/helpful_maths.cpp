#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> s;

    string temp;
    for(auto ch: s){
        if(ch != '+'){
            temp.push_back(ch);
        }
    }

    sort(all(temp));

    string ans;
    for(auto ch: temp){
        ans = ans + ch + "+";
    }

    ans.pop_back();

    cout << ans << endl;
    
    return 0;
}