#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n, m;
struct edge {
    int u, v, w;
};
vector<edge> G[maxn];

int dis[maxn], vis[maxn];
void dijkstra(int s) {
    for (int i = 1; i <= n; ++i) {
        vis[i] = false;
        dis[i] = (i == s) ? 0 : INT_MAX;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   greater<pair<int, int> > >
        q;

    q.push({dis[s], s});
    while (!q.empty()) {
        int cur = q.top().second;
        q.pop();

        if (vis[cur]) {
            continue;
        }
        vis[cur] = true;

        for (int i = 0; i < G[cur].size(); ++i) {
            int v = G[cur][i].v, w = G[cur][i].w;
            if (dis[v] > max(dis[cur], w)) {
                dis[v] = max(dis[cur], w);
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    cin >> n >> m;

    for (int i = 1, a, b, c; i <= m; ++i) {
        cin >> a >> b >> c;

        G[a].push_back({a, b, c});
        G[b].push_back({b, a, c});
    }

    dijkstra(1);

    cout << dis[n] << '\n';

    return 0;
}
