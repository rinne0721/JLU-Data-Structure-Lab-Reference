//7.A 任务排序
#include<bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(int a, int b){
        return a>b;  //用于优先队列比较的仿函数，数越小位于队列越顶部
    }
};
int main(){
    int n,e;
    cin>>n>>e;
    int in[n];//表示每个点的入度
    memset(in,0,sizeof(n));
    vector<vector<int>>g(n); //邻接表
    vector<int>result;
    for(int i=0;i<e;i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        in[b]++;
    }
    priority_queue<int,vector<int>,cmp>p;
    for(int i=0;i<n;i++){
        if(in[i]==0)p.push(i);
    }
    while(!p.empty()){
        int temp=p.top();
        p.pop();
        for(auto& a:g[temp]){
            in[a]--;
            if(in[a]==0)p.push(a);
        }
        result.push_back(temp);

    }
    if((int)result.size()!=n)cout<<"unworkable project";
    else{
        for(auto& a:result)cout<<a<<' ';

    }
    return 0;

}
