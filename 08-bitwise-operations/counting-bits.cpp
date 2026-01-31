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
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
    ll n; cin >> n;

    ll d[64];

    d[0] = 0;
    d[1] = 1;

    ll resp = 0;

    for(int i = 2; 64 > i; ++i){
        d[i] =
    }


    while(n > 0){
        resp += (n&1);
        n = (n>>1);
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
