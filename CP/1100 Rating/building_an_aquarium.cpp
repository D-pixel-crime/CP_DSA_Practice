#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

int isPossible(vector<ll>& arr, ll& mid, ll& x){
    ll total = 0;
    for(auto i: arr){
        ll curr = max(0LL, mid - i);
        if(total > x - curr){
            return -1;
        }
        total += curr;
    }

    if(total <= x){
        return 1;
    }
    return -1;
}

void solve() {
    int n;
    cin >> n;

    ll x;
    cin >> x;

    ll start = LLONG_MAX, end = x + 1;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        start = min(start, arr[i]);
    }

    end = start + x + 1;

    while(start + 1 < end){
        ll mid = start + (end - start) / 2;
        if(isPossible(arr, mid, x) == 1){
            start = mid;
        }else end = mid;
    }

    cout << start << endl;
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