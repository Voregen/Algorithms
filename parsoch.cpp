using namespace std;
const int N = 2e4 + 5;

vector <int> us(N, 0);
int mt[N], cur = 0;
vector <int> g[N];
vector <pii> a[1000005];
bool dfs(int v) {
    if (us[v] == cur) return 0;
    us[v] = cur;
    for (int to : g[v]) {
        if (mt[to] == -1) {
            mt[to] = v;
            mt[v] = to;
            return 1;
        }
    }
    for (int to : g[v]) {
        if (us[to] != cur && dfs(mt[to])) {
            mt[to] = v;
            mt[v] = to;
            return 1;
        }
    }
    return 0;
}

int main() {
    for (int i = 0; i < k; i++) mt[i] = -1;
    bool run = 1;
    while (run) {
        run = 0;
        cur++;
        for (int i = 0; i < k; i++) {
            if (mt[i] == -1 && dfs(i)) {
                run = 1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < k; i++){
        if (mt[i] != -1) res++;
    }
    cout << res / 2 << endl;
    return 0;
}
