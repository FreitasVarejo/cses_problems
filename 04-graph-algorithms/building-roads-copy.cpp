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
    ll n, m; cin >> n >>m;

    vvll ar(n, vll (0,0));
    vll vis(n,-1);
    vll rep(n,-1);

    while(m--){
        ll a,b; cin >> a >> b;
        a--,b--;
        ar[a].eb(b);
        ar[b].eb(a);
    }

    ll c = 0;

    for(int i = 0; n > i; ++i){
        if(vis[i] == -1){
            queue <ll> q;
            q.push(i);
            vis[i] = c;
            rep[c] = i+1;


            while(!q.empty()){
                ll u = q.front();
                q.pop();

                for(auto v:ar[u]){
                    if(vis[v] == -1){
                        q.push(v);
                        vis[v] = c;
                    }
                }
            }
            c++;
        }
    }

    cout << c-1 << endl;
    for(int i = 0; c-1 > i; ++i){
        cout << rep[i] << ' ' << rep[i+1]<< endl;
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
