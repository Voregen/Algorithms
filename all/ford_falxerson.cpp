#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define ullong unsigned long long
#define llong long long
#define endl '\n'

using namespace std;

// CODE CODE CODE CODE CODE CODE CODE

const int MOD = 1e9;
const int N = 1e3 + 36;

llong c[N][N], f[N][N], pr[N], n;
vector < bool > used(N);

void dfs(int v) {
    used[v] = 1;
    for (int i(0); i < n; i++) {
        if (!used[i] && c[v][i] - f[v][i] > 0) {
            pr[i] = v;
            dfs(i);
        }
    }
}

llong max_flow(int s, int t) {
    llong ans = 0;
    while (true) {
        used.assign(100, 0);
        dfs(s);
        if (!used[t]) {
            break;
        }
        int v = t;
        llong flow = 1e9;
        while (v != s) {
            flow = min(flow, c[pr[v]][v] - f[pr[v]][v]);
            v = pr[v];
        }
        v = t;
        while (v != s) {
            f[pr[v]][v] += flow;
            f[v][pr[v]] -= flow;
            v = pr[v];
        }
        ans += flow;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("tree.in", "r", stdin);
    //freopen("tree.out", "w", stdout);
#endif
    int k, u, v, cost;
    cin >> n >> k;
    for (int i(0); i<k; i++) {
        cin >> u >> v >> cost;
        u--, v--;
        c[u][v] = c[v][u] = cost;
    }
    cout << max_flow(0, n - 1) << endl;
    return 0;
}
