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

    vll v (n+1, 0);

   v[n]= 1;

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; 5 >= j; ++j){
            if(n >= i+j+1){
                v[i] = (v[i] + v[i+j+1])%MOD;
            }
        }
    }

    cout << v[0] << endl;

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
