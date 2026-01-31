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

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash {
	static int P;
	vector<ll> h, p;
	str_hash(string s) : h(s.size()), p(s.size()+1) {
        int n = (int)s.size();
        if (n == 0) { p[0] = 1; return; }
        p[0] = 1;
        h[0] = (unsigned char)s[0] % MOD;
        for (int i = 1; i < n; i++) {
            p[i] = (p[i - 1] * (ll)P) % MOD;
            h[i] = (h[i - 1] * (ll)P + (unsigned char)s[i]) % MOD;
        }
        p[n] = (p[n - 1] * (ll)P) % MOD; // garante acesso a p[n]
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]
        if (l == 0) return h[r];
        ll res = h[r] - (h[l - 1] * p[r - l + 1]) % MOD;
        if (res < 0) res += MOD;
        return res;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1); // l > |sigma|

void solve(){
    string s ; cin >> s;
    ll n = s.size();

    ll mod = 1e9 + 7;

    using H = str_hash<1000000007>;
    H sh(s);

    ll m ; cin >> m;

    map<ll, vector<ll>> mp;

    for(int i = 0; m > i; ++i){
        string x; cin >> x;

        H xh(x);
        ll xn = x.size();
        ll xhash = xh(0, xn-1);

        mp[xhash].eb(xn);
    }

    vll dp(n+1, 0);
    dp[n] = 1;

    for(int k = 1; n >= k; ++k){
        for(int i = n-1; i-(k-1) >= 0; --i){
            ll shash = sh(i-(k-1), i);
            if(mp.find(shash) != mp.end()){
                for(auto u:mp[shash]){
                    
                }
            }
        }
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
