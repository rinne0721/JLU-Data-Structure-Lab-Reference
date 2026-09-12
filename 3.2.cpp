//3.B 二叉树查找节点与父节点
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* rightnode;
    node* leftnode;
    node* father;
    node(int val):data(val),rightnode(nullptr),leftnode(nullptr),father(nullptr){}
};
node* bulidtree(vector<int>& s,int& cnt,node* father=nullptr){
    if(cnt>=(int)s.size())return nullptr;
    int val=s[cnt++];
    if(val==0)return nullptr;
    node* root=new node(val);
    root->father=father;
    root->leftnode=bulidtree(s,cnt,root);
    root->rightnode=bulidtree(s,cnt,root);
    return root;
}
bool dfs(int val,node* root){
    if(root==nullptr)return false;
    else if(root->data==val){
        if(!root->father)cout<<'0'<<endl;
        else{
            cout<<root->father->data<<endl;
        }
        return true;
    }
    return dfs(val,root->leftnode)||dfs(val,root->rightnode);
}

int main(){
    vector<int>tre;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    while (ss >> x) tre.push_back(x);
    int cnt=0;
    node* root=bulidtree(tre,cnt);
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int n;
        cin>>n;
        if(!dfs(n,root))cout<<'0'<<endl;
    }
    return 0;
}