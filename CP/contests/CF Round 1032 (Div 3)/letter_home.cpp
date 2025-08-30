#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << abs(min(s - arr[0], arr[n - 1] - s)) + (arr[n - 1] - arr[0]) << endl;
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