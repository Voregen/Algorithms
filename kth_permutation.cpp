
bool was[N];
llong P[N];

void calc(){
    P[0] = 1;
    P[1] = 1;
    for (int i(2); i < 30; ++i){
        P[i] = P[i - 1] * i;
    }
    return;
}
vector < int > a;

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
    llong n, k, ans = 0;
    cin >> n >> k;
    a.assign(n, 0);
    for (int i(0); i < n; ++i){
        st.insert(i + 1);
    }
    calc();
    k--;
    for (int i(0); i < n; ++i){
        llong now = k / P[n - i - 1];
        k %= P[n - i  - 1];
        int H = *st.find_by_order(now);
        st.erase(H);
        a[i] = H;
    }
    for (auto to:a){
        cout << to << ' ';
    }
    return 0;
}
