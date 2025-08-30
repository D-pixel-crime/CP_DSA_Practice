#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  ll temp;
  cin >> temp;
  ll maxi, a, b, mini, total = 0;
  a = maxi = mini = b = total = temp;
  
  for(int i = 1; i < n; i++){
    cin >> temp;
    total += temp;
    maxi = max(maxi + temp, temp);
    mini = min(mini + temp, temp);
    b = min(b, mini);
    a = max(a, maxi);
  }
  
  if(a < 0)cout << a << endl;
  else cout << max(a, total - b) << endl;
  
  return 0;
}