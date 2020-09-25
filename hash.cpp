#include <bits/stdc++.h>
#define ll long long
#define S second
#define F first
using namespace std;
const int N = 5 * 1e5 + 1;
const int MOD1 = 1e9 + 9;
const int MOD2 = 1e9 + 7;
const int P = 91099;
vector < pair < int , int > > p(N);

struct Hash {
    vector < pair < int , int > > h;
    Hash(const string & s) : h (s.size()) {
        h[0].F = s[0] - '0' + 1;
        h[0].S = s[0] - '0' + 1;
        for (int i(1); i < s.size(); i++) {
            h[i].F = (h[i - 1].F * (1ll) * P) % MOD1;
            h[i].S = (h[i - 1].S * (1ll) * P) % MOD2;
            h[i].F = (h[i].F * (1ll) + s[i] - '0' + 1) % MOD1;
            h[i].S = (h[i].S * (1ll) + s[i] - '0' + 1) % MOD2;
        }
    }
    pair  < int, int > get(int l, int r) {
        int len = r - l + 1;
        int res1 = h[r].F;
        int res2 = h[r].S;
        if (l > 0) {
            res1 -= (1ll) * h[l - 1].F * p[len].F % MOD1;
            res2 -= (1ll) * h[l - 1].S * p[len].S % MOD2;
        }
        res1 %= MOD1;
        res2 %= MOD2;
        if (res1 < 0) res1 += MOD1;
        if (res2 < 0) res2 += MOD2;
        return { res1, res2 };
    }
};

int main () {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    p[0].F = 1;
    p[0].S = 1;

    for (int i(1); i <= N; i++) {
        p[i].F = (p[i - 1].F * (1ll * P)) % MOD1;
        p[i].S = (p[i - 1].S * (1ll * P)) % MOD2;
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = s;
    reverse(s.begin(), s.end());
    for (int i(0); i < n; i++) {
        if (s[i] == '1') s[i] = '0';
        else s[i] = '1';
    }
    Hash h(s1);
    Hash h1(s);
    int m, l, r;
    cin >> m;
    set < pair < ll , ll > > aa;
    for (int i(0); i < m; i++) {
        cin >> l >> r;
        l--;
        r--;
        pair < int , int >  ss = h.get(l, r);
        aa.insert(ss);
    }
    ll anss = 0;
    for (int i(0); i < n; i++) {
        int l = 1, r = min(i, n - i), ans = 0;
        while (l <= r) {
            int len = (l + r) / 2;
            int a = (n - (i - 1) - 1), b = n - (i - len) - 1;
            if (h1.get(a, b) == h.get(i, i + len - 1)) {
                ans = len;
                l = len + 1;
            } else r = len - 1;
        }
        anss += ans;
    }
    cout << anss << endl;
    cout << aa.size() << endl;
}



// SUPER

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

//const int N = 100100;

//int mod[2] = {1000000000 + 9, 1000000000 + 7};
int mod[2] = {888888901, 999988901};
vector<int> st[2];
int add[2] = {449, 37};
const char smallest = 'a';

bool precalc() {
    st[0].resize(N);
    st[0][0] = 1;
    st[1].resize(N);
    st[1][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            st[j][i] = (1ll * st[j][i - 1] * add[j]) % mod[j];
        }
    }
    return false;
}

bool precalc_crash = precalc();

struct super_hash {
    vector<int> a[2];
    super_hash() {}
    super_hash(string &s) {
        a[0].resize(s.size());
        a[1].resize(s.size());
        a[0][0] = (s[0] - smallest) + 1;
        a[1][0] = (s[0] - smallest) + 1;
        for (int i = 1; i < s.size(); i++) {
            for (int j = 0; j < 2; j++) {
                a[j][i] = a[j][i - 1];
                a[j][i] = (1ll * a[j][i] + 1ll * st[j][i] * (s[i] - smallest + 1)) % mod[j];
            }
        }
    }
    pair<int, int> get_hash(int l, int r, int p = N - 1) {
        pair<int, int> ans;
        ans.F = a[0][r] - (l == 0 ? 0 : a[0][l - 1]);
        if (ans.F < 0) ans.F += mod[0];
        ans.F = (1ll * ans.F * st[0][p - l]) % mod[0];
        ans.S = a[1][r] - (l == 0 ? 0 : a[1][l - 1]);
        if (ans.S < 0) ans.S += mod[1];
        ans.S = (1ll * ans.S * st[1][p - l]) % mod[1];
        return ans;
    }
};
