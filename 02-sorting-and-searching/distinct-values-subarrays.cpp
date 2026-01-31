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
    
    ll id = 0;
    map <ll, ll> mp;
    vll v;

    for(int i = 0; n > i; ++i){
        ll x; cin >> x;

        if(mp.find(x) == mp.end()){
            mp[x] = id;
            id++;
        }
        v.eb(mp[x]);
    }


    vll last(id+2, 0);

    ll resp = 0;

    for(int i = 0; n > i; ++i){
        ll x = v[i];
        resp += (1<<(i -last[x]));
        last[x] += 1;
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