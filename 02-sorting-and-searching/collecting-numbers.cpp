#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pll pair <ll, ll>
#define fs first
#define sc second
#define vll vector<ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define eb emplace_back
#define fs first
#define sc second
using namespace std;
const ll MOD = 1e9 +7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
  ll n; cin >> n; 
  vll v(n+1, 0);

  for(int i = 1; n >= i; i++){
    ll x; cin >> x;
    v[x] = i;
  }

  ll resp = 1;
  for(int i = 1; n >= i; i++){
    if(v[i] < v[i-1]){
      resp++;
    }
  }

  cout << resp << endl;
}
int main(){_
    int o = 1;
    //cin >> o;

    while(o--){
        solve();
    }

    return  0;
}
