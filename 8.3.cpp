//8.C 网络布线
#include<bits/stdc++.h>
#define maxn 605
using namespace std;
int n,e;
struct edge{
    int to;
    int w;
    edge(int to1, int w1):to(to1), w(w1){
    }
};
struct cmp{
    bool operator()(edge a, edge b){
        return a.w>b.w;  //
    }
};
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<edge>>g(n+1);
    edge minedge=edge(n+1,0x3f3f3f3f);
    for(int i=0;i<n;i++){
        int quan;
        cin>>quan;
        g[n].push_back(edge(i,quan));
    }

    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(edge(b,c));
        g[b].push_back(edge(a,c));
    }

    vector<bool> in(n+1, false);
    priority_queue<edge,vector<edge>,cmp>pq;
    vector<int> dist(n+1, INT_MAX);
    dist[n] = 0;
    pq.push(edge(n,0));
    int cnt=0;
    int total =0;
    while(!pq.empty()&&cnt<n+1){
        edge cur=pq.top();
        pq.pop();
        int u=cur.to;
        int v=cur.w;
        if(in[u])continue;
        in[u]=1;
        total+=v;
        cnt++;
        for(auto &e : g[u]){
            if(!in[e.to] && e.w < dist[e.to]){
                dist[e.to] = e.w;
                pq.push(edge(e.to, e.w));
            }
        }
    }
    cout<<total;
    return 0;

}
