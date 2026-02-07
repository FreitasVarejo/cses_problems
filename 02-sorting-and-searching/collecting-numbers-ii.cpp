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
  ll n, q; cin >> n >> q;
  
  vll v(n+2, 0);
  vll pos(n+1, 0);
  v[0] = 0, v[n+1] = n+1;
  for(int i = 1; n >= i; i++){
    ll x; cin >> x; 
    v[x] = i;
    pos[i] =  x;
  }
  
  ll resp = 0;  
  for(int i = 1; n >= i; i++){ 
    resp += (v[i]<v[i+1] ? 0 : 1);
    resp += (v[i]>v[i-1] ? 0 : 1);
  } 

  cout << resp << endl;
  
  while(q--){
    ll ai, bi; cin >> ai >> bi;
    ll a = pos[ai], b = pos[bi]; 

    resp -= (v[a]<v[a+1] ? 0 : 1);
    resp -= (v[a]>v[a-1] ? 0 : 1);
    resp -= (v[b]<v[b+1] ? 0 : 1);
    resp -= (v[b]>v[b-1] ? 0 : 1);

    swap(pos[ai], pos[bi]);
    swap(v[a], v[b]);
    
    resp += (v[a]<v[a+1] ? 0 : 1);
    resp += (v[a]>v[a-1] ? 0 : 1);
    resp += (v[b]<v[b+1] ? 0 : 1);
    resp += (v[b]>v[b-1] ? 0 : 1);

    cout << resp << endl;
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
