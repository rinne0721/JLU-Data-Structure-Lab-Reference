//4.A ¶þ²æÊ÷É¾³ý×ÓÊ÷
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
void mid(node* root){
    if(root==nullptr)return;
    else{
        mid(root->leftnode);
        cout<<root->data<<' ';
        mid(root->rightnode);

        return;

    }
}
void delete1(int num, node* root,int& check){
    if(root==nullptr)return;
    else if(root->data==num){
        node* cnt=root->father;
        if(cnt->leftnode==root)cnt->leftnode=nullptr;
        else cnt->rightnode=nullptr;
        check=1;
        return;
    }
    else{
        delete1(num, root->leftnode, check);
        delete1(num, root->rightnode, check);
    }
    return;
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
    int num1;
    cin>>num1;
    for(int i=0;i<num1;i++){
        int check =0 ;
        int num;
        cin>>num;
        delete1(num, root, check);
        if(check==0)cout<<0<<endl;
        else {
            mid(root);
            cout<<endl;
        }

    }
    return 0;
}