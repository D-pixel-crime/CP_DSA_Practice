#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

int findMin(vector<pair<int, int>>& arr, vector<vector<vector<int>>>& dp, int i, int j, int k){
    if(i >= arr.size()){
        return 0;
    }
    if(j <= arr[i].second && k <= arr[i].second)return INT_MAX;
    if(dp[i][j][k] != -1)return dp[i][j][k];

    int first = INT_MAX, second = INT_MAX;
    if(j >= arr[i].second){
        int temp = findMin(arr, dp, i + 1, j - arr[i].second, k);
        if(temp != INT_MAX)first = temp + arr[i].first;
    }
    if(k >= arr[i].second){
        int temp = findMin(arr, dp, i + 1, j, k - arr[i].second);
        if(temp != INT_MAX)second = temp - arr[i].first;
    }
    
    if(abs(first) < abs(second)){
        return dp[i][j][k] = first;
    }
    return dp[i][j][k] = second;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, v;
    cin >> n >> v;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(v + 1, vector<int>(v + 1, -1)));

    int ans = findMin(arr, dp, 0, v, v);

    cout << (ans == INT_MAX ? -1 : abs(ans)) << endl;
    
    return 0;
}