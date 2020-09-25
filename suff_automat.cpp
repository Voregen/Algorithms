struct suffix_automaton {
    int to[N][26];
    int link[N];
    int len[N];
    int sz = 1;
    int last = 0;

    void add(char ch) {
        int c = ch - 'a';
        int p = last;
        last = sz++;
        len[last] = len[p] + 1;
        for(; p != -1 && !to[p][c]; p = link[p]) {
            to[p][c] = last;
        }
        if(p == -1) return;
        int q = to[p][c];
        if(len[q] == len[p] + 1) {
            link[last] = q;
            return;
        }
        int cl = sz++;
        memcpy(to[cl], to[q], sizeof(to[q]));
        link[cl] = link[q];
        len[cl] = len[p] + 1;
        link[q] = link[last] = cl;
        for(; p != -1 && to[p][c] == q; p = link[p]) to[p][c] = cl;
    }

    bool count(string s) {
        bool ok = 1;
        int v = 0;
        for (auto ch : s) {
            int c = ch - 'a';
            if (to[v][c]) {
                v = to[v][c];
            } else {
                ok = 0;
                break;
            }
        }
        return ok;
    }

    void init(string s) {
        for (auto x : s) add(x);
    }

    suffix_automaton() {
        memset(to, 0, sizeof to);
        memset(link, 0, sizeof link);
        memset(len, 0, sizeof len);
        link[0] = -1;
    }
};

int main() {
    string s;
    cin >> s;
    suffix_automaton aut;
    aut.init(s);
    int q;
    cin >> q;
    while (q--) {
       string t;
       cin >> t;
       if (aut.count(t)){
         cout << "Yes";
       } else cout << "No";
       cout << endl;
    }
    return 0;
}
