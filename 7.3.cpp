//7.C 最少点字典序最短路径
#include <bits/stdc++.h>
using namespace std;
#define maxn 20005
int m,n;
vector<pair<int,int>>edge[maxn];
int des[maxn];
bool used[maxn];
vector<int> path[maxn];
void dij(int n) { //m代表元素个数
    for (int i = 0; i < n; i++) des[i] = 200000000;
    memset(used, 0, sizeof(used));
    des[0] = 0;
    path[0] = {0};

    for(int i=0;i<n;i++){
        int temp=-1;
        for(int j=0;j<n;j++){
            if(!used[j] && (temp==-1 || des[j] < des[temp])){  //每次使用未在已使用集合中的最小des节点
                temp = j;
            }
        }
        if(temp == -1) break;

        used[temp]=1;
        for(auto& e:edge[temp]){
            int to=e.first;
            int val=e.second;
            int des1=des[temp]+val;
            if(des1<des[to]){
                des[to]=des1;
                path[to]=path[temp];
                path[to].push_back(to);
            }else if(des1==des[to]){
                if(path[to].size()>path[temp].size()+1){
                    des[to]=des1;
                    path[to]=path[temp];
                    path[to].push_back(to);
                }else if(path[to].size()==path[temp].size()+1){
                    vector<int>newpath=path[temp];
                    newpath.push_back(to);
                    if(newpath < path[to]){
                        path[to] = newpath;
                    }
                }
            }
        }

    }
    for(int i=1;i<n;i++){
        if(des[i] < 200000000){
            for(int k=0;k<path[i].size();k++){
                if(k) cout<<"->";
                cout<<path[i][k];
            }
            cout<<"\n";
        }
    }

}
int main() {
    cin >>n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
    }

    dij(n);
    return 0;
}