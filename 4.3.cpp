//4.C ab间路径
#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* leftnode;
    node* rightnode;
    node(int val1):val(val1),leftnode(NULL),rightnode(NULL){
    }
};
node* buildtree(vector<int>s, int &cnt){
    if(cnt>=(int)s.size())return NULL;
    int temp=s[cnt++];
    if(temp==0)return NULL;
    node* root= new node(temp);
    root->leftnode=buildtree(s,cnt);
    root->rightnode=buildtree(s,cnt);
    return root;
}
bool findpath(node* root, vector<int>& s,int des){   //回溯法，核心！！！
    if(!root)return false;
    s.push_back(root->val);
    if(root->val==des)return true;
    if(findpath(root->leftnode,s,des))return true;
    if(findpath(root->rightnode,s,des))return true;
    s.pop_back();
    return false;
}
void bind(node* root, int a, int b,vector<int>&result){
    vector<int>apath,bpath;
    findpath(root, apath, a);
    findpath(root, bpath, b);
    int i=0;
    while(i<(int)apath.size()&&i<(int)bpath.size()&&apath[i]==bpath[i])i++;
    int newroot=apath[i-1];
    for(int j=(int)apath.size()-1;j>=i;j--)result.push_back(apath[j]);
    result.push_back(newroot);
    for(int j=i;j<(int)bpath.size();j++)result.push_back(bpath[j]);
    return;
}
int main(){
    string line;
    vector<int>s;
    getline(cin,line);
    stringstream ss(line);
    int x;
    while(ss>>x)s.push_back(x);
    int cnt=0;
    int sum;
    node* root= buildtree(s,cnt);
    cin>>sum;
    vector<int>result;
    while(sum--){
        int a,b;
        cin>>a>>b;
        bind(root,a,b,result);
        cout<<(int)result.size()-1<<endl;
        for(int i=0;i<(int)result.size();i++)cout<<result[i]<<' ';
        cout<<endl;
        result.clear();
    }
    return 0;
}