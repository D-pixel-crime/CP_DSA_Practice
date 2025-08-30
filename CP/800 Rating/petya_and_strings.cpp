#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s, t;
    cin >> s >> t;

    int i = 0, j = 0;

    while(i < s.size() && j < t.size()){
        char a = s[i], b = t[j];
        if(a >= 'A' && a <= 'Z'){
            a = a - 'A' + 'a';
        }
        if(b >= 'A' && b <= 'Z'){
            b = b - 'A' + 'a';
        }
        if(a < b){
            cout << -1 << endl;
            return 0;
        }else if(a > b){
            cout << 1 << endl;
            return 0;
        }else i++, j++;
    }

    cout << 0 << endl;
    
    return 0;
}