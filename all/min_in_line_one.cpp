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

const llong N = 3e6 + 36;
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

int A[N];
vector < pair < pair < int, int >, int > > a, b;

void add(int x) {
    if (a.empty()) {
        a.pb({{x, x}, x});
    } else {
        a.pb({{x, max(x, a.back().F.S)}, min(x, a.back().S)});
    }
}

void transfer() {
    if (!b.empty())
        return;
    while (!a.empty()) {
        auto H = a.back();
        a.pop_back();
        if (b.empty()) {
            b.pb({{H.F.F, H.F.F}, H.F.F});
        } else {
            b.pb({{H.F.F, max(H.F.F, b.back().F.S)}, min(H.F.F, b.back().S)});
        }
    }
}

void del() {
    b.pop_back();
}

int mx() {
    if (a.empty() && b.empty()) {
        return 0;
    }
    if (a.empty()) {
        return b.back().F.S;
    }
    if (b.empty()) {
        return a.back().F.S;
    }
    return max(a.back().F.S, b.back().F.S);
}

int mn() {
    if (a.empty() && b.empty()) {
        return 0;
    }
    if (a.empty()) {
        return b.back().S;
    }
    if (b.empty()) {
        return a.back().S;
    }
    return min(a.back().S, b.back().S);
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
    int n, t;
    cin >> t >> n;
    for (int i(0); i < n; ++i) {
        cin >> A[i];
    }
    int l = 0, r = 0, ans = 0;
    add(A[0]);
    while (r + 1 < n) {
        while (r + 1 < n && mx() - mn() <= t) {
            r++;
            add(A[r]);
        }
        if (mx() - mn() <= t){
            ans = max(ans, r - l);
        } else {
            ans = max(ans, r - l - 1);
        }
        while (l <= r && mx() - mn() > t){
            transfer();
            del();
            l++;
        }
    }
    ans = max(ans, r - l);
    cout << ans + 1 << endl;
    return 0;
}
