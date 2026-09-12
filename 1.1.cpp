//1.A 括号匹配（进阶版）
#include<bits/stdc++.h>
using namespace std;
map<char, int> m = {
        {'<', 1}, {'(', 2}, {'[', 3}, {'{', 4},
        {'>', 5}, {')', 6}, {']', 7}, {'}', 8}
};
stack<int>s;
void check(string& p){
    for(char c:p){
        if(c=='<'|| c=='(' || c=='[' || c== '{'){
            if(!s.empty()){
                s.push(m[c]);
            }else{
                if(m[c]>=s.top()){
                    cout<<"Fail"<<endl;
                    return;
                }else{
                    s.push(m[c]);
                }
            }
        }else if(c=='>' || c==')' || c==']' || c== '}'){
            if(!s.empty()){
                cout<<"Fail"<<endl;
                return;
            }
            if(m[c]==4+s.top()){
                s.pop();
            }else{
                cout<<"Fail"<<endl;
                return;
            }
        }
    }
    if(!s.empty()){
        cout<<"Match"<<endl;
        return;
    }
    else{
        cout<<"Fail"<<endl;
        return;
    }
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        string p;
        getline(cin,p);
        check(p);
    }
    return 0;
}