#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
#define vll vector<ll>

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
  ll resp = 0;
  ll p = 5;
  
  ll n; cin >> n;

  while(n >= p){
    resp += n/p;
    p *= 5;
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
