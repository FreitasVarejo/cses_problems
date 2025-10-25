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

const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
    ll n; cin >> n;
    
    vvll v(n,vll(n, 0));
    vvll vis(n,vll(n, 0));

    queue <pll> q;

    vis[0][0] = 1;

    vector <pll>  dir = {
        mp(1,2),
        mp(1,-2),
        mp(-1,2),
        mp(-1,-2),
        mp(2, 1),
        mp(2, -1),
        mp(-2, 1),
        mp(-2, -1),
    };

    q.push(mp(0,0));
    vis[0][0] == 0;

    while(!q.empty()){
        pll u = q.front();
        q.pop();

        ll u_d = v[u.fs][u.sc];

        for(auto d: dir){
            ll x = u.fs+d.fs;
            ll y = u.sc+d.sc;

            if(n > x && x >= 0 && n > y && y>= 0 && 
            vis[x][y] == 0){
                vis[x][y] = 1;
                v[x][y] = 1 + u_d;
                q.push(mp(x,y));
            }
            
        }
    }

    for(int i = 0; n > i; ++i){
        for(int j = 0; n > j; ++j){
            cout << v[i][j] << ' ';
        }cout<< endl;
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