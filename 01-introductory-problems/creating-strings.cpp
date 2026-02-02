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

vector<string> f(map<char, ll> pv){
  vector<string> resp;

  if(pv.empty()){
    resp.eb(""); 
    return resp;
  }

  for(auto it = pv.begin(); it != pv.end(); it++){
    char c = it->fs;

    map<char, ll> prop = pv;
    prop[c]--;

    if(prop[c] == 0) 
      prop.erase(c);

    vector<string> prop_r = f(prop);

    for(int i = 0; prop_r.size()>i; i++){
      prop_r[i].insert(0, 1, c); 
    }
    resp.insert(resp.end(), prop_r.begin(), prop_r.end());
  }
    
  return resp;
}

void solve(){
  string str; cin >> str;

  map<char, ll> m;
  for(auto c:str) m[c]++;

  vector<string> resp = f(m);

  cout << resp.size() << endl;

  for(auto str:resp) cout << str << endl;
}

int main(){_
  int o = 1;
  //cin >> o;

  while(o--){
      solve();
  }

  return  0;
}
