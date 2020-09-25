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
#define ld double long
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
const ld EPS = 1e-9;

//tree <int, null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> st;

//mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

bool eq(ld a, ld b) {
    return abs(a-b) < EPS;
}


struct pt {
    ld x;
    ld y;
    pt(ld x = 0, ld y = 0) : x(x), y(y) {}
    bool operator<(pt a) {
        return eq(x, a.x)? y < a.y : x < a.x;
    }
};

bool mem(vector < pt > a, vector < pt > b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool f = true;
    for (int i(0); i < 4; ++i){
        if (a[i].x != b[i].x || a[i].y != b[i].y){
            f = false;
        }
    }
    return f;
}

vector < vector < pt > > all;

void kek(){
    qwe:
    for (int i(0); i < int(all.size()); ++i){
        for (int j(i + 1); j < int(all.size()); ++j){
            if (mem(all[i], all[j])){
                swap(all[int(all.size()) - 1], all[j]);
                all.pop_back();
                goto qwe;
            }
        }
    }
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
    pt a, b, c, d;
    a = {0, 0};
    b = {1, 1};
    c = {2, 2};
    d = {3, 3};
    all.pb({a, b, c, d});
    all.pb({a, b, d, c});
    kek();
    cout << all.size() << endl;
    return 0;
}
