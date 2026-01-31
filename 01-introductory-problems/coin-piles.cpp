#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
#define vll vector<ll>

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
  ll a, b; cin >> a >> b;

  if(b > a) swap(a, b);

  ll x = a-b, y = b;

  if(y-x>=0 && (y-x)%3 == 0) cout << "YES"  << endl;
  else cout << "NO" << endl;
}

int main(){_
  int o = 1;
  cin >> o;

  while(o--){
      solve();
  }

  return  0;
}
