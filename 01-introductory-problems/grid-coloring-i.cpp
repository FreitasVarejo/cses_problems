#include <bits/stdc++.h>
#define vll vector<ll>
#define vvll vector<vll>
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
 
void solve(){
  ll n, m; cin >> n >> m;
  vvll v(n, vll(m, 0));

  for(int i = 0; n > i; ++i){
    string str; cin >> str;
    for(int j = 0; m > j; ++j){
      set<ll> s;
      for(int k = 0; 4 > k; k++) s.insert(k);

      s.erase((int)(str[j]-'A'));
      if(i > 0) s.erase(v[i-1][j]);
      if(j > 0) s.erase(v[i][j-1]);

      v[i][j] = *s.begin();
    }
  }

  for(int i = 0; n > i; ++i){
    for(int j = 0; m > j; ++j) cout << (char)('A'+v[i][j]);
    cout << endl;
  }
}
 
int main(){_
  int o = 1;
  // cin >> o;
 
  while(o--){
      solve();
  }
 
  return  0;
}

