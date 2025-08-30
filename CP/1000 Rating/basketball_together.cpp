#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, d;
    cin >> n >> d;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)cin >> arr[i];

    sort(all(arr), [](const auto& a, const auto& b){
        return a > b;
    });

    int i = 0, count = n;
    while(i < n){
        int needed = (d / arr[i]) + 1;
        if(needed > count){
            cout << i << endl;
            return 0;
        }
        count -= needed;
        i++;
    }

    cout << i << endl;
    
    return 0;
}