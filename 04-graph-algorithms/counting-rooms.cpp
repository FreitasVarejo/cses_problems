#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pll pair <ll, ll>
#define fs first
#define sc second
#define vll vector<ll>
#define vpll vector<pll>
#define vvll vector<vll>

#define eb emplace_back

using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
    ll n, m; cin >> n >> m;

    vvll w (n, (vll (m, 0)));
    vvll vis (n, (vll (m, 0)));

    for(int i = 0; n > i; ++i){
        string str; cin >> str;
        for(int j = 0; m > j; ++j){
            char c = str[j];
            if(c == '#'){
                w[i][j] = 1;
            }
        }
    }

    ll resp = 0;

    for(int i = 0; n > i; ++i){
        for(int j = 0; m > j; ++j){
            if(w[i][j] == 0 && vis[i][j] == 0){
                resp++;

                queue <pll> q;

                vis[i][j] = 1;
                q.push(mp(i,j));

                while(!q.empty()){
                    auto [a, b] = q.front();
                    q.pop();

                    vpll dir= {mp(a+1,b),
                            mp(a-1,b),
                            mp(a,b+1),
                            mp(a,b-1)};

                    for(auto [ar, br]:dir){
                        if(n >ar && ar >= 0 &&
                        m > br && br >= 0 &&
                        vis[ar][br] == 0 &&
                        w[ar][br] == 0){
                            vis[ar][br] = 1;
                            q.push(mp(ar,br));
                        }
                    }
                }
            }
        }
    }

    cout << resp << endl;

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
