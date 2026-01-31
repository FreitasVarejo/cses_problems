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
    ll n; cin >> n;

    vvll v(n+1, vll (n+1,0));
    vvll dp(n+1, vll (n+1,0));

    dp[n-1][n] = 1;
    v[n-1][n] = 1;

    for(int i = 0; n > i; ++i){
        for(int j = 0; n > j; ++j){
            char c; cin >> c;

            v[i][j] = ((c=='.')?1:0);
        }
    }

    for(int i = n-1; i >= 0; --i){
        for(int j = n-1; j >= 0; --j){
            if(v[i][j]){
                dp[i][j] += ( ((v[i+1][j]==1)?dp[i+1][j]:0) + ((v[i][j+1]==1)?dp[i][j+1]:0)) % MOD;
            }

        }
    }

    //for(int i = 0; n > i; ++i){
    //    for(int j = 0; n > j; ++j){
    //        cout << dp[i][j] << ' ';
    //    }cout << endl;
    //}

    cout << dp[0][0] << endl;

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
