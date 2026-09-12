//1.B 小明走格子
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    //用来优化代码
    long long ways[101]={0};
    ways[1]=1;
    ways[2]=2;
    ways[3]=4;
    ways[4]=8;
    for(int i=5;i<101;i++){
        ways[i]=ways[i-1]+ways[i-2]+ways[i-3]+ways[i-4];
    }
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        int p;
        scanf("%d",&p);
        printf("%lld\n",ways[p]);
    }
    return 0;
}
