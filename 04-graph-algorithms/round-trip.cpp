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
#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const MAXN = 100100

vll in(MAXN, -1);
vll p(MAXN, -1);
vvll ar(MAXN, vll);
vvll ar(MAXN, vll);

ll dfs(ll u, ll t){
    in[u] = t;

    for(auto v:ar[u]){
        if(p[v] == -1){
            p[v] = u;
            in[v] = t;
            t = dfs(u, t+1);
        }
    }

    for()
}

void solve(){
    ll n, m; cin >> n >> m;

    while(m--){
        ll a, b; cin >> a >> b;
        ar[a].pb(b);
        ar[b].pb(a);
    }

    dfs(0, 0);



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
