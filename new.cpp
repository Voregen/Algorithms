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
const llong M = 11;
const llong INF = 2e9 + 7;
const llong MOD = 987654323;
const llong MOD1 = 1e9 + 7;
const llong MOD2 = 1e9 + 9;
const int XK[4] = {-1, 0, 1, 0};
const int YK[4] = {0, -1, 0, 1};
const int X[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int Y[8] = {2, -2, 2, -2, 1, -1, 1, -1};

//tree <int, null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> st;


mt19937 gen(19937);

int a[N][N], dp[N][N], res[N][N];
llong pref[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL
    int n, m;
    cin >> n >> m;
    for (int i(0); i < n; ++i) {
        for (int j(0); j < m; ++j) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    return 0;
    for (int i(0); i < n; ++i) {
        for (int j(0); j < m; ++j) {
            dp[i][j] = a[i][j];
            dp[i][j] += i ? dp[i - 1][j] : 0;
            dp[i][j] += j ? dp[i][j - 1] : 0;
            dp[i][j] -= (i && j) ? dp[i - 1][j - 1] : 0;
        }
    }
    llong cur = 0;
    for (int i(0); i < (m + 1) / 2; ++i) {
        int l = i, r = m - i - 1;
        cur += dp[n - 1][r];
        cur -= l ? dp[n - 1][l - 1] : 0;
        llong now = cur;
        for (int j(0); j < n; ++j) {
            pref[j][m - 1] += dp[j][r];
            if (l)
                pref[j][m - 1] -= dp[j][l - 1];
        }
        for (int j(0); j < (n + 1) / 2; ++j) {
            res[j][i] = now % 10;
            res[n - j - 1][i] = now % 10;
            res[j][m - i - 1] = now % 10;
            res[n - j - 1][m - i - 1] = now % 10;
            int cl = j + 1;
            int cr = n - j - 2;
            now += pref[cr][m - 1];
            now -= pref[cl - 1][m - 1];
        }
    }
    for (int i(0); i < n; ++i) {
        for (int j(0); j < m; ++j) {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}
