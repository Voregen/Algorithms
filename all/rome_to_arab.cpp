#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
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

const llong N = 1e3 + 36;
const llong M = 1e3 + 36;
const llong INF = 2e9+7;
const llong MOD = 987654323;
const llong MOD1 = 1e9 + 7;
const llong MOD2 = 1e9 + 9;
const llong MOD3 = 1e18 + 3;
const int XK[4] = {-1, 0, 1, 0};
const int YK[4] = {0, -1, 0, 1};
const int X[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int Y[8] = {2, -2, 2, -2, 1, -1, 1, -1};

//tree <pair<pair<int,int>, int>, null_type, less<pair<pair<int,int>, int>>, rb_tree_tag, tree_order_statistics_node_update> st;

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

llong dp[N];
set < string > can;
map < string, int > mp;

void prec() {
    mp["MMM"] = 3000;
    mp["MM"] = 2000;
    mp["M"] = 1000;
    mp["C"] = 100;
    mp["CC"] = 200;
    mp["CCC"] = 300;
    mp["CD"] = 400;
    mp["D"] = 500;
    mp["DC"] = 600;
    mp["DCC"] = 700;
    mp["DCCC"] = 800;
    mp["CM"] = 900;
    mp["X"] = 10;
    mp["XX"] = 20;
    mp["XXX"] = 30;
    mp["XL"] = 40;
    mp["L"] = 50;
    mp["LX"] = 60;
    mp["LXX"] = 70;
    mp["LXXX"] = 80;
    mp["XC"] = 90;
    mp["I"] = 1;
    mp["II"] = 2;
    mp["III"] = 3;
    mp["IV"] = 4;
    mp["V"] = 5;
    mp["VI"] = 6;
    mp["VII"] = 7;
    mp["VIII"] = 8;
    mp["IX"] = 9;
    can.insert("MMM");
    can.insert("MM");
    can.insert("M");
    can.insert("C");
    can.insert("CC");
    can.insert("CCC");
    can.insert("CD");
    can.insert("D");
    can.insert("DC");
    can.insert("DCC");
    can.insert("DCCC");
    can.insert("CM");
    can.insert("X");
    can.insert("XX");
    can.insert("XXX");
    can.insert("XL");
    can.insert("L");
    can.insert("LX");
    can.insert("LXX");
    can.insert("LXXX");
    can.insert("XC");
    can.insert("I");
    can.insert("II");
    can.insert("III");
    can.insert("IV");
    can.insert("V");
    can.insert("VI");
    can.insert("VII");
    can.insert("VIII");
    can.insert("IX");
}

bool correct(string &s) {
    bool T = false, S = false, D = false, E = false;
    int n = int(s.size());
    for (int i(0); i < n; ++i) {
        if (s[i] == 'M') {
            if (T || S || D || E)
                return false;
            T = true;
            int k = 0;
            while(i < n && s[i] == 'M') {
                i++;
                k++;
            }
            if (k > 3)
                return false;
            if (i == n)
                break;
            --i;
            continue;
        }
        if (s[i] == 'C' || s[i] == 'D') {
            if (S || D || E) {
                return false;
            }
            S = true;
            string ss = "";
            ss += s[i];
            while (i < n) {
                i++;
                if (s[i] != 'C' && s[i] != 'D' && s[i] != 'M')
                    break;
                if (s[i] == 'M') {
                    ss += s[i];
                    i++;
                    break;
                }
                ss += s[i];
            }
            if (!can.count(ss))
                return false;
            if (i == n)
                break;
            --i;
            continue;
        }
        if (s[i] == 'X' || s[i] == 'L') {
            if (D || E) {
                return false;
            }
            D = true;
            string ss = "";
            ss += s[i];
            while (i < n) {
                i++;
                if (s[i] != 'X' && s[i] != 'L' && s[i] != 'C')
                    break;
                if (s[i] == 'C') {
                    ss += s[i];
                    i++;
                    break;
                }
                ss += s[i];
            }
            if (!can.count(ss))
                return false;
            if (i == n)
                break;
            --i;
            continue;
        }
        if (s[i] == 'I' || s[i] == 'V') {
            if (E) {
                return false;
            }
            E = true;
            string ss = "";
            ss += s[i];
            while (i < n) {
                i++;
                if (s[i] != 'I' && s[i] != 'V' && s[i] != 'X')
                    break;
                if (s[i] == 'X') {
                    ss += s[i];
                    i++;
                    break;
                }
                ss += s[i];
            }
            if (!can.count(ss))
                return false;
            if (i == n)
                break;
            --i;
            continue;
        }
    }
    return true;
}

int per(string &s) {
    int sum = 0;
    int n = int(s.size());
    for (int i(0); i < n; ++i) {
        if (s[i] == 'M') {
            string ss = "";
            while (i < n && s[i] == 'M') {
                ss += s[i];
                i++;
            }
            sum += mp[ss];
        }
        if (s[i] == 'C' || s[i] == 'D') {
            string ss = "";
            ss += s[i];
            while (i < n) {
                i++;
                if (s[i] != 'C' && s[i] != 'D' && s[i] != 'M')
                    break;
                if (s[i] == 'M') {
                    ss += s[i];
                    break;
                }
                ss += s[i];
            }
            sum += mp[ss];
        }
        if (s[i] == 'X' || s[i] == 'L') {
            string ss = "";
            ss += s[i];
            while (i < n) {
                i++;
                if (s[i] != 'X' && s[i] != 'L' && s[i] != 'C')
                    break;
                if (s[i] == 'C') {
                    ss += s[i];
                    break;
                }
                ss += s[i];
            }
            sum += mp[ss];
        }
        if (s[i] == 'I' || s[i] == 'V') {
            string ss = "";
            ss += s[i];
            while (i < n) {
                i++;
                if (s[i] != 'I' && s[i] != 'V' && s[i] != 'X')
                    break;
                if (s[i] == 'X') {
                    ss += s[i];
                    break;
                }
                ss += s[i];
            }
            sum += mp[ss];
        }
    }
    return sum;
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
#endif // LOCAL
    prec();
    string T = "XIX";
//    cout << correct(T) << ' ' << T << ' ' << per(T) << endl;
//    return 0;
    string s;
    cin >> s;
    int n = int(s.size());
    for (int i(0); i <= n; ++i) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int i(1); i <= n; ++i) {
        for (int j(0); j < i; ++j) {
            string t = s.substr(j, i - j);
            //cout << correct(t) << ' ' << t << ' ' << per(t) << endl;
            if (correct(t)) {
                int H = per(t);
                dp[i] = min(dp[i], dp[j] + H);
            }
        }
    }
    cout << dp[int(s.size())] << endl;
    return 0;
}
