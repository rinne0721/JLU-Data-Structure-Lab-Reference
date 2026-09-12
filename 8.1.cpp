#include<bits/stdc++.h>
#define inf 100005
using namespace std;
int main(){
    int n,e;
    while(cin>>n>>e){
        vector<vector<int>>dist(n,vector<int>(n,inf));
        for(int i=0;i<n;i++)dist[i][i]=0;
        while(e--){
            int a, b, c;
            cin>>a>>b>>c;
            dist[a][b]=min(dist[a][b],c);
            dist[b][a]=min(dist[b][a],c);
        }
        for(int i=0; i<n; i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        vector<int>sum(n,0);
        int best=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum[i]+=dist[i][j];
            }
            if(sum[i]<sum[best])best=i;
        }
        cout<<best<<endl;
    }
    return 0;
}