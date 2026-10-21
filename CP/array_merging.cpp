#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> b[i];

    vector<int> sa(n), sb(n);
    int i = 0;
    while(i < n){
        int j = i;
        while(j < n && a[j] == a[i]){
            j++;
        }

        int len = j - i, temp = len;
        for(j = i; j < i + len; j++, temp--){
            sa[j] = temp;
        }

        i = j;
    }

    i = 0;
    while(i < n){
        int j = i;
        while(j < n && b[j] == b[i]){
            j++;
        }

        int len = j - i, temp = len;
        for(j = i; j < i + len; j++, temp--){
            sb[j] = temp;
        }

        i = j;
    }

    int ans = 1;
    unordered_map<int, int> count;
    for(int i = 0; i < n; i++){
        count[a[i]] = max(sa[i], count[a[i]]);
        ans = max(ans, count[a[i]]);
    }
    for(int i = 0; i < n; i++){
        ans = max(ans, sb[i] + count[b[i]]);
    }

    cout << ans << endl;
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