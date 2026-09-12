#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
struct Node {
    int x, y;
};
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};


int main(){
    int m,n,t;
    while(cin>>m>>n>>t) {
        int dist[maxn][maxn];
        int maps[maxn][maxn];
        int sx,sy,tx,ty; //起始点坐标
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> maps[i][j];
                dist[i][j]=-1;
                if(maps[i][j]==3){
                    sx=i;
                    sy=j;
                }
                else if(maps[i][j]==4){
                    tx=i;
                    ty=j;
                }
            }
        }
        if(sx==tx&&sy==ty){
            cout<<'0'<<endl;
            continue;
        }
        deque<Node>solve;
        solve.push_back({sx,sy});
        dist[sx][sy]=0;
        bool check= false;
        int curx,cury;
        while(!solve.empty()&&!check){
            Node cur = solve.front();
            solve.pop_front();
            for(int i=0; i<4; i++){
                curx=cur.x+dx[i];
                cury=cur.y+dy[i];
                if(curx>0&& curx<=m && cury>0 && cury<=n && dist[curx][cury]==-1 && maps[curx][cury]!=1){
                    if(curx==tx&&cury==ty){
                        check= true;
                        cout<<dist[cur.x][cur.y]+2-t<<endl;
                        break;
                    }
                    solve.push_back({curx,cury});
                    dist[curx][cury]=dist[cur.x][cur.y]+1;

                }
            }


        }
        if(!check)cout<<"can not save"<<endl;
    }
    return 0;
}