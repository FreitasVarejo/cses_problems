#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pll pair<ll, ll>
#define fs first
#define sc second
#define vll vector<ll>
#define vpll vector<pll>
#define vvll vector<vll>
#define vvpll vector<vpll>

#define eb emplace_back

using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define _                                                                      \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);

void solve() {
    ll n, q;
    cin >> n >> q;
    vvll v(n + 1, vll(n + 1, 0));
    vvll sm(n + 1, vll(n + 1, 0));

    for(int i = 1; n >= i; i++){
        for(int j = 1; n >= j; j++){
            char c; cin >> c;
            v[i][j] = (c == '*');
            sm[i][j] = v[i][j];
            sm[i][j] += sm[i-1][j];
            sm[i][j] += sm[i][j-1];
            sm[i][j] -= sm[i-1][j-1];

        }
    }

    while (q--) {
        ll ax, bx, ay, by;
        cin >> ay >> ax >> by >> bx;
        cout << sm[by][bx] - sm[ay - 1][bx] - sm[by][ax - 1] +
                    sm[ay - 1][ax - 1] << endl;
    }
}

int main() {
    _ int o = 1;
    // cin >> o;

    while (o--) {
        solve();
    }

    return 0;
}
