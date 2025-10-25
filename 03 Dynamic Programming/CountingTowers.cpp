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



void solve(){
    ll t; cin >> t;

    vvll dp(1e6+4, vll (2, 0));

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; 1e6+4 > i; ++i){
        dp[i][0] = dp[i-1][0]*2+dp[i-1][1];
        dp[i][0] %= MOD;

        dp[i][1] = dp[i-1][0]*1+dp[i-1][1]*4;
        dp[i][1] %= MOD;
    }

    while(t--){
        ll x; cin >> x;
        cout << (dp[x][0]+dp[x][1])%MOD << endl;
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
