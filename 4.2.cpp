//4.B 二叉树和等于某值路径
#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* leftnode;
    node* rightnode;
    node(int v) : val(v), leftnode(nullptr), rightnode(nullptr) {}
};
node* buildtree(vector<int>& s,int& cnt){
    if(cnt>=(int)s.size())return nullptr;
    int val=s[cnt++];
    if(val==0)return nullptr;
    node* root=new node(val);
    root->leftnode=buildtree(s,cnt);
    root->rightnode=buildtree(s,cnt);
    return root;
}
vector<int>p;
vector<vector<int>>result;
void find(node* root, int sum){  //回溯法！！！！！！！！！！！！！！！
    if(!root)return;
    sum-=root->val;
    p.push_back(root->val);
    if(!root->leftnode&&!root->rightnode&&sum==0){
        result.push_back(p);
    }
    else{
        find(root->leftnode,sum);
        find(root->rightnode,sum);
    }
    p.pop_back();
}
int main(){
    vector<int>s;
    int num;
    string line;
    getline(cin,line);
    stringstream ss(line);
    while(ss>>num)s.push_back(num);
    int cnt=0;
    node* root=buildtree(s,cnt);
    int sum;
    cin>>sum;
    find(root,sum);
    int len=(int)result.size();
    cout<<len<<endl;
    for(int i=0;i<len;i++){
        for(auto& a:result[i]){
            cout<<a<<' ';
        }
        cout<<endl;
    }
    return 0;
}