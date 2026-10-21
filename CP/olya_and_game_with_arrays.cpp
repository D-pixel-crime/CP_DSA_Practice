#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

pair<ll, ll> getMins(vector<ll>& arr){
    ll mini = INT_MAX, second_min = INT_MAX;
    for(auto i: arr){
        if(i < mini){
            second_min = mini;
            mini = i;
        }else if(i < second_min){
            second_min = i;
        }
    }

    return {mini, second_min};
}

void solve() {
    int n;
    cin >> n;

    ll mini = INT_MAX, second_min = INT_MAX, sum = 0;
    while(n--){
        int m;
        cin >> m;
        vector<ll> arr(m);
        for(int i = 0; i < m; i++){
            cin >> arr[i];
        }

        auto [a, b] = getMins(arr);

        mini = min(a, mini);
        second_min = min(second_min, b);

        sum += b;
    }

    mini = mini == INT_MAX ? 0: mini;
    second_min = second_min == INT_MAX ? 0: second_min;

    cout << mini + sum - second_min << endl;
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