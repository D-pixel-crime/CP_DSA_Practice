#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)


void solve() {
    string a, b;
    cin >> a >> b;

    if(a == b){
        cout << 0 << endl;
        return;
    }

    int longest_common_substring = 0;

    vector<int> prev(b.size() + 1);
    for(int i = 1; i <= a.size(); i++){
        vector<int> curr(b.size() + 1);
        for(int j = 1; j <= b.size(); j++){
            if(a[i - 1] == b[j - 1]){
                curr[j] = 1 + prev[j - 1];
            }else curr[j] = 0;
            longest_common_substring = max(longest_common_substring, curr[j]);
        }
        prev = curr;
    }

    cout << (a.size() - longest_common_substring) + (b.size() - longest_common_substring) << endl;
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