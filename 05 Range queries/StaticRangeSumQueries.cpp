#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pll pair <ll, ll>
#define fs first
#define sc second
#define vll vector<ll>
#define vpll vector<pll>
#define vvll vector<vll>
#define vvpll vector<vpll>

#define eb emplace_back

using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
    ll n,q; cin >> n >> q;

    vll v(n+1, 0);
    vll sm(n+1, 0);

    for(int i = 1; n >= i; ++i) cin >> v[i];
    for(int i = 1; n >= i; ++i) sm[i] = sm[i-1]+v[i];

    while(q--){
        ll a, b; cin >> a >> b;
        cout << sm[b]-sm[a-1] << endl;
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
