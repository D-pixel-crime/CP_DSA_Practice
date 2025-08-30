#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_map<char, int> pos;
    for(int i = n - 1; i >= 0; i--){
        char ch = s[i];
        for(auto& j: pos){
            if(j.first < ch){
                cout << "YES\n" << i + 1 << " " << j.second + 1 << endl;
                return 0;
            }
        }

        pos[ch] = i;
    }

    cout << "NO\n";
    
    return 0;
}