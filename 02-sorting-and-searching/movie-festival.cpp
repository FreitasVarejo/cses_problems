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
  vpll v;
  map<ll, ll> mp;

  ll n; cin >> n;

  for(int i=0; n>i; i++){
    pll x; cin >> x.fs >> x.sc;
    v.eb(x);
    mp[x.fs]++, mp[x.sc]++;
  }

  ll sz=1;
  for(auto it=mp.begin(); it!=mp.end(); it++, sz++) 
    it->sc = sz;
  sz--;

  for(int i=0; n>i; i++){
    v[i].fs = mp[v[i].fs];
    v[i].sc = mp[v[i].sc];
  }

  vll fim(sz+1, -1);

  for(int i=0; n>i; i++){
    fim[v[i].sc] = max(fim[v[i].sc], v[i].fs);
  }

  vll resp(sz+1, 0);

  for(int i=1; sz>=i; i++){
    resp[i] = resp[i-1];
    if(fim[i]!=-1){
      resp[i] = max(resp[i], 1+resp[fim[i]]);
    }
  }

  cout << resp[sz] << endl;

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
