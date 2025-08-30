#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].second;
        arr[i].second %= k;
        if(!arr[i].second)arr[i].second = k;
        arr[i].first = i + 1;
    }

    sort(all(arr), [](const auto& a, const auto &b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    for(auto [i, el]: arr){
        cout << i << " ";
    }

    cout << "\n";
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