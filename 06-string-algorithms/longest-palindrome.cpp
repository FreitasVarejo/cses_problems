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
	vector<ll> h, p, psum;
	str_hash(string s) : h(s.size()), p(s.size()+1), psum(s.size()+1) {
        int n = (int)s.size();
        if (n == 0) { p[0] = 1; return; }
        p[0] = 1;
        psum[0] = 0;
        h[0] = (unsigned char)s[0] % MOD;
        for (int i = 1; i < n; i++) {
            p[i] = (p[i - 1] * (ll)P) % MOD;
            psum[i] = (p[i]+psum[i-1]) % MOD;
            h[i] = (h[i - 1] * (ll)P + (unsigned char)s[i]) % MOD;
        }
        p[n] = (p[n - 1] * (ll)P) % MOD; // garante acesso a p[n]
        psum[n] = (p[n]+psum[n-1]) % MOD;
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]
        if (l == 0) return h[r];
        ll res = h[r] - (h[l - 1] * p[r - l + 1]) % MOD;
        if (res < 0) res += MOD;
        return res;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1); // l > |sigma|


ll modpow(ll a, long long e, ll mod) {
    a %= mod;
    if (a < 0) a += mod;
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

ll modinv(ll x, ll mod) {
    return modpow(x, mod - 2, mod);
}

ll modexp_exp(ll a, ll b, ll c, ll mod) {
    // supõe que mod é primo
    ll e = modpow(b, c, mod - 1); // reduz expoente com Fermat
    return modpow(a, e, mod);
}

void solve(){
    string s ; cin >> s;
    ll n = s.size();
    map <char, vector<int>> mp;

    for(int i = 0 ; n > i; ++i){
        if(mp.find(s[i]) == mp.end()){
            mp[s[i]] = vector<int>();
        }
        mp[s[i]].eb(i);
    }

    string sr = s;
    reverse(sr.begin(), sr.end());

    ll mod = 1000000007;

    using H = str_hash<1000000007>;
    H sh(s), shr(sr);

    int l = 0, r = 0;

    // par
    int esq = 0, dir = n/2;

    while(dir > esq){
        ll meio = (esq+dir)/2;
        ll t = meio*2;
        for(int i = 0; n > i+t-1; ++i){
            if(sh(i,i+t-1) == shr((n-1)-i-(t-1),(n-1)-i)){
                if(t > r-l+1){
                    l = i;
                    r = i+t-1;
                }
                esq = meio;
                break;
            }
        }

        if(meio != esq){
            dir = meio-1;
        }else if(dir == esq+1){
            t = dir*2;
            for(int i = 0; n > i+t-1; ++i){
                if(sh(i,i+t-1) == shr((n-1)-i-(t-1),(n-1)-i)){
                    if(t > r-l+1){
                        l = i;
                        r = i+t-1;
                    }
                    esq = dir;
                    break;
                }

            }
            dir = esq;
        }
    }

    // impar
    esq = 0, dir = n/2+1;

    while(dir > esq){
        ll meio = (esq+dir)/2;
        ll t = 1+meio*2;
        for(int i = 0; n > i+t-1; ++i){
            if(sh(i,i+t-1) == shr((n-1)-i-(t-1),(n-1)-i)){
                if(t > r-l+1){
                    l = i;
                    r = i+t-1;
                }
                esq = meio;
                break;
            }
        }

        if(meio != esq){
            dir = meio-1;
        }else if(dir == esq+1){
            t = dir*2+1;
            for(int i = 0; n > i+t-1; ++i){
                if(sh(i,i+t-1) == shr((n-1)-i-(t-1),(n-1)-i)){
                    if(t > r-l+1){
                        l = i;
                        r = i+t-1;
                    }
                    esq = dir;
                    break;
                }

            }
            dir = esq;
        }
    }

    cout << s.substr(l,r-l+1) << endl;

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
