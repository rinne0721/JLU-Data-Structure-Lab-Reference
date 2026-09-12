//6.A 图的创建
#include<bits/stdc++.h>
using namespace std;
struct edge{
    int to ;
    int weight;
    edge(int to1 , int weight1):to(to1),weight(weight1){}
};
bool cmp(edge a, edge b){
    return a.to<b.to;
}
int main(){
    int n,e ;
    cin>>n>>e;
    vector<vector<edge>>g(n);
    for(int i=0;i<e;i++){
        int s,t,w;
        cin>>s>>t>>w;
        g[s].push_back(edge(t,w));

    }
    for(int i = 0; i < n; i++){
        if(g[i].empty())continue;
        sort(g[i].begin(),g[i].end(),cmp);
        cout<<i<<':';
        for(auto j:g[i]){
            cout <<"(" <<i <<"," <<j.to <<"," <<j.weight <<")";
        }
        cout <<endl;
    }
    return 0;
}