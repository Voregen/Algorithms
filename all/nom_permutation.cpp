
bool was[N];
llong P[N];

void calc(){
    P[1] = 1;
    for (int i(2); i < 30; ++i){
        P[i] = P[i - 1] * i;
    }
    return;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif // LOCAL
    llong n, k, ans = 0;
    cin >> n;
    vector < int > a(n);
    for (int i(0); i < n; ++i){
        cin >> a[i];
    }
    calc();
    for (int i(0); i < n; ++i){
        for (int j(1); j < a[i]; ++j){
            if (!was[j]){
                ans += P[n - i - 1];
            }
        }
        was[a[i]] = true;
    }
    cout << ans + 1 << endl;
    return 0;
}

