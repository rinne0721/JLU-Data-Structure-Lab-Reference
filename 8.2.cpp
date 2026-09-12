//8.B È¥»ð³µÕ¾
#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

vector<long long> dijkstra(int n, int src,
                           vector<vector<pair<int,int>>> &g) {

    vector<long long> dist(n+1, INF);
    priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v,w] : g[u]){
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,s,t;
    while(cin >> n >> s >> t){

        int m;
        cin >> m;
        vector<vector<pair<int,int>>> bus(n+1);

        for(int i=0;i<m;i++){
            int a,b,c;
            cin >> a >> b >> c;
            bus[a].push_back({b,c});
            bus[b].push_back({a,c});
        }

        int k;
        cin >> k;
        vector<tuple<int,int,int>> metro(k);
        for(int i=0;i<k;i++){
            cin >> get<0>(metro[i])
                >> get<1>(metro[i])
                >> get<2>(metro[i]);
        }

        auto distS = dijkstra(n, s, bus);
        auto distT = dijkstra(n, t, bus);

        long long best = distS[t];
        int bestK = -1;

        for(auto [x,y,z] : metro){
            if(distS[x] + z + distT[y] < best){
                best = distS[x] + z + distT[y];
                bestK = x;
            }
            if(distS[y] + z + distT[x] < best){
                best = distS[y] + z + distT[x];
                bestK = y;
            }
        }

        cout << best << "\n";
        if(bestK == -1) cout << "no metro\n";
        else cout << bestK << "\n";
    }
}
