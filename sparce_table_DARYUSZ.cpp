#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

using namespace std;
//using namespace __gnu_pbds;

#define llong long long
#define dlong double long
#define ulong unsigned long long
#define endl '\n'
#define pb push_back
#define F first
#define S second

// CODE CODE CODE CODE CODE CODE CODE CODE CODE

const llong N = 1e5 + 36;
const llong M = 11;
const llong INF = 2e18 + 7;
const llong MOD = 987654323;
const llong MOD1 = 1e9 + 7;
const llong MOD2 = 1e9 + 9;
const int XK[4] = {-1, 0, 1, 0};
const int YK[4] = {0, -1, 0, 1};
const int X[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int Y[8] = {2, -2, 2, -2, 1, -1, 1, -1};

//tree <int, null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> st;

int a[N], st[N], n, q;
vector < int > g[N];
map < int, llong > mp;

inline void prec() {
    for (int i(0); i < n; ++i) {
        g[i].pb(a[i]);
    }
    int sz = 1, k = 1;
    while ((sz << 1) < n) {
        for (int i(0); i <= n - (sz << 1); ++i) {
            g[i].pb(__gcd(g[i][k - 1], g[i + sz][k - 1]));
        }
        sz <<= 1;
        ++k;
    }
    return;
}

inline int ask(int l, int r) {
    int H = st[r - l + 1];
    return __gcd(g[l][H], g[r - (1 << H) + 1][H]);
}

inline void calc() {
    for (int i(0); i < n; ++i) {
        int lst = i;
        while (lst < n) {
            int l = lst, r = n - 1, ans = n - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (ask(i, mid) == ask(i, lst)) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            mp[ask(i, ans)] += ans - lst + 1;
            //cout << lst << ' ' << ans << ' ' << ask(i, ans) << ' ' << ans - lst + 1 << ' ' << "I: " << i << endl;
            lst = ans + 1;
        }
    }
    return;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    int  next = 4, k = 1;
    cin >> n;
    for (int i(0); i < n; ++i) {
        cin >> a[i];
    }
    st[1] = 0, st[2] = 1;
    for (int i(3); i <= n; ++i) {
        if (next == i) {
            next <<= 1;
            ++k;
        }
        st[i] = k;
    }
    prec();
    calc();
    cin >> q;
    for (int i(0); i < q; ++i) {
        int x;
        cin >> x;
        cout << mp[x] << endl;
    }
    return 0;
}





#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

using namespace std;
//using namespace __gnu_pbds;

#define llong long long
#define dlong double long
#define ulong unsigned long long
#define endl '\n'
#define pb push_back
#define F first
#define S second

// CODE CODE CODE CODE CODE CODE CODE CODE CODE

const llong N = 2e3 + 36;
const llong M = 31;
const llong INF = 2e9 + 7;
const llong MOD = 987654323;
const llong MOD1 = 1e9 + 7;
const llong MOD2 = 1e9 + 9;
const int XK[4] = {-1, 0, 1, 0};
const int YK[4] = {0, -1, 0, 1};
const int X[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int Y[8] = {2, -2, 2, -2, 1, -1, 1, -1};

//tree <int, null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> st;

int a[N][N], st[N], n, m, p, k;
int g[N][N][14];

inline void prec() {
    int next = 4, k = 1;
    st[1] = 0, st[2] = 1;
    for (int i(3); i < N; ++i) {
        if (next == i) {
            next <<= 1;
            ++k;
        }
        st[i] = k;
    }
    for (int i(0); i < n; ++i) {
        for (int j(0); j < m; ++j) {
            g[i][j][0] |= (1 << a[i][j]);
        }
    }
    int sz = 1;
    k = 1;
    while ((sz << 1) < n) {
        for (int i(0); i <= n - (sz << 1); ++i) {
            for (int j(0); j <= m - (sz << 1); ++j) {
                g[i][j][k] |= g[i][j][k - 1];
                g[i][j][k] |= g[i][j + sz][k - 1];
                g[i][j][k] |= g[i + sz][j][k - 1];
                g[i][j][k] |= g[i + sz][j + sz][k - 1];
            }
        }
        sz <<= 1;
        ++k;
    }
    return;
}

inline int ask(int l, int r, int k) {
    int H = st[k], now = 0;
    now |= g[l][r][H];
    now |= g[l + k - (1 << H)][r][H];
    now |= g[l][r + k - (1 << H)][H];
    now |= g[l + k - (1 << H)][r + k - (1 << H)][H];
    return __builtin_popcount(now);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m >> p >> k;
    for (int i(0); i < n; ++i) {
        for (int j(0); j < m; ++j) {
            cin >> a[i][j];
        }
    }
    prec();
    llong ans = 0;
    for (int i(0); i < n; ++i) {
        for (int j(0); j < m; ++j) {
            int l = 1, r = min(n - i, m - j), ans1 = INF, ans2 = INF;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int H = ask(i, j, mid);
                if (H == k) {
                    ans1 = mid;
                }
                if (H < k) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (ans1 == INF)
                continue;
            l = ans1, r = min(n - i, m - j);
            while (l <= r) {
                int mid = (l + r) >> 1;
                int H = ask(i, j, mid);
                if (H == k) {
                    ans2 = mid;
                }
                if (H > k) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans += ans2 - ans1 + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
