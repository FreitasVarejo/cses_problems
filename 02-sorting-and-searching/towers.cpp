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
  map<ll, ll> mp;

  while(n--){
    ll x; cin >> x;
    auto ub = mp.upper_bound(x);
    // cout << ub->fs << ' ' << (ub!= mp.end()) << endl;
    mp[x]++;
    if(ub!= mp.end()){
      ll h = ub->fs;
      mp[h]--;
      if(mp[h] == 0) mp.erase(h);
    }
  }

  ll resp = 0; 
  for(auto it = mp.begin(); it != mp.end(); it++) resp += it->sc; 
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
