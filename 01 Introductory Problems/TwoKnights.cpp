#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

typedef long long ll;
#define vll vector <ll>
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);


void solve(){
	ll n; cin >> n;
	for(ll i = 1; n >= i ; ++i) cout << (i*i*(i*i-1)/2 - 4*(i-2)*(i-1)) << endl;


}

int main(){_
    int o = 1;
    //cin >> o;

    while(o--){
        solve();
    }

    return  0;
}
