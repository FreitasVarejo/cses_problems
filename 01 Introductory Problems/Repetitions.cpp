#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
    string s ; cin >> s;

    ll resp = 1, x = 1;

    for(int i = 1; s.size() > i; ++i){
        if(s[i] != s[i-1])
            x   = 1;
        else
            x++;
        resp = max(resp, x);
    }

    cout << resp <<endl;
}

int main(){_
    int o = 1;
    //cin >> o;

    while(o--){
        solve();
    }

    return  0;
}
