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
  ll n, a, b; cin >> n >> a >> b;
  ll rv = 0;
  if(b < a){
    rv = 1;
    swap(a, b);
  }

  ll h = b-a;
  ll x = (a != b ? a-1 : a );

  if((a != b && b > 0 && a == 0) 
    || n < (a != b ? 2+h : 0) + 2*x ){
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;

  vll v1(n+1, 0);
  vll v2(n+1, 0);

  for(int i = 1; n >= i; i++) v1[i] = i, v2[i] = i;

  int idx = 1;
  if(a != b){
    idx = h+2+1;
    v2[1] = h+2;
    for(int i = 2; h+2 >= i; i++) v2[i] = i-1;
  }

  while(x >= 1){
    swap(v2[idx], v2[idx+1]);
    x--, idx += 2;
  } 

  if(!rv) swap(v1, v2);

  for(int i = 1; n >= i; i++) cout << v1[i] << ' ';
  cout << endl;
  for(int i = 1; n >= i; i++) cout << v2[i] << ' ';
  cout << endl;
}

int main(){_
  int o = 1;
  cin >> o;

  while(o--){
      solve();
  }

  return  0;
}
