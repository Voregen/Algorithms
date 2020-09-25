int ALPHABET = 1000;

vector<int> suffix_array(string s) {
    s.push_back(0);
    int n = s.size();
    vector<int> c(n), new_c(n), suf(n), new_suf(n), starts(max(n, ALPHABET + 1));
    for (int i = 0; i < n; i++) {
        suf[i] = i;
        c[i] = s[i];
        starts[s[i] + 1]++;
    }
    int sum = 0;
    for (auto &v : starts) {
        sum += v, v = sum;
    }
    for (int l = 0; l < n; l = (l ? 2 * l : 1)) {
        for (auto v : suf) {
            int pos = (v - l + n) % n;
            new_suf[starts[c[pos]]++] = pos;
        }
        int type = -1;
        long long last = -1;
        for (int i = 0; i < n; i++) {
            int v = new_suf[i];
            if (last != (c[v] * 1ll * max(n, ALPHABET + 1) + c[(v + l) % n])) {
                last = (c[v] * 1ll * max(n, ALPHABET + 1) + c[(v + l) % n]);
                starts[++type] = i;
            }
            new_c[v] = type;
        }
        swap(c, new_c);
        swap(suf, new_suf);
    }
    return suf;
}
