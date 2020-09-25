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

const llong N = 4e2 + 36;
const llong M = 3e4 + 36;
const llong INF = 2e9+7;
const dlong EPS = 0.00000001;
const llong MOD = 987654323;
const int X[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int Y[8] = {2, -2, 2, -2, 1, -1, 1, -1};
const int XK[8] = {1, -1, -1, 1, 0, 0, 1, -1};
const int YK[8] = {1, -1, 1, -1, 1, -1, 0, 0};

//tree <int, null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> st;

int a[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    freopen("input.txt", "w", stdout);
    int seed;
    //ifstream A("seed.txt");
    fstream A("seed.txt");
    A >> seed;
    srand(seed);
    seed++;
    fstream B("seed.txt");
    B << seed;
    cerr << seed << endl;
    int n = 1e5, m = 1e5 - 1;
    cout << n << ' ' << m << endl;
    for (int i(0); i < m; ++i){
        cout << i + 1 << ' ' << i + 2 << ' ';
        cout << (i << 1) + 3 << endl;
    }
    return 0;
}
