#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> count;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        count[arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(count[arr[i]] == 1){
            cout << -1 << endl;
            return;
        }
    }

    vector<int> ans(n);
    for(int i = 1; i <= n; i++){
        ans[i - 1] = i;
    }

    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i + 1]){
            swap(arr[i], arr[i + 1]);
            swap(ans[i], ans[i + 1]);
        }
    }

    for(auto i: ans)cout << i << " ";

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