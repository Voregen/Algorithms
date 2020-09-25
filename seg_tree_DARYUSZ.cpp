#include <bits/stdc++.h>

using namespace std;
int ss;
// pair < string, int > s[260000];

int add [10000001];
int tr  [10000001];

int ot[10000001];
void push(int v, int l, int r) {
    tr[v*2]+=add[v];
    tr[(v*2)+1]+=add[v];
    add[v*2]+=add[v];
    add[(v*2)+1]+=add[v];
    add[v]=0;
}

void modify(int l1, int r1, int v, int l, int r,int c1) {
    if (l>r1 || r<l1)
        return;
    if (l<=l1 && r>=r1) {
        add[v]+=c1;
        tr[v]+=c1;
        return;
    }
    push(v,l1,r1);
    modify(l1,(l1+r1)/2,v*2,l,r,c1);
    modify((l1+r1)/2+1,r1,(v*2)+1,l,r,c1);
    tr[v]=max(tr[v*2],tr[(v*2)+1]);
}

void sum(int l1, int r1, int v, int l, int r) {
    if (l>r1 || r<l1)
        return;
    if (l<=l1 && r>=r1) {
        ss=max(tr[v],ss);
        return;
    }
    push(v,l1,r1);
    sum(l1,(l1+r1)/2,v*2,l,r);
    sum((l1+r1)/2+1,r1,v*2+1,l,r);
    tr[v]=max(tr[v*2],tr[v*2+1]);
}

int main () {
    ios_base::sync_with_stdio(0);
    freopen("bigwall.in","r",stdin);
    freopen("bigwall.out","w",stdout);
    int n,m,l,r,x;
    string s;
    cin >> n >> m;
    int p=1;
    while (p<n)
        p*=2;
    int v=0;
    for (int i(0); i<m; i++) {
        cin >> s;
        if (s=="test") {
            cin >> l >> r;
            v++;
            ss=0;
            sum(p-1,p+n-1,1,l+p-1,r+p-1);
            ot[v]=ss;
        } else {
            cin >> l >> r >> x;
            modify(p-1,p+n-1,1,l+p-1,r+p-1,x);
        }

        /* for (int j(1); j<=p+n-1; j++)
         cout << tr[j] << " " ;
         cout << endl;
         for (int j(1); j<=p+n-1; j++)
         cout << j << " " ;
         cout << endl;
         cout << l+p-1 << " " << r+p-1 << endl;

         cout << endl; */
    }
    for (int i(1); i<=v; i++) {
        cout << ot[i] << endl;
    }
}
