//2.A 表达式求值
#include<bits/stdc++.h>
using namespace std;
long long pwr(long long a, long long b){
    long long res=1;
    if(b==0)return res;
    while(b>0){
        if(b&1)res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

int pri(char c) {
    if (c == '+' || c  == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}
bool calc(stack<long long>& num,stack<char>& opt){
    if (num.size() < 2 || opt.empty()) return false;
    long long a=num.top();num.pop();
    long long b=num.top();num.pop();
    char c=opt.top();opt.pop();
    if(c=='*') num.push(a*b);
    else if(c=='+')num.push(a+b);
    else if(c=='-')num.push(b-a);
    else if(c=='/'){
        if(a==0)return false;
        else num.push(b/a);
    }
    else if(c=='^')num.push(pwr(b,a));
    return true;
}
int main(){

    string s;

    while(getline(cin,s)) {
        stack<long long>num;
        stack<char>opt;
        int check=1;
        for(int i=0;i<(int)s.size();){
            if(s[i]==' '){
                i++;
                continue;
            }
            else if(isdigit(s[i])){
                long long cnt=0;
                while(i<(int)s.size()&&isdigit(s[i])){
                    cnt=cnt*10+(s[i]-'0');
                    i++;
                }
                num.push(cnt);
            }
            else if(s[i]=='('){opt.push(s[i]);i++;}
            else if(s[i]==')'){
                while(!opt.empty()&&opt.top()!='('){
                    if(!calc(num,opt)){
                        check=0;
                        break;
                    }
                }
                if(!opt.empty() && opt.top()=='(') opt.pop();
                i++;

            }
            else{
                char c=s[i++];
                while(!opt.empty()&&pri(opt.top())>=pri(c)){
                    if(!calc(num,opt)){check=0;break;}
                }
                if(check==0)break;
                opt.push(c);
            }
        }
        while(check&&!opt.empty()){
            if(!calc(num,opt)){check=0;break;
            }
        }
        if(check==0||num.size()!=1)cout<<"INVALID"<<endl;
        else cout<<num.top()<<endl;
    }

    return 0;
}