#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)cin >> arr[i];

    sort(all(arr));

    for(auto i: arr){
        cout << i << " ";
    }
    
    return 0;
}
