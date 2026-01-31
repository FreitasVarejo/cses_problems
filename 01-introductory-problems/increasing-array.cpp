#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
    ll n; cin >> n;
    ll x, past;

    cin >> past;

    ll resp = 0;

    for(int i = 1; n > i; ++i){
        cin >> x;
        resp += max((ll)0, past-x);
        past = max(past,x);
    }

    cout << resp << endl;
}

int main(){_
    int o = 1;
    //cin >> o;

    while(o--){
        solve();
    }

    return  0;
}
