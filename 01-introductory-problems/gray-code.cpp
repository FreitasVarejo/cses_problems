#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
#define vll vector<ll>

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
  ll n; cin >> n;
  vector <string> v;

  v.eb("0"); 
  v.eb("1");
  n--;
  while(n--){
    vector <string> tmp;

    for(int i=0; v.size()>i; i++){
      tmp.eb("0"+v[i]);
    }

    for(int i=v.size()-1; i>=0; i--){
      tmp.eb("1"+v[i]);
    }

    swap(v, tmp);
  }

  for(auto s:v){
    cout << s << endl;
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
