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
    ll n, m; cin >> n >> m;

    vvll w (n, (vll (m, 0)));
    vvll vis (n, (vll (m, 0)));
    vvpll last (n, (vpll (m, mp(-1,-1))));

    pll a, b;

    for(int i = 0; n > i; ++i){
        string str; cin >> str;
        for(int j = 0; m > j; ++j){
            char c = str[j];
            if(c == '#'){
                w[i][j] = 1;
            }else if(c == 'A'){
                a = mp(i,j);
            }else if(c == 'B'){
                b = mp(i,j);
            }
        }
    }

    queue <pll> q;
    q.push(a);
    vis[a.fs][a.sc] = 1;


    while(!q.empty()){
        pll u = q.front();
        q.pop();

        vpll dir = {
            mp(u.fs+1, u.sc),
            mp(u.fs-1, u.sc),
            mp(u.fs, u.sc+1),
            mp(u.fs, u.sc-1)
        };

        for(auto [x,y]:dir){
            if(n > x && x >= 0 &&
            m > y && y >= 0 &&
            vis[x][y] == 0 && w[x][y] == 0){
                q.push(mp(x, y));
                vis[x][y] = 1;
                last[x][y] = mp(u.fs, u.sc);
            }
        }
    }

    if(vis[b.fs][b.sc] == 1){
        string str = "";
        pll u = b;

        while(u != a){
            pll l = last[u.fs][u.sc];

            if(l.fs == u.fs+1 && l.sc == u.sc){
                str += "U";
            }else if(l.fs == u.fs-1 && l.sc == u.sc){
                str += "D";
            }
            else if(l.fs == u.fs && l.sc == u.sc+1){
                str += "L";
            }
            else if(l.fs == u.fs && l.sc == u.sc-1){
                str += "R";
            }

            u = l;
        }

        reverse(str.begin(), str.end());

        cout << "YES" << endl;
        cout << str.length() << endl;
        cout << str << endl;
    }else{
        cout << "NO" << endl;
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
