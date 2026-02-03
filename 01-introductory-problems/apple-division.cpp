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

void solve(){
  ll n; cin >> n; 
  ll sum = 0;
  vll v(n, 0);

  for(int i = 0; n > i; i++){
    cin >> v[i];
    sum += v[i];
  }

  set <ll> s;
  s.insert(sum);

  for(int i = 0; n > i; i++){
    set<ll> add;
    for(auto u:s) add.insert(u-2*v[i]);
    add.insert(sum-2*v[i]);

    s.insert(add.begin(), add.end());
  }

  cout << min(abs(*s.lower_bound(0)), abs(*s.upper_bound(0))) << endl;
}

int main(){_
  int o = 1;
  //cin >> o;

  while(o--){
      solve();
  }

  return  0;
}
