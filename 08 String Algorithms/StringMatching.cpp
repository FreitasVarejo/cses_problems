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
    string k; cin >> k;

    using H = str_hash<1000000007>;
    H sh(s), kh(k);

    ll val = kh(0, k.size()-1);

    ll resp = 0;

    for(int i = 0; s.size() > i+k.size()-1; ++i){
        if(sh(i, i+k.size()-1) == val){
            resp++;
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
