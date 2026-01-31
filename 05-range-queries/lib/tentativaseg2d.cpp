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
	vvll seg, lazy;

	SegTree() {}
	SegTree(const vvll &a) { init(a); }

	void init(const vvll &a) {
		n = (int)a.size();
		seg.assign(4 * n, vll(4 * n, 0));
		lazy.assign(4 * n, vll(4 * n, 0));
		build(1, 1, 0, n - 1, 0, n - 1, a);
	}

	void build(int pa, int pb, int la, int ra, int lb, int rb, const vvll &a) {
		lazy[pa][pb] = 0;
		if (la == ra && lb == rb) {
		seg[pa][pb] = a[la][lb];
		return;
		}
		int ma = (la + ra) / 2;
		int mb = (lb + rb) / 2;
		build(pa * 2, pb * 2, la, ma, lb, mb, a);
		build(pa * 2 + 1, pb * 2, ma + 1, ra, lb, mb, a);
		build(pa * 2, pb * 2 + 1, la, ma, mb+1, rb, a);
		build(pa * 2 + 1, pb * 2 + 1, ma+1, ra, mb+1, rb, a);
		seg[pa][pb] = seg[pa * 2][pb * 2] + seg[pa * 2 + 1][pb * 2] +
					seg[pa * 2][pb * 2 + 1] + seg[pa * 2 + 1][pb * 2 + 1];
	}
	/*
	inline void apply(int p, int l, int r, long long val) {
			seg[p] += val * (r - l + 1);
			lazy[p] += val;
	}

	inline void push(int p, int l, int r) {
			if (lazy[p] == 0 || l == r) return;
			int m = (l + r) / 2;
			apply(p*2,     l,   m, lazy[p]);
			apply(p*2 + 1, m+1, r, lazy[p]);
			lazy[p] = 0;
	}

	void update(int ql, int qr, long long x) { update(ql, qr, x, 1, 0, n-1); }
	void update(int ql, int qr, long long x, int p, int l, int r) {
			if (qr < l || r < ql) return;
			if (ql <= l && r <= qr) { apply(p, l, r, x); return; }
			push(p, l, r);
			int m = (l + r) / 2;
			update(ql, qr, x, p*2, l, m);
			update(ql, qr, x, p*2+1, m+1, r);
			seg[p] = seg[p*2] + seg[p*2+1];
	}*/

	long long query(int qal, int qar, int qbl, int qbr) {
		return query(qal, qar, qbl, qbr, 1, 1, 0, n - 1, 0, n - 1);
	}
    //long long query(int ql, int qr, int p, int l, int r) {
	//return query(ql, qr, p*2, l, m) + query(ql, qr, p*2+1, m+1, r);

	long long query(int qa, int qb, int pa, int pb, int pb, int la, int ra, int lb, int rb) {
		if (qar < la || ra < qal || qbr < lb || rb < qbl)
			return 0;
		if (qal <= la && ra <= qal && qbr <= lb && rb <= qbl)
			return seg[pa][pb];
		int ma = (la + ra) / 2;
		int mb = (lb + rb) / 2;
		return query(qal, qar, qbl, qbr, pa * 2, pb * 2, la, ma, lb, mb) +
			query(qal, qar, qbl, qbr, pa * 2 + 1, pb * 2, ma + 1, ra, lb, mb) +
			query(qal, qar, qbl, qbr, pa * 2, pb * 2 + 1, la, ma, mb + 1, rb) +
			query(qal, qar, qbl, qbr, pa * 2 + 1, pb * 2 + 1, ma + 1, ra, mb + 1, rb);
	}
};

void solve() {
	ll n, q;
	cin >> n >> q;
	vvll v(n, vll(n, 0));

	for (int i = 0; n > i; ++i){
		for (int j = 0; n > j; ++j) {
			char c; cin >> c;
			v[i][j] = (c == '*') ? 1 : 0;
		}
	}

	SegTree s(v);

	while (q--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << s.query(a - 1, c - 1, b - 1, d - 1) << endl;
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
