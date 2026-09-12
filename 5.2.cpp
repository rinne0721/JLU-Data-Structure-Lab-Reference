#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node* leftnode;
    node* rightnode;
    int dep;
    node(char data1):data(data1),leftnode(nullptr),rightnode(nullptr){}
};
node* buildtree(string s, int& cnt,int depth){
    if(cnt>=(int)s.size())return nullptr;
    char temp=s[cnt++];
    if(temp=='#')return nullptr;
    node* root= new node(temp);
    root->dep=depth;
    root->leftnode=buildtree(s,cnt,depth+1);
    root->rightnode=buildtree(s,cnt,depth+1);
    return root;
}
int getdep(node* root){
    if(root==nullptr)return 0;
    return max(getdep(root->leftnode)+1,getdep(root->rightnode)+1);
}
int main(){
    string s;
    getline(cin,s);
    int cnt=0;
    node* root= buildtree(s,cnt,0);
    int de=getdep(root);
    int count[de];
    memset(count,0,sizeof(count));
    queue<node*>bfs;
    bfs.push(root);
    while(!bfs.empty()){
        node*temp= bfs.front();
        bfs.pop();
        if((!temp->leftnode&&temp->rightnode)||(!temp->rightnode&&temp->leftnode))count[temp->dep]++;
        if(temp->leftnode)bfs.push(temp->leftnode);
        if(temp->rightnode)bfs.push(temp->rightnode);
    }
    for(int i=0;i<de;i++)cout<<count[i]<<endl;
    return 0;
}