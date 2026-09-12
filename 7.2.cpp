//7.B 关键路径
//边（u,v,w)为关键路径的唯一条件：ve+w=vl
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {

    int n, e;
    while (cin >> n >> e) {
        vector<Edge> edges;
        vector<vector<pair<int,int>>> g(n + 1);
        vector<int> indeg(n + 1, 0);

        for (int i = 0; i < e; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            edges.push_back({a, b, c});
            g[a].push_back({b, c});
            indeg[b]++;
        }

        /* ---------- 拓扑排序 ---------- */
        /*三个作用：
         * 1.判断是否有环
         * 2.确保在计算 ve[v] 之前，所有指向 v 的前驱结点 u 的 ve[u] 都已经算完
         * 3.确保在计算 vl[u] 时，所有从 u 出发的后继结点 v 的 vl[v] 已知*/
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (indeg[i] == 0)
                q.push(i);

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (auto &p : g[u]) {
                int v = p.first;
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }

        if ((int)topo.size() != n) {
            cout << "unworkable project\n";
            continue;
        }

        /* ---------- ve ---------- */
        vector<int> ve(n + 1, 0);
        for (int u : topo) {
            for (auto &p : g[u]) {
                int v = p.first, w = p.second;
                ve[v] = max(ve[v], ve[u] + w);
            }
        }

        int project_time = 0;
        for (int i = 1; i <= n; i++)
            project_time = max(project_time, ve[i]);

        /* ---------- vl ---------- */
        vector<int> vl(n + 1, project_time);
        for (int i = n - 1; i >= 0; i--) {
            int u = topo[i];
            for (auto &p : g[u]) {
                int v = p.first, w = p.second;
                vl[u] = min(vl[u], vl[v] - w);
            }
        }

        /* ---------- 关键活动 ---------- */
        vector<pair<int,int>> critical;
        for (auto &ed : edges) {
            int u = ed.u, v = ed.v, w = ed.w;
            if (ve[u] == vl[v] - w)
                critical.push_back({u, v});
        }

        sort(critical.begin(), critical.end());

        /* ---------- 输出 ---------- */
        cout << project_time << "\n";
        for (auto &p : critical) {
            cout << p.first << "->" << p.second << "\n";
        }
    }
    return 0;
}
