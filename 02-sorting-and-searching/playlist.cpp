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
  ll n; cin >> n; 
  ll resp = 0;
  ll last = -1;
  map<ll, ll> mp;
    
  for(int i = 0; n > i; i++){
    ll x; cin >> x;
    if(mp.find(x) != mp.end()){
      last = max(last, mp[x]);
    }
    resp = max(resp, i-last);
    mp[x] = i;
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
