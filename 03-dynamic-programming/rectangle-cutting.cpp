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
    ll n, m; cin >> n >> m;

    ll k = max(n, m);

    vvll dp(k+1, vll(k+1, INF));

    for(ll i = 1; k >= i; ++i){
        dp[i][i] = 0;
    }

    for(int i = 1; k >= i; ++i){
        for(int j = i+1; k >= j; ++j){
            for(int h = 1; j > h; ++h){
                ll a = min(h, i), b = max(h, i);
                ll c = j-h;
                dp[i][j] = dp[a][b]*(a != b)+dp[min(a,c)][max(a,c)]*(a != c);
            }
            //cout << dp[i][j] << ' ';
        }//cout<< endl;
    }

    if(m < n) swap(n, m);

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
