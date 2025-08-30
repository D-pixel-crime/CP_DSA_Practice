#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;

    int repete = (int)ceil((double)n / 5.0);
    int needed = n % 5;
    int remainingRepete = n / 5;


    vector<char> arr = {'a', 'e', 'i', 'o', 'u'};
    int i = 0, j = 0;
    while(j < needed && i < 5){
        for(int k = 0; k < repete; k++){
            cout << arr[i];
        }
        j++; i++;
    }

    j = 0;
    while(j < n - needed && i < 5){
        for(int k = 0; k < remainingRepete; k++){
            cout << arr[i];
        }
        j++, i++;
    }

    cout << endl;
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