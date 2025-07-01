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
const ll MX = 1e6 +7;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

ll fast_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

void solve(){
    ll n; cin >> n;

    vll dp(MX, INF);
    vvll p(MX, vll(10, 0));

    dp[0] = 0;

    for(int i = 1; MX >i; ++i){
        ll x = i;
        while(x > 0){
            ll b = x%10;
            x /= 10;
            p[i][b] = 1;
        }

        for(int j = 0; 9 >= j; ++j){
            if(p[i][j])
                dp[i] = min(dp[i], 1+dp[i-j]);
        }
    }

    cout << dp[n] << endl;

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
