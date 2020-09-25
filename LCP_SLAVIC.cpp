vector<int> suffarray(string & s) {
    int n = (int)s.size();
    int classes = 0;
    vector<int> p(n, 0), pn(n, 0);
    vector<int> c(n, 0), cn(n, 0);
    vector<int> cnt(max(n, 128), 0);

    for(int i = 0; i < n; ++i)
        ++cnt[s[i]];

    for(int i = 1; i < max(n, 128); ++i)
        cnt[i] += cnt[i - 1];

    for(int i = 0; i < n; ++i)
        p[--cnt[s[i]]] = i;

    c[p[0]] = 0;
    for(int i = 1; i < n; ++i) {
        if(s[p[i]] != s[p[i - 1]]) ++classes;
        c[p[i]] = classes;
    }

    for(int h = 0; (1 << h) < n; ++h) {
        cnt.assign(classes + 1, 0);
        for(int i = 0; i < n; ++i) {
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0) pn[i] += n;
        }

        for(int i = 0; i < n; ++i)
            ++cnt[c[pn[i]]];

        for(int i = 1; i <= classes; ++i)
            cnt[i] += cnt[i - 1];

        for(int i = n - 1; i >= 0; --i)
            p[--cnt[c[pn[i]]]] = pn[i];

        classes = 0;
        cn[p[0]] = 0;
        for(int i = 1; i < n; ++i) {
            if(c[p[i]] != c[p[i - 1]] || c[(p[i] + (1 << h)) % n] != c[(p[i - 1] + (1 << h)) % n])
                ++classes;
            cn[p[i]] = classes;
        }

        c = cn;
    }

    return p;
}

vector<int> kasai(string s, vector<int> sa) {
    int n = s.size();
    int k = 0;
    vector <int> lcp(n, 0);
    vector <int> rank(n, 0);
    for(int i = 0; i < n; i++) rank[sa[i]] = i;
    for(int i = 0; i < n; i++, k ? k--: 0) {
        if(rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while(i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
    }
    return lcp;
}

const int lg = 19;

int dp[N][20];
int logr[N];

void sparse_table(vector <int> &lcp) {
    for(int i = 0; i < lcp.size(); i++) dp[i][0] = lcp[i];
    for(int lg = 1; (1 << lg) <= lcp.size(); lg++)
        for(int i = 0; i + (1 << lg) < lcp.size(); i++)
            dp[i][lg] = min(dp[i][lg - 1], dp[i + (1 << (lg - 1))][lg - 1]);

    logr[0] = -1;
    for(int i = 1; i <= lcp.size(); i++) logr[i] = logr[i / 2] + 1;
}

int LCP(int l, int r) {
    if (l > r) swap(l, r);
    int len = r - l + 1, lg = logr[len];
    return min(dp[l][lg], dp[r - (1 << lg) + 1][lg]);
}
