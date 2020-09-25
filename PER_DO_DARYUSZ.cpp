struct node {
    llong kol;
    int ch_l, ch_r;
};

vector < node > t;

llong sum(int v, int l, int r, int L, int R) {
    if (r < L || l > R) {
        return 0;
    }
    if (L <= l && r <= R) {
        return t[v].kol;
    }
    return sum(t[v].ch_l, l, (l + r) >> 1, L, R) + sum(t[v].ch_r, ((l + r) >> 1) + 1, r, L, R);
}

llong query(int x, int y, int l, int r, int k) {
    if (l == r) {
        return r;
    }
    if (t[t[x].ch_l].kol - t[t[y].ch_l].kol >= k) {
        return query(t[x].ch_l, t[y].ch_l, l, (l + r) >> 1, k);
    } else {
        k -= t[t[x].ch_l].kol - t[t[y].ch_l].kol;
        return query(t[x].ch_r, t[y].ch_r, ((l + r) >> 1) + 1, r, k);
    }
}

int modify(int v, int l, int r, int p, int x) {
    t.pb(t[v]);
    v = int(t.size()) - 1;
    if (r - l == 0) {
        t[v].kol += x;
        return v;
    }
    if (((l + r) >> 1) < p) {
        int z = modify(t[v].ch_r, ((l + r) >> 1) + 1, r, p, x);
        t[v].ch_r = z;
    } else {
        int z = modify(t[v].ch_l, l, (l + r) >> 1, p, x);
        t[v].ch_l = z;
    }
    t[v].kol = t[t[v].ch_l].kol + t[t[v].ch_r].kol;
    return v;
}
