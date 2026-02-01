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
  ll n, x; cin >> n >> x;
  vpll v;

  for(int i=0;n>i;++i){
    pll x;cin >> x.fs;
    x.sc = i+1;
    v.eb(x);
  }

  sort(v.begin(), v.end());

  ll l = 0, r = n-1;

  while(r>l){
    ll sm = v[l].fs+v[r].fs;
    if(sm > x){
      r--;
    }else if(sm < x){
      l++;
    }else{
      cout << v[l].sc << ' ' << v[r].sc << endl;
      return;
    }
  }

  cout << "IMPOSSIBLE" << endl;

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
