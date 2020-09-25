#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define llong long long
#define dlong long double
#define endl '\n'

using namespace std;

const int N=1000005;
const int MOD=(1e9) + 7;

llong fac[N], sum[50], refac[N];
int mk[50], mkk[50];


llong binpow (llong a, int n) {
    llong res = 1;
    while (n) {
        if (n & 1) res *= a;
        res%=MOD;
        a *= a;
        a%=MOD;
        n >>= 1;
    }
    return res%MOD;
}

int del(int x, int y) {
    return (x * (binpow(y,(MOD - 2))))%MOD;
}


int main() {
    ios_base::sync_with_stdio();
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif // LOCAL
    string s,ss;
    cin >> s >> ss;
    fac[1]=1;
    refac[1]=del(1,fac[1]);
    fac[0]=1;
    refac[0]=del(1,fac[0]);
    for (llong i(2); i<=(1e6+3); i++) {
        fac[i]=(fac[i-1]*i)%MOD;
        refac[i]=del(1,fac[i]);
    }

    return 0;
}
