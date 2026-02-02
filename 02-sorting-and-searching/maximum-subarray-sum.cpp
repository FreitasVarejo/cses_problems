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
  vll v(n, 0);

  for(int i = 0; n > i; ++i) cin >> v[i];

  ll resp = v[0], sm = max(v[0], (ll)0);

  for(int i = 1; n > i; i++){
    sm += v[i];
    resp = max(resp, sm);
    sm = max(sm, (ll)0);
  }

  cout << resp << endl;
  return;
}

int main(){_
    int o = 1;
    //cin >> o;

    while(o--){
        solve();
    }

    return  0;
}
