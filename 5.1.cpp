#include<bits/stdc++.h>
#define maxn 30005
using namespace std;
int parent[30005];
int find(int n){
    int cur = n;
    while(parent[cur]!=cur)cur=parent[cur];
    int cur1=n;
    while(cur1!=cur){
        parent[cur1]=cur;
        cur1=parent[cur1];
    }
    return cur;
}
int bind(int a, int b ){
    int a1=find(a);
    int b1=find(b);
    if(a1!=b1){
        parent[a1]=b1;
        find(a);
    }
    return b1;
}
int main(){
    int num;
    cin>>num;
    while(num--){
        int n,m;
        cin>>n>>m; //分别代表珍珠个数与操作数
        for(int i=1;i<n+1;i++)parent[i]=i;
        while(m--){
            int a,b;
            cin>>a>>b;
            bind(a,b);
        }
        for(int i=1; i<n+1; i++){
            cout<<find(i)<<' ';
        }
        cout<<endl;

    }
    return 0;
}