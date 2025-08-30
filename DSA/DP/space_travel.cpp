#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(ll i = a; i < b; i++)

ll f;

ll findMax(vector<vector<ll>>& arr, vector<vector<ll>>& dp, ll i, ll j){
    if(i >= arr.size()){
        return 0;
    }
    if(j * arr[i][0] > f)return LLONG_MIN;
    if(dp[i][j] != -1)return dp[i][j];

    ll dont = findMax(arr, dp, i + 1, j);
    ll take = LLONG_MIN;
    if(arr[i][0] * (j + arr[i][1]) <= f){
        ll temp = findMax(arr, dp, i + 1, j + arr[i][1]);
        if(temp != LLONG_MIN){
            take = temp + arr[i][2];
        }
    }

    return dp[i][j] = max(dont, take);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    ll n;
    cin >> n >> f;

    ll sum = 0;

    vector<vector<ll>> arr(n, vector<ll>(3));
    for(ll i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        sum += arr[i][1];
    }

    vector<vector<ll>> dp(n, vector<ll>(sum + 1, -1));

    ll ans = findMax(arr, dp, 0, 0);
    cout << (ans == LLONG_MIN ? -1 : ans) << endl;
    
    return 0;
}