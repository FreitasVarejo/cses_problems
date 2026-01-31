#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
    ll n; cin >> n;
    
    vector <ll> v;

    for(int i = 1; n > i; ++i){
        ll x; cin >> x;
        v.eb(x);
    }

    v.eb(0);

    sort(v.begin(), v.end());

    for(int i = 1; v.size() > i; ++i){
        if(v[i] != v[i-1]+1){
            cout << i << endl;
            return;
        }
    }   

    cout << n << endl;
    
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