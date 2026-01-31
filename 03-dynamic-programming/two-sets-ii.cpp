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

ll mod_pow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll mod_inv(ll a, ll mod = MOD) {
    // MOD precisa ser primo
    return mod_pow(a, mod - 2, mod);
}

ll mod_div(ll a, ll b, ll mod = MOD) {
    return (a % mod * mod_inv(b, mod)) % mod;
}


void solve(){
    ll n; cin >> n;

    if((n*(n+1))%4 != 0){
        cout << 0 << endl;
        return;
    }

    ll m = (n*(n+1))/4;

    vvll dp(n+1, vll(m+1,0));

    for(int i = 0; n >= i; ++i){
        dp[i][0] = 1;
    }

    for(int i = 1; n >= i; ++i){
        for(int j = m; j >= 0; --j){
            dp[i][j] = dp[i-1][j];
            if(j >= i){
                dp[i][j] += dp[i-1][j-i];
            }
            dp[i][j] %= MOD;
        }
    }

    //for(int i = 0; n >= i; ++i){
    //   for(int j = 0; m >= j; ++j){
    //        cout << dp[i][j] << ' ';
    //    }cout << endl;
    ///}

    cout << mod_div(dp[n][m], 2) << endl;

}

int main(){_
    int o = 1;
    //cin >> o;

    while(o--){
        solve();
    }

    return  0;
}
