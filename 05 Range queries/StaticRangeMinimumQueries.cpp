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
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);

struct SegTree {
    int n;
    vector<long long> seg, lazy;

    SegTree() {}
    SegTree(const vector<long long> &a) { init(a); }

    void init(const vector<long long> &a) {
        n = (int)a.size();
        seg.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void build(int p, int l, int r, const vector<long long> &a) {
        //lazy[p] = 0;
        if (l == r) {
            seg[p] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(p * 2, l, m, a);
        build(p * 2 + 1, m + 1, r, a);
        seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int q, long long x) { update(q, x, 1, 0, n - 1); }
    //void update(int ql, int qr, long long x) { update(ql, qr, x, 1, 0, n - 1); }
    void update(int q, long long x, int p, int l, int r) {
        if (q < l || r < q)
            return;
        if (l == r) {
            seg[p] = x;
            return;
        }
        int m = (l + r) / 2;
        update(q, x, p * 2, l, m);
        update(q, x, p * 2 + 1, m + 1, r);
        seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
    }

    long long query(int ql, int qr) { return query(ql, qr, 1, 0, n - 1); }
    long long query(int ql, int qr, int p, int l, int r) {
        if (qr < l || r < ql)
            return INF;
        if (ql <= l && r <= qr)
            return seg[p];
        int m = (l + r) / 2;
        return min(query(ql, qr, p * 2, l, m), query(ql, qr, p * 2 + 1, m + 1, r));
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vll v(n, 0);

    for (int i = 0; n > i; ++i)
        cin >> v[i];

    SegTree s(v);

    while (q--) {
        ll c, a, b;
        cin >> c >> a >> b;
        if (c == 2)
            cout << s.query(a-1, b-1) << endl;
        else
            s.update(a-1, b);
    }
}

int main() {_
    int o = 1;
    // cin >> o;

    while (o--) {
        solve();
    }

    return 0;
}
