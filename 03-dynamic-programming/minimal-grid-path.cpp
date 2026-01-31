#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pll pair <ll, ll>
#define fs first
#define sc second
#define vll vector<ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define npll mp((ll)-1,(ll)-1)

#define eb emplace_back

using namespace std;
const ll MOD = 1e9 +7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
    ll n; cin >> n;

    vvll v(n+2, vll (n+2, INF));
    vvpll dp(n+2, vpll (n+2, npll));
    vvpll up(n+2, vpll (n+2, npll));

    int it = (n-1)*2;

    for(int i = 1; n >= i; ++i){
        for(int j = 1; n >= j; ++j){
            char c; cin >> c;
            v[i][j] = (ll)(c-'A');
        }
    }

    for(int i = 1; n >= i; ++i){
        for(int j = 1; n >= j; ++j){
            if(i == n && j == n) continue;

            if(v[i+1][j] < v[i][j+1]){
                dp[i][j] = mp(i+1,j);
            }else if(v[i][j+1] < v[i+1][j]){
                dp[i][j] = mp(i,j+1);
            }
        }
    }

    vpll a(1, mp(1,1));
    vpll b;

    while(it > 0){
        ll mn = INF;

        for(auto k:a){
            mn = min(mn, v[k.fs][k.sc]);
        }

        for(auto k:a){
            if(v[k.fs][k.sc] != mn) continue;
            if(dp[k.fs][k.sc] != npll){
                pll k1 = dp[k.fs][k.sc];
                b.eb(k1);
                up[k1.fs][k1.sc] = k;
            }else{
                pll k1 = mp(k.fs+1, k.sc);
                pll k2 = mp(k.fs, k.sc+1);

                if(n >= k1.fs && n >= k1.sc){
                    b.eb(k1);
                    up[k1.fs][k1.sc] = k;
                }

                if(n >= k2.fs && n >= k2.sc){
                    b.eb(k2);
                    up[k2.fs][k2.sc] = k;
                }
            }
        }
        a = b;
        b = vpll();
        it--;
    }

    pll idx = mp(n,n);
    string resp = "";

    while(idx != mp((ll)1,(ll)1)){
        resp = resp + (char)(v[idx.fs][idx.sc]+'A');
        idx = up[idx.fs][idx.sc];
    }
    resp = resp + (char)(v[1][1]+'A');

    //for(int i = 0; n >= i; ++i){
    //    for(int j = 0; n >= j; ++j){
    //        cout << "[" << up[i][j].fs << "," << up[i][j].sc << "] ";
    //    }cout << endl;
    //}

    reverse(resp.begin(), resp.end());

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
