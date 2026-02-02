#include <bits/stdc++.h>
#define vll vector<ll>
#define fs first
#define sc second
#define eb emplace_back
#define mp make_pair
#define pll pair<ll, ll>
#define vpll vector<pll>
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

vpll f(int n, int ini, int fim){
  int aux = (ini+fim == 3 ? 3 : (ini+fim == 4 ? 2 : 1));

  vpll resp;
  
  if(n > 1){
    vpll v = f(n-1, ini, aux);
    resp.insert(resp.end(), v.begin(), v.end());
  }

  resp.eb(mp(ini, fim));

  if(n > 1){
    vpll v = f(n-1, aux, fim);
    resp.insert(resp.end(), v.begin(), v.end());
  }

  return resp;
}

void solve(){
  ll n; cin >> n; 
  
  vpll resp = f(n, 1, 3);
  
  cout << resp.size() << endl;
  for(auto p:resp){
    cout << p.fs << ' ' << p.sc << endl;
  }
}

int main(){_
  int o = 1;
  //cin >> o;

  while(o--){
      solve();
  }

  return  0;
}
