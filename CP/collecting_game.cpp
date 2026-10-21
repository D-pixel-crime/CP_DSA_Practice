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
        arr[i].second = i;
    }

    sort(all(arr), [](const auto& a, const auto& b){
        return a.first < b.first;
    });

    ll sum = 0;
    vector<int> breakpoints;

    for(int i = 0; i < n - 1; i++){
        sum += arr[i].first;
        if(sum < arr[i + 1].first){
            breakpoints.push_back(i);
        }
    }

    reverse(all(breakpoints));

    vector<int> ans(n, n - 1);
    for(int i = 0; i < n; i++){
        if(breakpoints.empty()){
            break;
        }else{
            ans[arr[i].second] = breakpoints.back();
            if(i == breakpoints.back()){
                breakpoints.pop_back();
            }
        }
    }

    for(auto i: ans){
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