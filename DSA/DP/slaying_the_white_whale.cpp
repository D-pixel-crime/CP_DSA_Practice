#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

int findMin(vector<vector<int>>& arr, vector<vector<int>>& dp, int i, int j){
    if(j <= 0)return 0;
    if(i >= arr.size()){
        return INT_MAX;
    }
    if(dp[i][j] != -1)return dp[i][j];

    int dont = findMin(arr, dp, i + 1, j);
    int take = INT_MAX;
    int temp = findMin(arr, dp, i, j - arr[i][0]);
    if(temp != INT_MAX){
        take = temp + arr[i][2];
    }

    return dp[i][j] = min(dont, take);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, d;
    cin >> n >> d;

    vector<vector<int>> arr(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        d -= (arr[i][0] * arr[i][1]);
    }

    if(d <= 0){
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(d + 1, -1));
    int ans = findMin(arr, dp, 0, d);
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    
    return 0;
}