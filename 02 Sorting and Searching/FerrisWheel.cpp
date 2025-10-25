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

    vll v(n, 0);

    for(int i = 0; n > i; ++i){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ll resp = 0;
    ll i = 0, j = n-1;

    while(j > i){
        if(v[i]+v[j] <= m){
            resp++;
            i++;
            j--;
        }else{
            resp++;
            j--;
        }
    }

    resp += (i == j);

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
