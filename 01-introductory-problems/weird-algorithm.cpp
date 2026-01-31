#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
    ll n; cin >> n;

    while(n != 1){
        cout << n << ' ';

        if((n&1) == 1){
            n = n*3+1;
        }else{
            n = (n>>1);
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