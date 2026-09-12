#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* leftnode;
    node* rightnode;
    node(int val):val(val),leftnode(nullptr),rightnode(nullptr){}
};
node* build(vector<int> &s, int& cnt){  //cnt需要更改！！！
    if(cnt>=(int)s.size())return nullptr;
    int val=s[cnt++];
    if(val==0)return nullptr;
    else {
        node* temp=new node(val);
        temp->leftnode=build(s,cnt);
        temp->rightnode=build(s,cnt);
        return temp;
    }
}
void front(node* root){
    if(root==nullptr)return;
    else {
        cout<<root->val<<' ';
        front(root->leftnode);
        front(root->rightnode);
    }
}
void mid(node* root){
    if(root==nullptr)return;
    else {
        mid(root->leftnode);
        cout<<root->val<<' ';
        mid(root->rightnode);
        return;
    }
}
void back(node* root){
    if(root==nullptr)return;
    else {
        back(root->leftnode);
        back(root->rightnode);
        cout<<root->val<<' ';
        return;
    }
}

int main(){
    vector<int>tre;
    int x;
    while (cin >> x) tre.push_back(x);
    int cnt=0;
    node* root=build(tre,cnt);
    front(root);
    cout<<endl;
    mid(root);
    cout<<endl;
    back(root);
    return 0;
}