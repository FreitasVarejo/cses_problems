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
    ll n, m, k; cin >> n >> m >> k;

    vll a(n,0), b(m,0);

    for(int i = 0; n > i; ++i){
        cin >> a[i];
    }

    for(int i = 0; m > i; ++i){
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    ll resp = 0;

    int i = 0, j = 0;

    while(n > i && m > j){
        if(b[j]+k>=a[i] && b[j]-k<=a[i]){
            i++;
            j++;
            resp++;
        }else if(b[j]+k<a[i]){
            i++;
        }else{
            j++;
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
