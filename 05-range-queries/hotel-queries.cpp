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

    map<ll, vll> m;
    for (int i = 1; n >= i; ++i) {
        ll x;
        cin >> x;
        m[x].eb(i);
    }

    while (q--) {
        ll x;
        cin >> x;
        auto it = m.lower_bound(x);
        if (it != m.end()) {
            cout << 0 << " ";
        } else {
            ll rm = it->sc.back();
            it->sc.pop_back();
            m[it->fs - x].emplace_back(rm);
            cout << rm << " ";
        }
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
