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

struct Compare {
    bool operator()(const pll &a, const pll &b) const{
        if(a.sc != b.sc){
            return  a.sc > b.sc;
        }
        return a.fs > b.fs;
    }
}

void solve(){
    ll n, m; cin >> n >>m;

    vvpll ar(n, vpll (0,mp(0,0)));
    while(m--){
        ll a,b,w; cin >> a >> b >> w;
        a--,b--;
        ar[a].eb(mp(b,w));
        ar[b].eb(mp(a,w));
    }

    prioirty_queue <pll, vpll, Compare> pq;
    vll vis(n, 0);
    vll d(n, INF);

    vis[0] = 1;
    d[0] = 0;

    pq.push({0, 0});

    while(!pq.empty()){
        auto [a,b] pq.front();
        pq.pop();

        for(auto [a,b]:ar)
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
