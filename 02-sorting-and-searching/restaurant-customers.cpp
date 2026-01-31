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
  vpll v;
  map <ll, ll> mp; 

  for(int i = 0; n > i; ++i){
    pll p; cin >> p.fs >> p.sc;
    mp[p.fs]++, mp[p.sc]++;
    v.eb(p);
  }

  ll sz = 0;
  for(auto it = mp.begin(); it != mp.end(); it++){
    it->sc = sz;
    sz++;
  }

  vll h(sz, 0);

  for(auto p:v){
    h[mp[p.fs]]++;
    h[mp[p.sc]]--;
  }  
  
  ll resp = 0, x = 0;

  for(int i = 0; sz > i; i++){
    x += h[i];
    resp = max(resp, x);
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
