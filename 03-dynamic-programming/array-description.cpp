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

ll intervalo(ll n, ll m, vll in, vll out){
    vvll dp(n+1, vll(m+1, 0));
    //cout << n << ' ' << m << endl;
    for(auto u:in){
        dp[0][u] = 1;
        //cout << u << ' ';
    }//cout<< endl;
    for(int k = 1; n >= k; k++){
        for(int j = 1; m >= j; ++j){
            dp[k][j] = dp[k-1][j];

            if(j != 1){
                dp[k][j] += dp[k-1][j-1];
                dp[k][j] %= MOD;
            }

            if(j != m){
                dp[k][j] += dp[k-1][j+1];
                dp[k][j] %= MOD;
            }
        }
    }

    ll resp = 0;

    for(auto u:out){
        resp += dp[n][u];
        resp %= MOD;
    //cout << u << ' ';
    }//cout<< endl;

    return resp;
}

void solve(){
    ll n, m; cin >> n >> m;

    vll v(n+1, 0);

    ll f = 1;

    for(int i = 0; n > i; ++i){
        cin >> v[i];
        if(v[i] != 0){
            f = 0;
        }
    }

    for(int i = 0; n > i+1; ++i){
        if(v[i] != 0 && v[i+1] != 0 &&abs(v[i]-v[i+1]) > 1){
            cout << 0 << endl;
            return;
        }
    }

    if(f == 1){
        vll in;
        vll out;
        for(int i = 1; m >= i; ++i){
            in.eb(i);
            out.eb(i);
        }

        cout << intervalo(n-1, m, in, out) << endl;

        return;
    }
    ll resp = 1;
    ll l = 0, r = n-1;

    while(v[l]==0){
        l++;
    }

    if(l != 0){
        vll in;
        vll out;
        in.eb(v[l]);
        for(int i = 1; m >= i; ++i){
            out.eb(i);
        }

        resp *= intervalo(l, m, in, out);
        resp %= MOD;
    }

    while(v[r]==0){
        r--;
    }

    if(r != n-1){
        vll in;
        vll out;
        in.eb(v[r]);
        for(int i = 1; m >= i; ++i){
            out.eb(i);
        }

        resp *= intervalo(n-1-r, m, in, out);
        resp %= MOD;
    }

    ll i = l+1, lst = i-1;

    while(r >= i){
        if(v[i] != 0){
            if(lst != i-1){
                vll in(1, v[lst]);
                vll out(1,v[i]);
                resp *= intervalo(i-lst, m, in, out);
                resp %= MOD;
            }
            lst = i;
        }
        i++;
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
