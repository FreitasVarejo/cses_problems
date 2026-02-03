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

ll fn(int i, int j){
  return i*8+j;
}

ll fx(int n){
  return n%8;
}

ll fy(int n){
  return n/8;
}

ll fd1(int n){
  return fx(n)+fy(n);
}

ll fd2(int n){
  return (7-n%8)%8+n/8;
}

vll v;
ll sz = 0;

ll f(int x, int r, vll sx, vll sy, vll sd1, vll sd2){
  if(r == 0) return 1;

  if(x >= sz){
    return 0; 
  }

  ll resp = f(x+1, r, sx, sy, sd1, sd2);
  ll h = v[x];
  
  if(sx[fx(h)] && sy[fy(h)] && sd1[fd1(h)] && sd2[fd2(h)]){
    sx[fx(h)] = 0;
    sy[fy(h)] = 0;
    sd1[fd1(h)] = 0;
    sd2[fd2(h)] = 0;
    resp += f(x+1, r-1, sx, sy, sd1, sd2);
  }  

  return resp;
}

void solve(){
  for(int i = 0; 8 > i; i++){
    string str; cin >> str;
    for(int j = 0; 8 > j; j++){
      if(str[j] == '.')
        v.eb(fn(i, j));
    } 
  }

  sz = v.size();

  vll sx(8, 1);
  vll sy(8, 1);
  vll sd1(15, 1);
  vll sd2(15 , 1);

  cout << f(0, 8, sx, sy, sd1, sd2) << endl;
}

int main(){_
  int o = 1;
  //cin >> o;

  while(o--){
      solve();
  }

  return  0;
}
