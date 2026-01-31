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

    vll h(n+1, 0), s(n+1,0);

    for(int i = 0; n > i; ++i){
        cin >> h[i];
    }

    for(int i = 0; n > i; ++i){
        cin >> s[i];
    }


    vll dp(m+1,vll(n+1,0));

    for(int i = 0; n > i; ++i){
        dp[m][i] = 1;
    }

    for(int j = m; j >= 0; --j){
        for(int i = 0; n > i; ++i){
            dp[j][i] = dp[j][i+1];
            if(m >= j+h[i]){
                dp[j][i] = max(dp[j][i], dp[j+h[i]][i]+s[i]);
            }
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
