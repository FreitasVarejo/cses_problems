struct SegTree {
    int n;
    vector<long long> seg, lazy;

    SegTree() {}
    SegTree(const vector<long long>& a) { init(a); }

    void init(const vector<long long>& a) {
        n = (int)a.size();
        seg.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(1, 0, n-1, a);
    }

    void build(int p, int l, int r, const vector<long long>& a) {
        lazy[p] = 0;
        if (l == r) { seg[p] = a[l]; return; }
        int m = (l + r) / 2;
        build(p*2, l, m, a);
        build(p*2+1, m+1, r, a);
        seg[p] = seg[p*2] + seg[p*2+1];
    }

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
    }

    long long query(int ql, int qr) { return query(ql, qr, 1, 0, n-1); }
    long long query(int ql, int qr, int p, int l, int r) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return seg[p];
        push(p, l, r);
        int m = (l + r) / 2;
        return query(ql, qr, p*2, l, m) + query(ql, qr, p*2+1, m+1, r);
    }
};
