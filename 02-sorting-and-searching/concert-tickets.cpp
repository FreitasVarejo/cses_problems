#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pll pair <ll, ll>
#define fs first
#define sc second
#define vll vector<ll>
#define vvll vector<vll>

#define eb emplace_back

using namespace std;
const ll MOD = 1e9 +7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

int bb(ll x, vll& v){
    ll l = 0, r = v.size()-1;

    while(r-1>l){
        ll meio = (r+l)/2;

	if(x >= v[meio]){
	    l = meio;
	}else{
	    r = meio-1;
	}
    }

    if(x >= v[r]) return r;

    return l;
}

void solve(){
    ll n, m; cin >> n >> m;

    vll v(n, 0);
    for(int i = 0; n > i; i++) cin >> v[i];
    
    sort(v.begin(), v.end());

    while(m--){
	   ll x; cin >> x;
	   if(x < v[0]){
		   cout << -1 <<endl; 
		   continue;
	}  
	   int idx = bb(x, v);
	   cout << v[idx] << endl;
	   v.erase(v.begin()+idx); 
			   
	     
    } 
    return;
}

int main(){_
    int o = 1;
    //cin >> o;

    while(o--){
        solve();
    }

    return  0;
}
