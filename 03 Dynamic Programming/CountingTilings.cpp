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

inline ll addmod(ll a, ll b, ll mod = MOD) {
    return ( (a % mod) + (b % mod) + mod ) % mod;
}

inline ll submod(ll a, ll b, ll mod = MOD) {
    return ( (a % mod) - (b % mod) + mod ) % mod;
}

inline ll mulmod(ll a, ll b, ll mod = MOD) {
    return ( (a % mod) * (b % mod) ) % mod;
}

ll expmod(ll a, ll e, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while (e > 0) {
        if (e & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return res;
}

// Inverso modular (válido se mod é primo)
ll invmod(ll a, ll mod = MOD) {
    return expmod(a, mod - 2, mod);
}

inline ll divmod(ll a, ll b, ll mod = MOD) {
    return mulmod(a, invmod(b, mod), mod);
}

void solve(){
    ll n,m; cin >> n >> m;

    vvll dpa(n+1, vll(m+1, 0));
    vvll dpb(n+1, vll(m+1, 0));
    vvll dpc(n+1, vll(m+1, 0));
    vvll dpd(n+1, vll(m+1, 0));

    if(n > 1) dp[2][1] = 1;
    if(m > 1) dp[1][2] = 1;

    for(int i = 0; n >= i; ++i) dp[i][0] = 1;
    for(int j = 0; m >= j; ++j) dp[0][j] = 1;

    for(int i = 1; n >= i; ++i){
        for(int j = 1; m >= j; ++j){
            if(3 >= i + j) continue;

            dp[i][j] = 0;

            if(j-2 >= 0){
                ll x = dp[i][j-2] * dp[i-1][j];
                x %= MOD;
                x = divmod(x, dp[i-1][j-2]);

                dp[i][j] += x;
                dp[i][j] %= MOD;
            }

            if(i-2 >= 0){
                ll x = dp[i-2][j] * dp[i][j-1];
                x %= MOD;
                x = divmod(x, dp[i-2][j-1]);

                dp[i][j] += x;
                dp[i][j] %= MOD;
            }
        }
    }

    for(int i = 1; n >= i; ++i){
        for(int j = 1; m >= j; ++j){
            cout << dp[i][j] << ' ';
        }cout << endl;
    }



    cout << dp[n][m] << endl;

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
