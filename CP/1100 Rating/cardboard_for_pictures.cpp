#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

int possible(vector<ll>& arr, ll& mid, ll& c){
    __int128 sum = 0;

    for(auto i: arr){
        __int128 temp = ((__int128)i + 2 * mid) * ((__int128)i + 2 * mid);
        if(sum > (__int128)c - temp){
            return 1;
        }
        sum += temp;
    }

    if(sum == c){
        return 0;
    }
    if(sum < c){
        return -1;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;

    ll c;
    cin >> c;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ll start = 1, end = sqrt(c) / 2 + 1;

    while(start <= end){
        ll mid = start + (end - start) / 2;
        int temp = possible(arr, mid, c);
        if(temp == 0){
            cout << mid << endl;
            return;
        }else if(temp == -1){
            start = mid + 1;
        }else end = mid - 1;
    }
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