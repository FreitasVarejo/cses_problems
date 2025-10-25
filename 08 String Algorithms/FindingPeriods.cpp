#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pll pair <ll, ll>
#define fs first
#define sc second
#define vll vector<ll>
#define vpll vector<pll>
#define vvll vector<vll>
#define vvpll vector<vpll>

#define eb emplace_back

using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

vll get_z(string s){
    ll n = s.size();
    vll z(n, 0);

    ll l = 0, r = 0;
    for(ll i = 1; n > i; ++i){
        if(r >= i) z[i] = min(r-i+1,z[i-l]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r) l = i, r = i + z[i] - 1;

    }

    z[0] = n;


    return z;
}

void solve(){
    string s ; cin >> s;

    vll v = get_z(s);

    ll n = s.size();

    for(int i = 1; n > i; ++i){
        if(i == n-v[i]){
            cout << i << ' ';
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
