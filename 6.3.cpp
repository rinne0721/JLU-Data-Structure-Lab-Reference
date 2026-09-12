//6.C 图的深度优先遍历
#include<bits/stdc++.h>
#define maxn 20005
using namespace std;
int check[maxn];
vector<vector<int>>g(maxn);
bool cmp(int a, int b){
    return a<b;
}
void dfs(int x){
    if(check[x])return ;
    check[x]=1;
    cout<<x<<' ';
    for(auto& a:g[x]){
        dfs(a);

    }
    return ;
}
int main(){
    int n,e;
    cin>>n>>e;

    memset(check,0,sizeof(check));
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        sort(g[a].begin(),g[a].end(),cmp);
    }
    for(int i=0; i<n; i++){
        dfs(i);
    }
    return 0;
}