#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    vector <int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cin >> m;
    vector <int> q(m);
    for (int i=0; i<m; ++i) {
        cin >> q[i];
    }
    for (int i=0; i<m; ++i) {
        int l=0, r=n-1, ans=n, z;
        while (l <= r) {
            z=(l+r)>>1;
            if (a[z] >= q[i]) {
                ans = z;
                r=z-1;
            } else {
                l=z+1;
            }
        }
        cout << ans << " ";
        ans=0;
    }
}
