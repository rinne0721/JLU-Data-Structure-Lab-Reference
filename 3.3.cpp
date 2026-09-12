//3.C 重建二叉树
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node* left;
    Node* right;
    Node(char v) : val(v), left(nullptr), right(nullptr) {}
};
Node* build(int pl, int pr, int il, int ir,bool& valid, string& post, string& in){
    //pl,pr:子树在后序遍历字符串中的起止位置
    //il,ir:子树在中序遍历字符串中的起止位置
    if (pl > pr || il > ir) return nullptr; //左或右子树为空的时候触发此终止条件
    char c=post[pr];
    int cntl=in.find(c,il);//从il位置开始寻找中序遍历序列中的c字符(子树的根节点)
    if(cntl==string::npos || cntl>ir){
        valid=false;
        return nullptr;
    }else{
        int size=cntl-il;
        Node* root=new Node(c);
        root->left=build(pl,pl+size-1,il,cntl-1,valid,post,in);
        root->right=build(pl+size,pr-1,cntl+1,ir,valid,post,in);
        return root;
    }

}
int height(Node* root){
    if(root==nullptr)return 0;
    return max(height(root->left),height(root->right))+1;
}
void preorder(Node* root) {
    if (!root) return;
    cout<<root->val;
    preorder(root->left);
    preorder(root->right);
}
int main(){
    string post;
    string in;
    while(cin>>post>>in){
        bool valid=true;
        Node* root=build(0,post.size()-1,0,in.size()-1,valid,post,in);

        if(!valid){
            cout<<"INVALID"<<endl;
            continue;
        }
        cout<<height(root)-1<<endl;
        preorder(root);
        cout<<endl;
    }
    return 0;
}