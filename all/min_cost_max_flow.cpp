#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;

//using namespace __gnu_pbds;

#define pb push_back
#define F first
#define S second
#define ll long long
#define ld double long
#define ull unsigned long long
#define endl '\n'

const int N = 1e6 + 36;
const ll INF = 1e9 + 7;
const int MOD = 1e9 + 7;

mt19937 gen(19937);

//tree < pair < int, int >, null_type, less < pair < int, int > >, rb_tree_tag, tree_order_statistics_node_update > st;

struct edge {
    int v, to, f, c, cap, obr;
};

vector < edge > E;
int dist[N], bat[N], n, m;

void add(vector < edge > &E, int v, int to, int f, int c) {
    edge nw;
    nw.v = v, nw.to = to, nw.f = 0, nw.c = c, nw.cap = f, nw.obr = int(E.size() + 1);
    E.pb(nw);
    nw.v = to, nw.to = v, nw.f = 0, nw.c = -c, nw.cap = 0, nw.obr = int(E.size() - 1);
    E.pb(nw);
}

void tru(int s) {
    dist[s] = 0;
    bool f;
    for (int i(0); i < n; ++i) {
        f = 0;
        for (int j(0); j < int(E.size()); ++j){
            auto to = E[j];
            if (to.cap == to.f)
                continue;
            if (dist[to.v] != INF && dist[to.v] + to.c < dist[to.to]) {
                dist[to.to] = dist[to.v] + to.c;
                bat[to.to] = j;
                f = 1;
            }
        }
        if (!f){
            break;
        }
    }
}



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif // LOCAL
    cin >> n >> m;
    for (int i(0); i < m; ++i) {
        int a, b, c, g;
        cin >> a >> b >> c >> g;
        --a, -- b;
        add(E, a, b, c, g);
    }
    int s, t;
    cin >> s >> t;
    --s, --t;
    add(E, n, s, INF, 0);
    add(E, t, n + 1, INF, 0);
    int flow = 0;
    ll cost = 0;
    n += 2;
    while (true) {
        for (int i(0); i < n; ++i) {
            dist[i] = INF;
        }
        tru(n - 2);
        if (dist[n - 1] == INF)
            break;
        int addflow = INF;
        for (int v(n - 1); v != n - 2; v = E[bat[v]].v) {
            addflow = min(addflow, E[bat[v]].cap - E[bat[v]].f);
        }
        for (int v(n - 1); v != n - 2; v = E[bat[v]].v) {
            E[bat[v]].f += addflow;
            E[E[bat[v]].obr].f -= addflow;
            cost += 1ll * E[bat[v]].c * addflow;
        }
        flow += addflow;
    }
    cout << cost << endl;

    return 0;
}
