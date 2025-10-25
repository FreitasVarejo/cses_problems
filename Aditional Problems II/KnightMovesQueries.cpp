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



    while(n--){
        ll x, y; cin >> x >> y;

        x--, y--;

        vector <pll>  octantes = {
            mp(1,2),
            mp(1,-2),
            mp(-1,2),
            mp(-1,-2),
            mp(2, 1),
            mp(2, -1),
            mp(-2, 1),
            mp(-2, -1)
        };

        ll ok = 1;          

        for(auto [x1, y1]:octantes){
            for(auto [x2, y2]:octantes){
                if(x1*y2-x2*y1 != 0){
                    ll b = (x1*y-x2*x)/(x1*y2-x2*y1);
                    ll a = (x-y1*b)/(x1);

                    if(ok&&(x1*y-x2*x)%(x1*y2-x2*y1) == 0 && (x-y1*b)%(x1) == 0&&a>=0&&b>= 0){
                        cout << x1 << ' ' <<  y1 << endl;
                        cout << x2 << ' ' <<  y2 << endl;
                        cout << b << ' ' <<  a << endl;
                        cout << a + b << endl;
                        //ok = 0;
                    }
                }
            }
        }
        
    }
    
    
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