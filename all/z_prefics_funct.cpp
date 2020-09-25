vector < int > z_func(string s) {
    int n = int(s.size());
    vector < int > z(n);
    for (int i(1); i < n; ++i) {
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
    }
    return z;
}

vector < int > p_func(string s) {
    int n = int(s.size());
    vector< int > p(n);
    for (int i(0); i < n; ++i) {
        for (int k(0); k <= i; ++k) {
            if (s.substr(0, k) == s.substr(i - k + 1, k)) {
                pi[i] = k;
            }
        }
    }
    return p;
}
