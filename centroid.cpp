const int N = 3e5;

int sz[N];
bool used[N];
vector<vector<int> > g;

int computeSize(int x, int pr = -1) {
    sz[x] = 1;
    for (int to : g[x]) {
        if (to == pr || used[to]) continue;
        sz[x] += computeSize(to, x);
    }
    return sz[x];
}

int findCentroid(int x) {
    int N = sz[x];
    bool run = true;
    int pr = -1;
    while (run) {
        run = false;
        for (int to : g[x]) {
            if (to == pr || used[to]) continue;
            if (sz[to] > N / 2) {
                pr = x;
                x = to;
                run = true;
                break;
            }
        }
    }
    return x;
}

void solve(int x) {
    computeSize(x);
    x = findCentroid(x);
    //action here

    used[x] = true;
    for (int to : g[x]) {
        if (used[to]) continue;
        solve(to);
    }
}
