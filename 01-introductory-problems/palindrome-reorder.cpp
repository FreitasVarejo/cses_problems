#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
#define vll vector<ll>

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
  string str; cin >> str;  
  vll v(26, 0);

  for(auto c:str){
    v[(int)(c-'A')]++;
  }

  ll imp = -1;

  for(int i=0; 26 > i; i++){
    if(v[i]%2 == 1){
      if(imp != -1){
        cout << "NO SOLUTION" << endl;
        return;
      } 
      imp = i;
    }
  }
  
  string resp = (imp==-1) ? "" : string(v[imp], (char)('A'+imp));

  for(int i=0; 26>i; i++){
    if(i != imp){
      string add = string(v[i]/2, (char)('A'+i));
      resp = add+resp+add;
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
