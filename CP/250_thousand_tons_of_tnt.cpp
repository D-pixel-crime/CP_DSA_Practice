#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

vector<int> findDivisors(int &n)
{
    if(n == 1){
        return {1};
    }

    vector<int> ans;
    ans.push_back(1);
    ans.push_back(n);

    int end = sqrt(n) + 1;

    for(int i = 2; i <= end; i++){
        if(n % i == 0){
            int temp = n / i;
            ans.push_back(i);
            if(temp != i){
                ans.push_back(temp);
            }
        }
    }

    return ans;
}

ll ways(vector<ll>& arr, vector<ll>& pre, int div){
    int i = 0;
    ll maxi = LLONG_MIN, mini = LLONG_MAX;
    ll ans = LLONG_MIN;
    while(i < pre.size()){
        int j = i + div - 1;
        ll sum = pre[j] - pre[i] + arr[i];
        maxi = max(maxi, sum);
        mini = min(mini, sum);

        ans = max(ans, maxi - mini);
        i += div;
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    vector<ll> pre(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pre[i] = i - 1 >= 0 ? pre[i - 1] + arr[i] : arr[i];
    }

    vector<int> divisors = findDivisors(n);

    ll ans = 0;
    for(auto i: divisors){
        ans = max(ans, ways(arr, pre, i));
    }

    cout << ans << endl;
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