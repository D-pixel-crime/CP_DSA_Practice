#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;

    ll s1 = 0, sn1 = (1LL * n * (n + 1)) / 2, s2 = 0, sn2 = (1LL * n * (n + 1) * ((2 * n) + 1)) / 6;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s1 += arr[i];
        s2 += (1LL * arr[i] * arr[i]);
    }

    ll missing = (((s2 - sn2) / (s1 - sn1)) - (s1 - sn1)) / 2;
    ll repete = ((s1 - sn1) + ((s2 - sn2) / (s1 - sn1))) / 2;

    cout << repete << " " << missing << endl;
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