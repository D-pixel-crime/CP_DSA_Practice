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

    unordered_map<char, int> count;
    for(auto ch: s){
        count[ch]++;
    }

    if(count.size() & 1){
        cout << "IGNORE HIM!";
    }else cout << "CHAT WITH HER!";
    
    return 0;
}