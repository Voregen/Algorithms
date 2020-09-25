struct otkat {
    int a, b, szA, szB, comp, deepA, deepB;
};

int pr[N], sz[N], deep[N], n, ans[N];
vector < int > g[N];
pair < int, int > A[N];
vector < otkat > st;

void make(int x) {
    pr[x] = x;
    sz[x] = 1;
    deep[x] = 0;
    return;
}

int perent(int x) {
    if (pr[x] == x)
        return x;
    else
        return perent(pr[x]);
}

void unite(int a, int b) {
    int x = perent(a), y = perent(b);
    otkat H;
    H.a = x, H.b = y, H.szA = sz[x], H.szB = sz[y], H.comp = n - (x != y ? 1 : 0), H.deepA = deep[x], H.deepB = deep[y];
    if (!st.empty()) {
        H.comp = st.back().comp - (x != y ? 1 : 0);
    }
    st.pb(H);
    if (gen() % 2) {
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
    } else {
        if (deep[x] < deep[y]) {
            swap(x, y);
        }
    }
    pr[y] = x;
    if (deep[x] == deep[y]) {
        ++deep[x];
    }
    sz[x] += sz[y];
    return;
}

void cumback() {
    if (!st.empty()) {
        otkat H = st.back();
        st.pop_back();
        pr[H.a] = H.a;
        pr[H.b] = H.b;
        sz[H.a] = H.szA;
        sz[H.b] = H.szB;
        deep[H.a] = H.deepA;
        deep[H.b] = H.deepB;
    }
    return;
}

void dfs(int v, int pr = -1) {
    unite(A[v].F, A[v].S);
    ans[v] = st.back().comp;
    for (auto to:g[v]) {
        if (to != pr) {
            dfs(to, v);
        }
    }
    cumback();
}
