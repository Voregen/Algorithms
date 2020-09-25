struct wavelet_tree {
    int lo, hi;
    wavelet_tree *l, *r;
    int *b, psz;

    wavelet_tree() {
        lo = 1;
        hi = 0;
        psz = 0;
        l = NULL;
        r = NULL;
    }

    void init(int *from, int *to, int x, int y) {
        lo = x, hi = y;
        if(lo == hi || from >= to) return;
        int mid = (lo + hi) >> 1;
        auto f = [mid](int x) {
            return x <= mid;
        };
        b = (int*)malloc((to - from + 2) * sizeof(int));
        psz = 0;
        b[psz++] = 0;
        for(auto it = from; it != to; it++) b[psz] = (b[psz - 1] + f(*it)), psz++;
        auto pivot = stable_partition(from, to, f);
        l = new wavelet_tree();
        l->init(from, pivot, lo, mid);
        r = new wavelet_tree();
        r->init(pivot, to, mid+1, hi);
    }

    int kth(int l, int r, int k) {
        if(l > r) return 0;
        if(lo == hi) return lo;
        int inLeft = b[r] - b[l - 1], lb = b[l - 1], rb = b[r];
        if(k <= inLeft) return this->l->kth(lb + 1, rb, k);
        return this->r->kth(l - lb, r - rb, k - inLeft);
    }

    int LTE(int l, int r, int k) {
        if(l > r || k < lo) return 0;
        if(hi <= k) return r - l + 1;
        int lb = b[l - 1], rb = b[r];
        return this->l->LTE(lb + 1, rb, k) + this->r->LTE(l - lb, r - rb, k);
    }

    int count(int l, int r, int k) {
        if(l > r || k < lo || k > hi) return 0;
        if(lo == hi) return r - l + 1;
        int lb = b[l - 1], rb = b[r];
        int mid = (lo + hi) >> 1;
        if(k <= mid) return this->l->count(lb + 1, rb, k);
        return this->r->count(l - lb, r - rb, k);
    }

    ~wavelet_tree() {
        delete l;
        delete r;
    }
};

wavelet_tree T;

int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
#endif // LOCAL
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    T.init(a, a + n, 0, n);
    for (int i = 0; i < q; i++){
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        cout << T.LTE(l, r, b) - T.LTE(l, r, a - 1) << endl;
    }
    return 0;
}
