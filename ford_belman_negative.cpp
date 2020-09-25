for (int i = 0; i < n; i++) d[i] = 1e9, pr[i] = -1;
    bool f = 0;
    int ve = -1;
    for (int i = 0; i < n; i++) {
        f = 0;
        for (auto x : e) {
            if (d[x.F.F] + x.S < d[x.F.S]) {
                f = 1;
                pr[x.F.S] = x.F.F;
                ve = x.F.S;
                d[x.F.S] = d[x.F.F] + l - x.S;
            }
        }
    }
    vector <int> path;
    vector <int> cnt(n, 0);
    cnt[ve]++;
    int x = pr[ve];
    path.pb(ve);
    vector <int> res;
    f = 0;
    while (true) {
        path.pb(x);
        // cerr << x << endl;
        cnt[x]++;
        int k = 0;
        if (cnt[x] == 2) {
            for (int i = path.size() - 1; i >= 0; i--) {
                if (path[i] == x) {
                    k++;
                }
                if (2 == k) {
                    f = 1;
                    break;
                }
                res.pb(path[i]);
            }
        }
        if (f) break;
        x = pr[x];
    }
    res.pb(x);
