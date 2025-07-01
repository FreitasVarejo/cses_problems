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
    ll n,s ; cin >> n >> s;

    vll dp(s+1, 0);
    vll v(n, 0);

    dp[s] = 1;

    for(int i = 0; n >i; ++i){
        cin >> v[i];
    }

    for(int j = s-1; j >= 0; --j){
        for(int i = 0; n > i; ++i){
            ll x = j+v[i];
            if(s >= x){
                dp[j] = (dp[j]+dp[x])%MOD;
            }
        }
    }

    cout << dp[0]<< endl;

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
