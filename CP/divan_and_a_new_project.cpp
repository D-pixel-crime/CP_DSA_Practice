#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(all(arr), [](const auto& a, const auto& b){
        return a.first < b.first;
    });

    vector<int> pos(n + 1);
    int last = 1;
    ll ans = 0;
    int end = INT_MIN, start = INT_MAX;
    
    for(int i = n - 1; i >= 0; i--){
        auto [times, j] = arr[i];
        pos[j] = last;
        if(last > 0){
            end = max(end, last);
        }else{
            start = min(start, last);
        }

        ans += (1LL * times * 2 * abs(last));

        if(last < 0){
            last = abs(last) + 1;
        }else last = -last;
    }

    int a = 1e6 - end, b = abs(start - 1e6);

    cout << ans << endl;
    for(auto i: pos){
        if(a < b){
            i = i + a;
        }else{
            i = i - b;
        }
        cout << i << " ";
    }

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