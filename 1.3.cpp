//1.C 使用栈非递归求解汉诺塔问题
#include<bits/stdc++.h>
using namespace std;
struct hanoi{
    int n;
    char a;
    char b;
    char c;
    hanoi(int n1, char a1, char b1, char c1):n(n1),a(a1),b(b1),c(c1){}
};
stack<hanoi>s;
long long op(int m) {
    long long maxsize=0;
    s.push({m, 'a', 'b', 'c'});
    while(!s.empty()){
         if(s.size()>maxsize)maxsize=s.size();
         hanoi temp=s.top();
         s.pop();
         if(temp.n==1){
             printf("Move disk from ");
             printf("%c",temp.a);
             printf(" to ");
             printf("%c\n",temp.c);
         }else{
             s.push({temp.n-1,temp.b,temp.a,temp.c});
             s.push({1,temp.a,temp.b,temp.c});
             s.push({temp.n-1,temp.a,temp.c,temp.b});
         }
    }
    return maxsize;
}
int main(){
    int n;
    cin>>n;
    long long max=op(n);
    printf("%lld",max);
    return 0;
}