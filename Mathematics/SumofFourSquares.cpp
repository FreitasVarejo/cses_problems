#include <bits/stdc++.h>
#define ll long long
#define fs first
#define sc second
#define vll vector<ll>
#define vvll vector<vll>

#define mp make_pair
#define pll pair <ll, ll>
#define vpll vector<pll>

#define eb emplace_back

using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr);

const ll MAX = (ll)(4 + 1e7);
const ll sqrt_MAX = 3162;

vll sq(MAX, 0);
vll quadrante(MAX, 0);
vll p(MAX, -1);

void pre(){
    for(int i = 0; MAX>i*i; ++i){
        sq[i*i] = i;
    }

    priority_queue<ll, vector<ll>, greater<ll>> q;

    p[0] = 0;

    //for(int i = 1; MAX > i*i; ++i){
    for(int i = sqrt_MAX+2; i > 0; --i){
        if(MAX > i*i){
            p[i*i] = i;
            q.push(i*i);
            quadrante[i*i] = 1;
        }
    }

    while(!q.empty()){
        ll v = q.top();
        q.pop();

        cout << v << ' ' << p[v] << endl;

        if(quadrante[v] != 4){
            for(int i = min(p[v], sqrt_MAX); i > 0; --i){
                ll u = i*i+v;

                if(MAX > u && p[u] == -1){
                    p[u] = i;
                    quadrante[u] = quadrante[v]+1;
                    q.push(u);
                }
            }
        }
    }

    for(int i = 0; 100 >= i; ++i){
        cout << i << ' ' << p[i] << ' '<< sq[i*i]<< endl;
    }
}

void solve(){
    ll n; cin >> n;
    for(int i = 1; 4 >= i; ++i){
        cout << sq[n-p[n]] << ' ';
        n = p[n];
    }cout<< endl;


    return;
}

int main(){_
    int t = 1;
    cin >> t;

    pre();

    while(t--){
        solve();
    }

    return  0;
}
