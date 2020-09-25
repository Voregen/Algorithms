#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

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

const llong N = 1e6 + 36;
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

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

string itos(int x) {
    if (x == 1)
        return "1";
    if (x == 2)
        return "2";
    if (x == 3)
        return "3";
    if (x == 4)
        return "4";
    if (x == 5)
        return "5";
    if (x == 6)
        return "6";
    if (x == 7)
        return "7";
    if (x == 8)
        return "8";
    if (x == 9)
        return "9";
    if (x == 10)
        return "10";
}

//set < pair < pair < int, int >, int > > st;
queue < pair < pair < set < pair < pair < int, int >, int > >, vector < vector < int > >, vector < int > > > q;
//vector < vector < int > > ans;
vector < int > cl, g[N], gr[N];
int sz[N], prior[N];

void add(set < pair < pair < int, int >, int > > &st, pair < pair < int, int >, int > a) {
    st.erase(a);
    for (auto to:g[a.S]) {
        st.erase({{sz[to], prior[to]}, to});
        sz[to]--;
        st.insert({{sz[to], prior[to]}, to});
    }
    ans.back().pb(a.S);
}

void dfs(int v, int now = 1) {
    prior[v] = now;
    for (auto to:gr[v]) {
        if (prior[to] == 0) {
            dfs(to, now + 1);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    int t = 4; //gen() % 6 + 3;
    if (t > 5) {
        t += 2;
    }
    ifstream inp("input" + itos(t) + ".txt");
    int n, m;
    inp >> n >> m;
    vector < int > per, obr;
    for (int i(0); i < n; ++i) {
        per.pb(i);
    }
    obr.resize(n);
    shuffle(per.begin(), per.end(), gen);
    for (int i(0); i < n; ++i) {
        obr[per[i]] = i;
    }
    for (int i(0); i < m; ++i) {
        int x, y;
        inp >> x >> y;
        x--, y--;
        x = per[x];
        y = per[y];
        sz[x]++;
        g[y].pb(x);
        gr[x].pb(y);
    }
    inp.close();

    for (int i(0); i < n; ++i) {
        if (!prior[i]) {
            dfs(i);
        }
    }

    for (int i(0); i < n; ++i) {
        st.insert({{sz[i], prior[i]}, i});
    }
    while (!st.empty()) {
        vector < pair < pair < int, int >, int > > H;
        while (!st.empty() && (*st.begin()).F.F == 0) {
            H.pb(*st.begin());
            st.erase(st.begin());
        }
        for (auto to:H) {
            st.insert(to);
        }
        if (int(H.size()) == 1) {
            add(H[0]);
            st.erase(H[0]);
        } else {
            pair < pair < int, int >, int > mx = H[0], mn = H[0];
            for (auto to:H) {
                mx = max(mx, to);
                mn = min(mn, to);
            }
            add(mx);
            add(mn);
        }
    }




    ifstream chec("output" + itos(t) + ".txt");
    int best;
    chec >> best;
    chec.close();

    cerr << t << ' ' << ' ' << int(ans.size()) << ' ' << best << ' ' << n << endl;
    if (int(ans.size()) >= best)
        return 0;
    cerr << "NEW ANS TEST : " << t << endl;
    ofstream out("output" + itos(t) + ".txt");
    out << int(ans.size()) << endl;
    for (auto to:ans) {
        out << int(to.size()) << ' ';
        for (auto go:to) {
            out << obr[go] + 1 << ' ';
        }
        out << endl;
    }
    out.close();
    return 0;
}
