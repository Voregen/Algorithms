struct sparse_table {
    int dp[MAXN][MAXLOG];
    int prec_lg2[MAXN], n;

    sparse_table() {
        memset(dp, 0, sizeof(dp));
        memset(prec_lg2, 0, sizeof(prec_lg2));
        n = 0;
    }

    void init(vector<int> &a) {
        n = a.size();
        for(int i = 2; i < 2 * n; i++) prec_lg2[i] = prec_lg2[i >> 1] + 1;
        for(int i = 0; i < n; i++) dp[i][0] = a[i];
        for(int j = 1; (1 << j) <= n; j++)
            for(int i = 0; i < n; i++)
                dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }

    int query(int l, int r) {
        int k = prec_lg2[r - l + 1];
        return min(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
};


int n, m, p, k;
int a[N][N];

namespace SparseTable {
int st[9][9][N][N];
inline int __log2(int x) {
    return 31-__builtin_clz(x);
}
inline int pw2(int x) {
    return (1<<x);
}
void build() {
    rep(lgX, 0, 8) rep(lgY, 0, 8) {
        rep(i, 0, n) rep(j, 0, m) {
            if (lgX == 0 && lgY == 0) {
                st[lgX][lgY][i][j] = a[i][j];
            } else if (lgX == 0) {
                st[lgX][lgY][i][j] = (st[lgX][lgY-1][i][j] | st[lgX][lgY-1][i][j+pw2(lgY-1)]);
            } else {
                st[lgX][lgY][i][j] = (st[lgX-1][lgY][i][j] | st[lgX-1][lgY][i+pw2(lgX-1)][j]);
            }
        }
    }
}
int query(int x, int y, int x2, int y2) {
    int sx = __log2(x2-x+1);
    int sy = __log2(y2-y+1);
    return (st[sx][sy][x][y] | st[sx][sy][x2-pw2(sx)+1][y] | st[sx][sy][x][y2-pw2(sy)+1] | st[sx][sy][x2-pw2(sx)+1][y2-pw2(sy)+1]);
}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //  srand(time(0));
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // freopen(FILE".in", "r", stdin);
    //  freopen(FILE".out", "w", stdout);
#endif // LOCAL
    cin >> n >> m >> p >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    SparseTable::build();
    int x = SparseTable::query(0, 0, 1, 1);
    return 0;
}
