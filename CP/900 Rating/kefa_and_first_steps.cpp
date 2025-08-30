#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i  < n; i++)cin >> arr[i];

    int ans = 1;
    int i = 0;
    while(i < n){
        int j = i + 1;
        while(j < n and arr[j] >= arr[j - 1]){
            j++;
        }
        ans = max(ans, j - i);
        i = j;
    }

    cout << ans;
    
    return 0;
}