template <typename T>
struct fenwick {
    int n;
    vector <T> t;
    vector <T> t1;

    T query(vector <T> &a, int x) {
        T res = 0;
        for (int i = x; i; i -= i & -i) {
            res += a[i];
        }
        return res;
    }

    T query(int x) {
        return query(t, x) * x - query(t1, x);
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
    }

    void update(vector <T> &a, int x, T y) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] += y;
        }
    }

    void update(int l, int r, T x) {
        update(t, l, x);
        update(t, r + 1, -x);
        update(t1, l, (l - 1) * x);
        update(t1, r + 1, -r * x);
    }

    fenwick(int _n) {
      n = _n;
      t.resize(n + 5);
      t1.resize(n + 5);
    }
};
