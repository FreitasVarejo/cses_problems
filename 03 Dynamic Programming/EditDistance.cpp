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
    string a, b;
    cin >> a >> b;
    ll n = a.size(), m = b.size();

    vvll dp(n+1,vll(m+1, INF));

    // j = m

    for(int i = 0; n >= i; ++i){
        dp[i][m] = n-i;
    }

    for(int j = m-1; j >= 0; --j){
        for(int i = n; i >= 0;--i){
            dp[i][j] = dp[i][j+1]+1;

            if(i != n){
                dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                dp[i][j] = min(dp[i][j], dp[i+1][j+1]+1);
                if(a[i] == b[j])
                    dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
            }

        }
    }

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
