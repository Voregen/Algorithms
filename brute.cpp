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
//#define endl '\n'
#define pb push_back
#define F first
#define S second

// CODE CODE CODE CODE CODE CODE CODE CODE CODE

const llong N = 2e2 + 36;
const llong M = 11;
const llong INF = 2e9 + 7;
const llong MOD = 987654323;
const llong MOD1 = 1e9 + 7;
const llong MOD2 = 1e9 + 9;
const char mov[4] = {'U', 'L', 'D', 'R'};
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

char a[N][N];
pair < int, int > s, f;
vector < pair < pair < int, int >, int > > teleports;
string ans = "";
int sum = 1, t, goes[N * N], n, m, T = 0, dist[N][N];
llong lst = 0;
bool us[N][N];

void die() {
    ifstream chec("need" + itos(t) + ".txt");
    int best;
    chec >> best;
    chec.close();
    if (sum <= best) {
        return;
    }
    cerr << "NEW ANS TEST : " << t << endl;
    cerr << t << ' ' << ' ' << sum << ' ' << best << endl;
    ofstream out("need" + itos(t) + ".txt");
    out << sum << endl;
    out << ans << endl;
    out.close();
    ofstream ut("output" + itos(t) + ".txt");
    ut << ans << endl;
    ut.close();
}

bool good(pair < int, int > x) {
    if (min(x.F, x.S) < 0 || x.F >= n || x.S >= m) {
        return false;
    }
    return good;
}

string tostr(int x) {
    string now = "";
    while (x > 0) {
        now += char((x % 10) + '0');
        x /= 10;
    }
    reverse(now.begin(), now.end());
    return now;
}

void dfs(pair < int, int > x) {
    ++lst;
    if (x == f) {
        die();
        return;
    }
    if (1.0 * clock() / CLOCKS_PER_SEC > 2.0) {
        exit(0);
    }
    us[x.F][x.S] = true;
    if (a[x.F][x.S] == '@') {
        us[x.F][x.S] = false;
//        if (lst < 20) {
//            for (int i(0); i < int(teleports.size()); ++i) {
//                if (goes[teleports[i].S] > 1)
//                    continue;
//                string tru = "{" + tostr(teleports[i].S + 1) + "}";
//                ans += tru;
//                ++goes[teleports[i].S];
//                dfs({teleports[i].F.F, teleports[i].F.S});
//                --goes[teleports[i].S];
//                while (!tru.empty()) {
//                    ans.pop_back();
//                    tru.pop_back();
//                }
//            }
//        } else {
        pair < pair < int, int >, int > mx = teleports[0];
        for (int i(0); i < int(teleports.size()); ++i) {
            if (goes[teleports[i].S] > 3)
                continue;
            if (dist[mx.S] < dist[teleports[i].S]) {
                mx = teleports[i];
            }
        }
        if (goes[mx.S] < 4) {
            string tru = "{" + tostr(mx.S + 1) + "}";
            ans += tru;
            ++goes[mx.S];
            dfs({mx.F.F, mx.F.S});
            --goes[mx.S];
            while (!tru.empty()) {
                ans.pop_back();
                tru.pop_back();
            }
        }
        //  }
    }
//    if (lst % 5) {
//        vector < int > h = {0, 1, 2, 3};
//        sort(h.begin(), h.end(), comp());
//        for (int i(0); i < 4; ++i) {
//            pair < int, int > nX = x;
//            nX.F += XK[i], nX.S += YK[i];
//            if (!good(nX) || us[nX.F][nX.S] || a[nX.F][nX.S] == '#')
//                continue;
//            ans += mov[i];
//            ++sum;
//            dfs(nX);
//            --sum;
//            ans.pop_back();
//        }
//    } else {
    pair < int, int > mn = x;
    pair < int, int > mx = x;

    char mnW, mxW;
    for (int i(0); i < 4; ++i) {
        pair < int, int > nX = x;
        nX.F += XK[i], nX.S += YK[i];
        if (!good(nX) || us[nX.F][nX.S] || a[nX.F][nX.S] == '#')
            continue;
        if (dist[mn.F][mn.S] > dist[nX.F][nX.S]) {
            mn = nX;
            mnW = i;
        }
        if (dist[mx.F][mx.S] < dist[nX.F][nX.S]) {
            mx = nX;
            mxW = i;
        }
    }
//    if (lst < 500 && gen() % 5) {
//        if (x != mx) {
//            ans += mov[mxW];
//            ++sum;
//            dfs(mx);
//            --sum;
//            ans.pop_back();
//        }
//    } else {
    vector < int > h = {0, 1, 2, 3};
    shuffle(h.begin(), h.end(), gen);
    for (int i(0); i < 4; ++i) {
        pair < int, int > nX = x;
        nX.F += XK[i], nX.S += YK[i];
        if (!good(nX) || us[nX.F][nX.S] || a[nX.F][nX.S] == '#')
            continue;
        ans += mov[i];
        ++sum;
        dfs(nX);
        --sum;
        ans.pop_back();
    }
    //}
    us[x.F][x.S] = false;
    return;
}

void finmin() {
    queue < pair < int, int > > q;
    q.push(f);
    dist[f.F][f.S] = 0;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        if (a[x.F][x.S] == '@') {
            for (int i(0); i < int(teleports.size()); ++i) {
                if (dist[teleports[i].F.F][teleports[i].F.S] > dist[x.F][x.S] + 1) {
                    q.push({teleports[i].F.F, teleports[i].F.S});
                    dist[teleports[i].F.F][teleports[i].F.S] = dist[x.F][x.S] + 1;
                }
            }
        }
        for (int i(0); i < 4; ++i) {
            pair < int, int > nX = x;
            nX.F += XK[i], nX.S += YK[i];
            if (!good(nX) || us[nX.F][nX.S] || a[nX.F][nX.S] == '#')
                continue;
            if (dist[nX.F][nX.S] > dist[x.F][x.S] + 1) {
                q.push({nX.F, nX.S});
                dist[nX.F][nX.S] = dist[x.F][x.S] + 1;
            }
        }
    }
    return;
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
    vector < int > gnrtr = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    t = gnrtr[gen() % int(gnrtr.size())];
    //t = 2;
    cout << t << endl;
    ifstream inp("input" + itos(t) + ".txt");
    inp >> n >> m;
    for (int i(0); i < n; ++i) {
        for (int j(0); j < m; ++j) {
            inp >> a[i][j];
            if (a[i][j] == 'S') {
                s = {i, j};
                a[i][j] = '.';
            }
            if (a[i][j] == 'F') {
                f = {i, j};
                a[i][j] = '.';
            }
            if (a[i][j] == '@') {
                teleports.pb({{i, j}, T++});
            }
            dist[i][j] = INF;
        }
    }
    inp.close();
    finmin();
    shuffle(teleports.begin(), teleports.end(), gen);
    dfs(s);
    return 0;
}
